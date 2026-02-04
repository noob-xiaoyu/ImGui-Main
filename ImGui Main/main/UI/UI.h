#pragma once
#include <iostream>
#include <Windows.h>
#include "imgui.h"
#include <string>

namespace UI{
    inline float Lerp(float a, float b, float t) { return a + (b - a) * t; }
    using ID = unsigned int;

    ID GetActiveID();
    struct Context{ID active_id = 0;ID hot_id = 0;};
    inline Context g_ctx;
    inline void SetActive(ID id){g_ctx.active_id = id;}
    inline void ClearActive(){g_ctx.active_id = 0;}
    inline bool IsActive(ID id){return g_ctx.active_id == id;}
	// Button 实现
    class Button{
    public:
        Button() = default;
        Button(ID id, const ImVec2& pos, const ImVec2& size);

        // 每帧调用
        bool Update();     // true = clicked

        void SetEnabled(bool enabled) { m_enabled = enabled; }

        bool Hovered() const { return m_hovered; }
        bool Pressed() const { return m_pressed; }
        bool Enabled() const { return m_enabled; }
        bool Active()  const { return GetActiveID() == m_id && m_hovered; }
        // setters
        
        void SetPos(const ImVec2& pos) { m_pos = pos; }
        void SetSize(const ImVec2& size) { m_size = size; }

    private:
        ID m_id;

        ImVec2 m_pos{};
        ImVec2 m_size{};

        bool m_hovered = false;
        bool m_pressed = false;
        bool m_enabled = true;
    };

    
	// InputText 实现
    class InputText
    {
    public:
        InputText() = default; // 默认构造函数
        InputText(ID id, ImVec2 pos, ImVec2 size);

        void SetEnabled(bool enabled);
        void SetText(const std::string& text);
        const std::string& GetText() const;

        bool Update(); // 返回 true = 本帧内容发生变化

        bool IsActive() const;
        bool IsCursorVisible() const; // 获取光标可见性
        bool IsHovered() const; // 获取悬停状态
        int GetCursorPosition() const; // 获取光标位置
        
        // 密码模式相关
        void SetPasswordMode(bool password);
        bool IsPasswordMode() const;
        void TogglePasswordVisible();
        bool IsPasswordVisible() const;

    private:
        ID m_id{ 0 };
        ImVec2 m_pos{ 0.0f, 0.0f };
        ImVec2 m_size{ 0.0f, 0.0f };

        bool m_enabled{ true };
        bool m_hovered{ false };
        bool m_active{ false };

        std::string m_text;
        int m_cursor{ 0 };
        float m_cursor_blink_timer{ 0.0f };
        bool m_cursor_visible{ true };
        
        // 密码模式
        bool m_password_mode{ false };
        bool m_password_visible{ false };
    };
}
