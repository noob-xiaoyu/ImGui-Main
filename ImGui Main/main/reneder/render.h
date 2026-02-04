#pragma once
#include <iostream>
#include <Windows.h>
#include "imgui.h"
#include <imgui_internal.h>

struct BlurData {
    float x, y, w, h;
    float strength;
    float alpha;
};

extern void BlurCallback(const ImDrawList* parent_list, const ImDrawCmd* cmd);
inline void BlurCallback(const ImDrawList* parent_list, const ImDrawCmd* cmd) {
    BlurData* data = (BlurData*)cmd->UserCallbackData;
    if (data) {
        ImGui::MemFree(data);
    }
}

struct Color {
    int r, g, b, a;
    Color(int r, int g, int b, int a = 255) : r(r), g(g), b(b), a(a) {}
};

namespace render{
    ImDrawList* get_drawlist() {
        return ImGui::GetForegroundDrawList();
    }
    void line(float x1, float y1, float x2, float y2, Color color, float thickness = 1.0f);
    void text(float x, float y, Color color, const char* content, bool centered = false);
    void rectangle(float x, float y, float w, float h, Color color, float rounding = 0.0f);
    void filled_rectangle(float x, float y, float w, float h, Color color, float rounding = 0.0f);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color);
    void triangle_outline(float x1, float y1, float x2, float y2, float x3, float y3, Color color, float thickness = 1.0f);
    void gradient(float x, float y, float w, float h, Color color1, Color color2, bool horizontal = false);
    void circle(float x, float y, Color color, float radius);
    void filled_circle(float x, float y, Color color, float radius, int segments = 0);
    void circle_outline(float x, float y, Color color, float radius, float start_deg, float percentage, float thickness);
    void outline_glow(float x, float y, float w, float h, Color color, int layers = 15);
    void blur(float x, float y, float w, float h, int a = 255, float strength = 1.0f);
    void blur_fake(float x, float y, int w, int h, int a = 255);
}
