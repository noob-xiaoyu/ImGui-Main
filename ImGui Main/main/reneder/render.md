# 渲染函数 Wiki

## 目录
- [包含头文件](#包含头文件)
- [函数列表](#函数列表)
  - [line](#line)
  - [text](#text)
  - [rectangle](#rectangle)
  - [filled_rectangle](#filled_rectangle)
  - [triangle](#triangle)
  - [triangle_outline](#triangle_outline)
  - [gradient](#gradient)
  - [circle](#circle)
  - [filled_circle](#filled_circle)
  - [circle_outline](#circle_outline)
  - [outline_glow](#outline_glow)
  - [blur](#blur)
  - [blur_fake](#blur_fake)
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

### 绘制空心矩形
```cpp
rectangle(x, y, w, h, Color, rounding);
```

### 绘制实心矩形
```cpp
filled_rectangle(x, y, w, h, Color, rounding);
```

### 绘制实心三角形
```cpp
triangle(x1, y1, x2, y2, x3, y3, Color);
```

### 绘制空心三角形
```cpp
triangle_outline(x1, y1, x2, y2, x3, y3, Color, thickness);
```

### 绘制渐变矩形
```cpp
gradient(x, y, w, h, Color1, Color2, horizontal);
```

### 绘制空心圆
```cpp
circle(x, y, radius, Color, thickness);
```

### 绘制实心圆
```cpp
filled_circle(x, y, radius, Color);
```

### 绘制空心圆环
```cpp
circle_outline(x, y, radius, Color, thickness);
```

### 绘制发光效果
```cpp
outline_glow(x, y, w, h, Color, glow_size);
```

### 绘制模糊效果
```cpp
blur(x, y, w, h, blur_size);
```

### 绘制假模糊效果
```cpp
blur_fake(x, y, w, h, blur_size);
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
**功能**：绘制空心矩形

**参数**：
- `x`：矩形左上角X坐标
- `y`：矩形左上角Y坐标
- `w`：矩形宽度
- `h`：矩形高度
- `color`：矩形颜色，使用`Color(r, g, b, a)`
- `rounding`：圆角半径，默认为0.0f

**示例**：
```cpp
// 绘制蓝色空心矩形
rectangle(300, 100, 100, 50, Color(0, 0, 255), 5.0f);
```

### <a name="filled_rectangle"></a>filled_rectangle
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
// 绘制黄色实心矩形（带圆角）
filled_rectangle(420, 100, 100, 50, Color(255, 255, 0), 5.0f);
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

### <a name="triangle_outline"></a>triangle_outline
**功能**：绘制空心三角形

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
// 绘制橙色空心三角形
triangle_outline(250, 200, 200, 250, 300, 250, Color(255, 165, 0), 2.0f);
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

### <a name="circle"></a>circle
**功能**：绘制空心圆

**参数**：
- `x`：圆心X坐标
- `y`：圆心Y坐标
- `color`：圆的颜色，使用`Color(r, g, b, a)`
- `radius`：圆的半径

**示例**：
```cpp
// 绘制青色空心圆
circle(150, 350, Color(0, 255, 255), 30);
```

### <a name="filled_circle"></a>filled_circle
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
filled_circle(250, 350, Color(255, 192, 203), 30);
```

### <a name="circle_outline"></a>circle_outline
**功能**：绘制空心圆环

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

## 使用示例

```cpp
void DrawListExample() {
    using namespace render;
    // 绘制红色线条
    line(100, 100, 200, 200, Color(255, 0, 0), 2.0f);
    
    // 绘制绿色文本（居中）
    text(150, 150, Color(0, 255, 0), "Hello World", true);
    
    // 绘制蓝色空心矩形
    rectangle(300, 100, 100, 50, Color(0, 0, 255));
    
    // 绘制黄色实心矩形（带圆角）
    filled_rectangle(420, 100, 100, 50, Color(255, 255, 0), 5.0f);
    
    // 绘制紫色实心三角形
    triangle(150, 200, 100, 250, 200, 250, Color(128, 0, 128));
    
    // 绘制橙色空心三角形
    triangle_outline(250, 200, 200, 250, 300, 250, Color(255, 165, 0), 2.0f);
    
    // 绘制水平渐变矩形（从红色到蓝色）
    gradient(350, 200, 150, 50, Color(255, 0, 0), Color(0, 0, 255), true);
    
    // 绘制垂直渐变矩形（从绿色到黄色）
    gradient(520, 200, 150, 50, Color(0, 255, 0), Color(255, 255, 0), false);
    
    // 绘制青色空心圆
    circle(150, 350, Color(0, 255, 255), 30);
    
    // 绘制粉色实心圆
    filled_circle(250, 350, Color(255, 192, 203), 30);
    
    // 绘制绿色空心圆环（从0度开始，绘制75%）
    circle_outline(350, 350, Color(0, 255, 0), 30, 0, 0.75f, 2.0f);
    
    // 绘制发光效果
    outline_glow(450, 320, 100, 60, Color(255, 215, 0), 10);
    
    // 绘制假模糊效果
    blur_fake(600, 320, 100, 60, 180);
    
    // 绘制预留的模糊效果（需要Shader实现）
    blur(720, 320, 100, 60, 180, 1.0f);
}
```

