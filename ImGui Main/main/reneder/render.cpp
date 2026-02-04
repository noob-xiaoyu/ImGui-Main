#include "render.h"

namespace render{
    // 绘制线
    void line(float x1, float y1, float x2, float y2, Color color, float thickness) {
        get_drawlist()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(color.r, color.g, color.b, color.a), thickness);
    }
    // 绘制文本
    void text(float x, float y, Color color, const char* content, bool centered) {
        if (centered) {
            ImVec2 textSize = ImGui::CalcTextSize(content);
            x -= textSize.x / 2.0f;
        }
        get_drawlist()->AddText(ImVec2(x, y), IM_COL32(color.r, color.g, color.b, color.a), content);
    }
    // 绘制矩形
    void rectangle(float x, float y, float w, float h, Color color, float rounding) {
        get_drawlist()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), IM_COL32(color.r, color.g, color.b, color.a), rounding);
    }
    // 绘制填充矩形
    void filled_rectangle(float x, float y, float w, float h, Color color, float rounding) {
        get_drawlist()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), IM_COL32(color.r, color.g, color.b, color.a), rounding);
    }
    // 绘制填充三角形
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color) {
        get_drawlist()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), IM_COL32(color.r, color.g, color.b, color.a));
    }
    // 绘制三角形边框
    void triangle_outline(float x1, float y1, float x2, float y2, float x3, float y3, Color color, float thickness) {
        get_drawlist()->AddTriangle(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), IM_COL32(color.r, color.g, color.b, color.a), thickness);
    }
    // 绘制渐变矩形
    void gradient(float x, float y, float w, float h, Color color1, Color color2, bool horizontal) {
        ImU32 col1 = IM_COL32(color1.r, color1.g, color1.b, color1.a);
        ImU32 col2 = IM_COL32(color2.r, color2.g, color2.b, color2.a);
        
        if (horizontal) {
            get_drawlist()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), col1, col2, col2, col1);
        } else {
            get_drawlist()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), col1, col1, col2, col2);
        }
    }
    // 绘制圆
    void circle(float x, float y, Color color, float radius) {
        get_drawlist()->AddCircle(ImVec2(x, y), radius, IM_COL32(color.r, color.g, color.b, color.a));
    }
    // 绘制填充圆
    void filled_circle(float x, float y, Color color, float radius, int segments) {
        get_drawlist()->AddCircleFilled(ImVec2(x, y), radius, IM_COL32(color.r, color.g, color.b, color.a), segments);
    }
    // 绘制圆边框
    void circle_outline(float x, float y, Color color, float radius, float start_deg, float percentage, float thickness) {
        ImDrawList* draw_list = get_drawlist();
        float min = start_deg * (IM_PI / 180.0f);
        float max = (start_deg + 360.0f * percentage) * (IM_PI / 180.0f);
        draw_list->PathArcTo(ImVec2(x, y), radius, min, max);
        draw_list->PathStroke(IM_COL32(color.r, color.g, color.b, color.a), 0, thickness);
    }
    //Glow
    void outline_glow(float x, float y, float w, float h, Color color, int layers) {
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
        float radius = 8.0f;
        float step = 1.0f;

        for (int i = 0; i < layers; i++) {
            float factor = 1.0f - ((float)i / layers);
            int current_a = (int)(color.a * factor);
            if (current_a <= 5) continue;

            ImU32 current_color = IM_COL32(color.r, color.g, color.b, current_a);
            float expand = i * step;

            draw_list->AddRect(
                ImVec2(x - expand, y - expand),
                ImVec2(x + w + expand, y + h + expand),
                current_color,
                radius + expand,
                0,
                1.5f
            );
        }
    }
    // 绘制模糊矩形
    void blur(float x, float y, float w, float h, int a, float strength) {
        if (a <= 0 || w <= 0 || h <= 0) return;

        ImDrawList* draw_list = get_drawlist();
        BlurData* data = (BlurData*)ImGui::MemAlloc(sizeof(BlurData));
        if (!data) return;

        data->x = x;
        data->y = y;
        data->w = w;
        data->h = h;
        data->strength = strength;
        data->alpha = (float)a / 255.0f;

        draw_list->AddCallback(BlurCallback, data);
        draw_list->AddCallback(ImDrawCallback_ResetRenderState, nullptr);
    }
    // 绘制模糊矩形（模拟）
    void blur_fake(float x, float y, int w, int h, int a) {
        ImDrawList* draw_list = get_drawlist();
        draw_list->AddRectFilled(
            ImVec2(x, y),
            ImVec2(x + w, y + h),
            IM_COL32(20, 20, 20, a * 0.6)
        );

        draw_list->AddRect(
            ImVec2(x, y),
            ImVec2(x + w, y + h),
            IM_COL32(255, 255, 255, 30)
        );
    }
}
