#include "UI.h"

namespace UI
{
    ID GetActiveID() { return g_ctx.active_id; }
    
    static bool MouseInRect(const ImVec2& pos, const ImVec2& size){
        ImVec2 m = ImGui::GetIO().MousePos;
        return m.x >= pos.x && m.y >= pos.y && m.x <= pos.x + size.x && m.y <= pos.y + size.y;
    }

	// Button 实现
    Button::Button(ID id, const ImVec2& pos, const ImVec2& size) : m_id(id), m_pos(pos), m_size(size), m_hovered(false), m_pressed(false), m_enabled(true) {}

    bool Button::Update(){
        ImGuiIO& io = ImGui::GetIO();
        if (!m_enabled){
            if (GetActiveID() == m_id)
                ClearActive();

            m_hovered = false;
            m_pressed = false;
            return false;
        }

        m_hovered = MouseInRect(m_pos, m_size);
        m_pressed = (GetActiveID() == m_id) && io.MouseDown[0];

        if (m_hovered && io.MouseClicked[0]) {
            SetActive(m_id);
        }

        if (GetActiveID() == m_id && io.MouseReleased[0]){
            ClearActive();
            return m_hovered;
        }

        if (GetActiveID() != 0 && GetActiveID() != m_id) {
            m_hovered = false;
        }

        return false;
    }

	// InputText 实现
    bool InputText::IsActive() const
    {
        return UI::IsActive(m_id);
    }

    bool InputText::IsCursorVisible() const
    {
        return m_cursor_visible;
    }

    int InputText::GetCursorPosition() const
    {
        return m_cursor;
    }

    bool InputText::IsHovered() const
    {
        return m_hovered;
    }

    // 密码模式相关方法
    void InputText::SetPasswordMode(bool password)
    {
        m_password_mode = password;
    }

    bool InputText::IsPasswordMode() const
    {
        return m_password_mode;
    }

    void InputText::TogglePasswordVisible()
    {
        m_password_visible = !m_password_visible;
    }

    bool InputText::IsPasswordVisible() const
    {
        return m_password_visible;
    }

    InputText::InputText(ID id, ImVec2 pos, ImVec2 size) : m_id(id), m_pos(pos), m_size(size), m_enabled(true), m_hovered(false), m_active(false), m_cursor(0), m_cursor_blink_timer(0.0f), m_cursor_visible(true), m_password_mode(false), m_password_visible(false) {}

    void InputText::SetEnabled(bool enabled)
    {
        m_enabled = enabled;
    }

    void InputText::SetText(const std::string& text)
    {
        m_text = text;
        m_cursor = (int)m_text.size();
    }

    const std::string& InputText::GetText() const
    {
        return m_text;
    }

    bool InputText::Update()
    {
        if (!m_enabled)
            return false;

        ImGuiIO& io = ImGui::GetIO();
        bool changed = false;

        // 1️⃣ Hover 判断
        m_hovered = io.MousePos.x >= m_pos.x && io.MousePos.x <= m_pos.x + m_size.x &&
                    io.MousePos.y >= m_pos.y && io.MousePos.y <= m_pos.y + m_size.y;

        // 2️⃣ 鼠标点击 -> 获得焦点
        if (m_hovered && io.MouseClicked[0]) {
            SetActive(m_id);
            m_cursor = (int)m_text.size();
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }

        m_active = IsActive();

        if (!m_active) {
            m_cursor_visible = false;
            return false;
        }

        // 3️⃣ 光标闪烁
        m_cursor_blink_timer += io.DeltaTime;
        if (m_cursor_blink_timer >= 0.5f) {
            m_cursor_visible = !m_cursor_visible;
            m_cursor_blink_timer = 0.0f;
        }

        // 4️⃣ 字符输入
        for (int i = 0; i < io.InputQueueCharacters.Size; i++) {
            ImWchar c = io.InputQueueCharacters[i];
            if (c >= 32) {
                m_text.insert(m_text.begin() + m_cursor, (char)c);
                m_cursor++;
                changed = true;
                m_cursor_blink_timer = 0.0f;
                m_cursor_visible = true;
            }
        }

        // 5️⃣ 退格键
        if (ImGui::IsKeyPressed(ImGuiKey_Backspace) && m_cursor > 0) {
            m_text.erase(m_cursor - 1, 1);
            m_cursor--;
            changed = true;
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }

        // 6️⃣ Delete键
        if (ImGui::IsKeyPressed(ImGuiKey_Delete) && m_cursor < (int)m_text.size()) {
            m_text.erase(m_cursor, 1);
            changed = true;
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }

        // 7️⃣ 左右箭头键
        if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow) && m_cursor > 0) {
            m_cursor--;
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }
        if (ImGui::IsKeyPressed(ImGuiKey_RightArrow) && m_cursor < (int)m_text.size()) {
            m_cursor++;
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }

        // 8️⃣ Home/End键
        if (ImGui::IsKeyPressed(ImGuiKey_Home)) {
            m_cursor = 0;
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }
        if (ImGui::IsKeyPressed(ImGuiKey_End)) {
            m_cursor = (int)m_text.size();
            m_cursor_blink_timer = 0.0f;
            m_cursor_visible = true;
        }

        // 9️⃣ Ctrl+C复制
        if (ImGui::IsKeyPressed(ImGuiKey_C) && (io.KeyCtrl || io.KeySuper)) {
            if (OpenClipboard(nullptr)) {
                EmptyClipboard();
                HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, m_text.size() + 1);
                if (hMem) {
                    char* pMem = (char*)GlobalLock(hMem);
                    if (pMem) {
                        strcpy_s(pMem, m_text.size() + 1, m_text.c_str());
                        GlobalUnlock(hMem);
                        SetClipboardData(CF_TEXT, hMem);
                    }
                }
                CloseClipboard();
            }
        }

        // 🔟 Ctrl+V粘贴
        if (ImGui::IsKeyPressed(ImGuiKey_V) && (io.KeyCtrl || io.KeySuper)) {
            if (OpenClipboard(nullptr)) {
                HANDLE hData = GetClipboardData(CF_TEXT);
                if (hData) {
                    char* pData = (char*)GlobalLock(hData);
                    if (pData) {
                        std::string clipboard_text = pData;
                        m_text.insert(m_cursor, clipboard_text);
                        m_cursor += (int)clipboard_text.size();
                        changed = true;
                        m_cursor_blink_timer = 0.0f;
                        m_cursor_visible = true;
                        GlobalUnlock(hData);
                    }
                }
                CloseClipboard();
            }
        }

        // 1️⃣1️⃣ Escape/Enter
        if (ImGui::IsKeyPressed(ImGuiKey_Escape)) {
            ClearActive();
        }
        if (ImGui::IsKeyPressed(ImGuiKey_Enter)) {
            ClearActive();
        }

        return changed;
    }
}