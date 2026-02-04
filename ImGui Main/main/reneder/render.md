# 渲染函数 Wiki

## 目录
- [包含头文件](#包含头文件)
- [函数列表](#函数列表)
  - [line](#line)
  - [text](#text)
  - [rectangle](#rectangle)
  - [rectangle_line](#rectangle_line)
  - [triangle](#triangle)
  - [triangle_line](#triangle_line)
  - [gradient](#gradient)
  - [DrawGradientBar](#DrawGradientBar)
  - [circle](#circle)
  - [circle_line](#circle_line)
  - [circle_outline](#circle_outline)
  - [outline_glow](#outline_glow)
  - [blur](#blur)
  - [blur_fake](#blur_fake)
  - [render_loading_circle](#render_loading_circle)
  - [loading_text](#loading_text)
  - [button](#button)
  - [InputText](#InputText)
- [使用示例](#使用示例)

## 包含头文件
```cpp
#include "render.h"
```

## 函数列表

### 绘制线条
```cpp
line(x1, y1, x2, y2, Color, thickness);
```

### 绘制文本
```cpp
text(x, y, Color, content, centered);
```

### 绘制实心矩形
```cpp
rectangle(x, y, w, h, Color, rounding);
```

### 绘制空心矩形边框
```cpp
rectangle_line(x, y, w, h, Color, rounding, thickness);
```

### 绘制实心三角形
```cpp
triangle(x1, y1, x2, y2, x3, y3, Color);
```

### 绘制空心三角形边框
```cpp
triangle_line(x1, y1, x2, y2, x3, y3, Color, thickness);
```

### 绘制渐变矩形
```cpp
gradient(x, y, w, h, Color1, Color2, horizontal);
``` 

### 绘制多颜色渐变矩形
```cpp
void DrawGradientBar(ImDrawList* draw_list, float x, float y, float width, float height, const GradientStop* stops, int stopCount);
```

### 绘制实心圆
```cpp
circle(x, y, Color, radius, segments);
```

### 绘制空心圆边框
```cpp
circle_line(x, y, Color, radius, thickness);
```

### 绘制部分空心圆环
```cpp
circle_outline(x, y, Color, radius, start_deg, percentage, thickness);
```

### 绘制发光效果
```cpp
outline_glow(x, y, w, h, Color, layers);
```

### 绘制模糊效果
```cpp
blur(x, y, w, h, a, strength);
```

### 绘制假模糊效果
```cpp
blur_fake(x, y, w, h, a);
```

### 绘制加载圆圈
```cpp
render_loading_circle(cx, cy, radius, Color, draw_list);
```

### 绘制加载文本
```cpp
loading_text(x, y, Color, base);
```

### 绘制按钮
```cpp
button(id, text, x, y, w, h, Color, enabled);
```

### 绘制输入框
```cpp
InputText(id, label, x, y, w, h, Color, enabled, is_password);
```
## 函数详细介绍

### <a name="line"></a>line
**功能**：绘制线条

**参数**：
- `x1`：起点X坐标
- `y1`：起点Y坐标
- `x2`：终点X坐标
- `y2`：终点Y坐标
- `color`：线条颜色，使用`Color(r, g, b, a)`
- `thickness`：线条宽度，默认为1.0f

**示例**：
```cpp
// 绘制红色线条，线宽为2.0f
line(100, 100, 200, 200, Color(255, 0, 0), 2.0f);
```

### <a name="text"></a>text
**功能**：绘制文本

**参数**：
- `x`：文本X坐标
- `y`：文本Y坐标
- `color`：文本颜色，使用`Color(r, g, b, a)`
- `content`：文本内容
- `centered`：是否居中显示，默认为false

**示例**：
```cpp
// 绘制绿色文本（居中）
text(150, 150, Color(0, 255, 0), "Hello World", true);
```

### <a name="rectangle"></a>rectangle
**功能**：绘制实心矩形

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `color`：矩形颜色，使用`Color(r, g, b, a)`
- `rounding`：圆角半径，默认为0.0f

**示例**：
```cpp
// 绘制蓝色实心矩形
rectangle(300, 100, 100, 50, Color(0, 0, 255), 5.0f);
```

### <a name="rectangle_line"></a>rectangle_line
**功能**：绘制空心矩形边框

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `color`：矩形颜色，使用`Color(r, g, b, a)`
- `rounding`：圆角半径，默认为0.0f
- `thickness`：线条宽度，默认为1.0f

**示例**：
```cpp
// 绘制蓝色空心矩形边框
rectangle_line(300, 100, 100, 50, Color(0, 0, 255), 5.0f, 2.0f);
```

### <a name="triangle"></a>triangle
**功能**：绘制实心三角形

**参数**：
- `x1`：第一个顶点X坐标
- `y1`：第一个顶点Y坐标
- `x2`：第二个顶点X坐标
- `y2`：第二个顶点Y坐标
- `x3`：第三个顶点X坐标
- `y3`：第三个顶点Y坐标
- `color`：三角形颜色，使用`Color(r, g, b, a)`

**示例**：
```cpp
// 绘制紫色实心三角形
triangle(150, 200, 100, 250, 200, 250, Color(128, 0, 128));
```

### <a name="triangle_line"></a>triangle_line
**功能**：绘制空心三角形边框

**参数**：
- `x1`：第一个顶点X坐标
- `y1`：第一个顶点Y坐标
- `x2`：第二个顶点X坐标
- `y2`：第二个顶点Y坐标
- `x3`：第三个顶点X坐标
- `y3`：第三个顶点Y坐标
- `color`：三角形颜色，使用`Color(r, g, b, a)`
- `thickness`：线条宽度，默认为1.0f

**示例**：
```cpp
// 绘制橙色空心三角形边框
triangle_line(250, 200, 200, 250, 300, 250, Color(255, 165, 0), 2.0f);
```

### <a name="gradient"></a>gradient
**功能**：绘制渐变矩形

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `color1`：起始颜色，使用`Color(r, g, b, a)`
- `color2`：结束颜色，使用`Color(r, g, b, a)`
- `horizontal`：是否为水平渐变，默认为false（垂直渐变）

**示例**：
```cpp
// 绘制水平渐变矩形（从红色到蓝色）
gradient(350, 200, 150, 50, Color(255, 0, 0), Color(0, 0, 255), true);

// 绘制垂直渐变矩形（从绿色到黄色）
gradient(520, 200, 150, 50, Color(0, 255, 0), Color(255, 255, 0), false);
```

### <a name="DrawGradientBar"></a>DrawGradientBar
**功能**：绘制多颜色渐变矩形

**参数**：
- `draw_list`：ImDrawList指针，用于绘制
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `stops`：渐变颜色数组，每个元素为`GradientStop`结构体
- `stopCount`：渐变颜色数组元素数量

**示例**：
```cpp
// 定义渐变颜色停止点
GradientStop stops[] = {
    { IM_COL32(0, 185, 255, 255), 0.0f },
    { IM_COL32(255,   1, 247, 255), 0.5f },
    { IM_COL32(232, 255,   0, 255), 1.0f }
};

// 绘制渐变条
DrawGradientBar(ImGui::GetForegroundDrawList(), 100, 100, 300, 30, stops, IM_ARRAYSIZE(stops));
```

### <a name="circle"></a>circle
**功能**：绘制实心圆

**参数**：
- `x`：圆心X坐标
- `y`：圆心Y坐标
- `color`：圆的颜色，使用`Color(r, g, b, a)`
- `radius`：圆的半径
- `segments`：圆的分段数，默认为0（自动计算）

**示例**：
```cpp
// 绘制粉色实心圆
circle(150, 350, Color(255, 192, 203), 30);
```

### <a name="circle_line"></a>circle_line
**功能**：绘制空心圆边框

**参数**：
- `x`：圆心X坐标
- `y`：圆心Y坐标
- `color`：圆的颜色，使用`Color(r, g, b, a)`
- `radius`：圆的半径
- `thickness`：线条宽度，默认为1.0f

**示例**：
```cpp
// 绘制青色空心圆边框
circle_line(150, 350, Color(0, 255, 255), 30, 2.0f);
```

### <a name="circle_outline"></a>circle_outline
**功能**：绘制部分空心圆环

**参数**：
- `x`：圆心X坐标
- `y`：圆心Y坐标
- `color`：圆环的颜色，使用`Color(r, g, b, a)`
- `radius`：圆环的半径
- `start_deg`：起始角度（度）
- `percentage`：圆环的百分比（0.0-1.0）
- `thickness`：圆环的宽度

**示例**：
```cpp
// 绘制绿色空心圆环（从0度开始，绘制75%）
circle_outline(350, 350, Color(0, 255, 0), 30, 0, 0.75f, 2.0f);
```

### <a name="outline_glow"></a>outline_glow
**功能**：绘制发光效果

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `color`：发光颜色，使用`Color(r, g, b, a)`
- `layers`：发光层数，默认为15

**示例**：
```cpp
// 绘制金色发光效果
outline_glow(450, 320, 100, 60, Color(255, 215, 0), 10);
```

### <a name="blur"></a>blur
**功能**：绘制模糊效果（需要Shader实现）

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `a`：透明度，默认为255
- `strength`：模糊强度，默认为1.0f

**示例**：
```cpp
// 绘制预留的模糊效果（需要Shader实现）
blur(720, 320, 100, 60, 180, 1.0f);
```

### <a name="blur_fake"></a>blur_fake
**功能**：绘制假模糊效果（半透明背景+边框）

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `a`：透明度，默认为255

**示例**：
```cpp
// 绘制假模糊效果
blur_fake(600, 320, 100, 60, 180);
```

### <a name="render_loading_circle"></a>render_loading_circle
**功能**：绘制加载动画圆圈

**参数**：
- `cx`：圆心X坐标
- `cy`：圆心Y坐标
- `radius`：圆的半径
- `color`：圆圈颜色，使用`Color(r, g, b, a)`
- `draw_list`：ImDrawList指针，用于绘制

**特性**：
- 自动旋转动画
- 呼吸透明度效果
- 缓入缓出转速

**示例**：
```cpp
// 绘制加载圆圈
render_loading_circle(100, 100, 20.0f, Color(255, 255, 255), ImGui::GetForegroundDrawList());
```

### <a name="loading_text"></a>loading_text
**功能**：绘制加载动画文本

**参数**：
- `x`：文本X坐标
- `y`：文本Y坐标
- `color`：文本颜色，使用`Color(r, g, b, a)`
- `base`：基础文本内容

**特性**：
- 自动添加动态省略号（...）
- 呼吸透明度效果
- 自动绘制加载圆圈

**示例**：
```cpp
// 绘制加载文本
loading_text(100, 100, Color(255, 255, 255), "Loading");
```

### <a name="button"></a>button
**功能**：绘制交互式按钮

**参数**：
- `id`：按钮唯一标识符（UI::ID类型）
- `text`：按钮文本内容
- `x`：按钮左上角X坐标
- `y`：按钮左上角Y坐标
- `w`：按钮宽度
- `h`：按钮高度
- `color`：按钮背景颜色，使用`Color(r, g, b, a)`
- `enabled`：是否启用按钮，默认为true

**返回值**：
- `bool`：是否被点击

**特性**：
- 支持悬停高亮
- 支持按下状态
- 支持禁用状态
- 自动文本居中

**示例**：
```cpp
// 绘制按钮
if (button(1, "Click Me", 100, 100, 120, 40, Color(50, 50, 50))) {
    // 按钮被点击
}

// 绘制禁用按钮
button(2, "Disabled", 100, 150, 120, 40, Color(50, 50, 50), false);
```

### <a name="InputText"></a>InputText
**功能**：绘制交互式输入框

**参数**：
- `id`：输入框唯一标识符（UI::ID类型）
- `text`：输入框标签文本
- `x`：输入框左上角X坐标
- `y`：输入框左上角Y坐标
- `w`：输入框宽度
- `h`：输入框高度
- `color`：输入框背景颜色，使用`Color(r, g, b, a)`
- `enabled`：是否启用输入框，默认为true
- `is_password`：是否为密码模式，默认为false

**返回值**：
- `const std::string&`：输入框当前文本内容

**特性**：
- 支持文本输入和编辑
- 支持光标闪烁
- 支持密码模式（显示*号）
- 支持密码可见性切换
- 支持悬停和激活状态

**示例**：
```cpp
// 绘制普通输入框
const std::string& username = InputText(1, "Username:", 100, 100, 200, 30, Color(30, 30, 30));

// 绘制密码输入框
const std::string& password = InputText(2, "Password:", 100, 150, 200, 30, Color(30, 30, 30), true, true);

// 绘制禁用输入框
InputText(3, "Disabled:", 100, 200, 200, 30, Color(30, 30, 30), false);
```

## 使用示例

### 基础绘图示例

```cpp
void DrawListExample() {
    using namespace render;
    
    // 绘制红色线条
    line(100, 100, 200, 200, Color(255, 0, 0), 2.0f);
    
    // 绘制绿色文本（居中）
    text(150, 150, Color(0, 255, 0), "Hello World", true);
    
    // 绘制蓝色实心矩形
    rectangle(300, 100, 100, 50, Color(0, 0, 255));
    
    // 绘制黄色空心矩形边框（带圆角）
    rectangle_line(420, 100, 100, 50, Color(255, 255, 0), 5.0f, 2.0f);
    
    // 绘制紫色实心三角形
    triangle(150, 200, 100, 250, 200, 250, Color(128, 0, 128));
    
    // 绘制橙色空心三角形边框
    triangle_line(250, 200, 200, 250, 300, 250, Color(255, 165, 0), 2.0f);
    
    // 绘制水平渐变矩形（从红色到蓝色）
    gradient(350, 200, 150, 50, Color(255, 0, 0), Color(0, 0, 255), true);
    
    // 绘制垂直渐变矩形（从绿色到黄色）
    gradient(520, 200, 150, 50, Color(0, 255, 0), Color(255, 255, 0), false);
    
    // 绘制粉色实心圆
    circle(150, 350, Color(255, 192, 203), 30);
    
    // 绘制青色空心圆边框
    circle_line(250, 350, Color(0, 255, 255), 30, 2.0f);
    
    // 绘制绿色部分空心圆环（从0度开始，绘制75%）
    circle_outline(350, 350, Color(0, 255, 0), 30, 0, 0.75f, 2.0f);
    
    // 绘制发光效果
    outline_glow(450, 320, 100, 60, Color(255, 215, 0), 10);
    
    // 绘制假模糊效果
    blur_fake(600, 320, 100, 60, 180);
    
    // 绘制预留的模糊效果（需要Shader实现）
    blur(720, 320, 100, 60, 180, 1.0f);
}
```

### 渐变条示例

```cpp
void DrawGradientBarExample() {
    using namespace render;
    
    // 定义渐变颜色停止点
    GradientStop stops[] = {
        { IM_COL32(0, 185, 255, 255), 0.0f },
        { IM_COL32(255,   1, 247, 255), 0.5f },
        { IM_COL32(232, 255,   0, 255), 1.0f }
    };
    
    // 绘制渐变条
    DrawGradientBar(ImGui::GetForegroundDrawList(), 100, 100, 300, 30, stops, IM_ARRAYSIZE(stops));
}
```

### 加载动画示例

```cpp
void LoadingAnimationExample() {
    using namespace render;
    
    // 绘制加载圆圈
    render_loading_circle(100, 100, 20.0f, Color(255, 255, 255), ImGui::GetForegroundDrawList());
    
    // 绘制加载文本（会自动绘制加载圆圈）
    loading_text(100, 150, Color(255, 255, 255), "Loading");
}
```

### 交互式控件示例

```cpp
void InteractiveControlsExample() {
    using namespace render;
    static UI::ID button_id = 1;
    static UI::ID username_id = 2;
    static UI::ID password_id = 3;
    
    // 绘制按钮
    if (button(button_id++, "Click Me", 100, 100, 120, 40, Color(50, 50, 50))) {
        // 按钮被点击
    }
    
    // 绘制禁用按钮
    button(button_id++, "Disabled", 100, 150, 120, 40, Color(50, 50, 50), false);
    
    // 绘制普通输入框
    const std::string& username = InputText(username_id++, "Username:", 100, 200, 200, 30, Color(30, 30, 30));
    
    // 绘制密码输入框
    const std::string& password = InputText(password_id++, "Password:", 100, 250, 200, 30, Color(30, 30, 30), true, true);
    
    // 绘制禁用输入框
    InputText(4, "Disabled:", 100, 300, 200, 30, Color(30, 30, 30), false);
}
```

### 综合示例

```cpp
void ComprehensiveExample() {
    using namespace render;
    static UI::ID next_id = 1;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 50, Color(255, 255, 255), "Render Library Demo", true);
    
    // 绘制装饰性元素
    gradient(100, 100, 200, 100, Color(0, 185, 255), Color(255, 1, 247), true);
    circle_outline(200, 150, Color(255, 255, 255), 40, 0, 0.75f, 2.0f);
    
    // 绘制按钮
    if (button(next_id++, "Start", 100, 250, 100, 40, Color(0, 185, 255))) {
        // 开始按钮被点击
    }
    
    if (button(next_id++, "Settings", 220, 250, 100, 40, Color(100, 100, 100))) {
        // 设置按钮被点击
    }
    
    // 绘制输入框
    const std::string& input = InputText(next_id++, "Input:", 100, 320, 220, 30, Color(30, 30, 30));
    
    // 绘制加载状态
    loading_text(100, 400, Color(255, 255, 255), "Processing");
    
    // 绘制发光效果
    outline_glow(100, 500, 200, 60, Color(0, 185, 255), 10);
    text(200, 530, Color(255, 255, 255), "Glow Effect", true);
    
    // 绘制模糊效果
    blur_fake(350, 500, 200, 60, 180);
    text(450, 530, Color(255, 255, 255), "Blur Effect", true);
}
```

