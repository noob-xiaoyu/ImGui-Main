# ImGui Main 项目文档

## 目录
- [项目概述](#项目概述)
- [技术栈](#技术栈)
- [项目架构](#项目架构)
- [模块介绍](#模块介绍)
  - [main 模块](#main-模块)
  - [UI 模块](#ui-模块)
  - [render 模块](#render-模块)
- [快速开始](#快速开始)
- [开发指南](#开发指南)
- [最佳实践](#最佳实践)
- [常见问题](#常见问题)
- [文档索引](#文档索引)

## 项目概述

ImGui Main 是一个基于 Dear ImGui 的 C++ 图形界面应用程序框架，使用 OpenGL 作为渲染后端。项目采用模块化设计，提供了完整的 UI 控件库和渲染功能，适合开发工具类应用、编辑器、调试工具等需要高效 UI 交互的场景。

### 主要特性

- **即时模式 GUI**：采用 Dear ImGui 的即时模式 GUI 范式，简化 UI 开发
- **高性能渲染**：使用 OpenGL 进行硬件加速渲染
- **模块化设计**：清晰的模块划分，便于功能扩展
- **丰富的控件**：提供按钮、输入框等常用控件
- **强大的渲染功能**：支持渐变、发光、模糊等高级效果
- **跨平台支持**：基于 GLFW 和 OpenGL，支持跨平台开发
- **现代化 C++**：使用现代 C++ 语法和标准库

### 应用场景

- 工具类应用
- 游戏编辑器
- 调试工具
- 数据可视化
- 配置界面
- 原型开发

### 纯渲染 UI 项目

此项目特别适合用于**纯渲染 UI 项目**，提供了完整的自定义 UI 渲染解决方案：

- **完全自定义渲染**：不依赖 ImGui 的默认控件，使用 render 模块提供的绘图函数完全自定义 UI 外观
- **灵活的样式控制**：通过 render 模块的渐变、发光、模糊等效果，实现独特的视觉风格
- **高性能绘制**：直接使用 OpenGL 渲染，避免 ImGui 控件的额外开销
- **混合模式支持**：可以结合 ImGui 的即时模式特性和自定义渲染，实现最佳的开发体验
- **游戏 UI 开发**：适合开发游戏中的 HUD、菜单、设置界面等纯渲染 UI
- **自定义控件库**：基于 render 模块可以轻松构建自定义控件库

#### 纯渲染 UI 开发示例

```cpp
void PureRenderUI() {
    using namespace render;
    
    // 完全自定义的 UI 渲染
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 自定义按钮样式
    gradient(100, 100, 200, 50, Color(0, 185, 255), Color(255, 1, 247), true);
    outline_glow(100, 100, 200, 50, Color(0, 185, 255), 5);
    text(200, 125, Color(255, 255, 255), "Custom Button", true);
    
    // 自定义输入框样式
    rectangle(100, 180, 300, 40, Color(30, 30, 30));
    rectangle_line(100, 180, 300, 40, Color(0, 185, 255), 5.0f, 2.0f);
    text(110, 200, Color(255, 255, 255), "Custom Input", false);
    
    // 自定义进度条
    gradient(100, 250, 300, 20, Color(0, 185, 255), Color(232, 255, 0), true);
    rectangle_line(100, 250, 300, 20, Color(255, 255, 255), 10.0f, 1.0f);
}
```

#### 纯渲染 UI 的优势

1. **视觉自由度**：不受 ImGui 默认控件样式的限制，可以完全自定义外观
2. **性能优化**：直接使用 OpenGL 绘制，减少中间层的开销
3. **品牌一致性**：可以精确控制 UI 的每个像素，确保品牌视觉一致性
4. **游戏集成**：与游戏渲染管线无缝集成，实现统一的视觉风格
5. **动画效果**：利用 render 模块的动画功能，实现流畅的 UI 动画

## 技术栈

| 技术/库 | 版本 | 用途 |
|---------|------|------|
| C++ | C++17+ | 核心开发语言 |
| OpenGL | 3.0+ | 图形渲染 |
| GLFW | - | 窗口管理与输入处理 |
| Dear ImGui | - | 即时模式 GUI 库 |
| GLAD | - | OpenGL 函数加载器 |
| nlohmann/json | - | JSON 数据处理 |
| stb | - | 图像加载和处理 |

## 项目架构

```
ImGui Main/
├── ImGui Main/                    # 主项目目录
│   ├── include/                   # 第三方库头文件
│   │   ├── glad/                  # OpenGL 加载库
│   │   ├── glfw/                  # 窗口管理库
│   │   ├── imgui/                 # Dear ImGui 库
│   │   ├── nlohmann/              # JSON 库
│   │   └── stb-master/            # STB 图像库
│   ├── main/                      # 主要源代码
│   │   ├── UI/                    # UI 模块
│   │   │   ├── UI.h               # UI 模块头文件
│   │   │   ├── UI.cpp             # UI 模块实现
│   │   │   └── UI.md              # UI 模块文档
│   │   ├── reneder/               # 渲染模块
│   │   │   ├── render.h           # 渲染模块头文件
│   │   │   ├── render.cpp         # 渲染模块实现
│   │   │   └── render.md          # 渲染模块文档
│   │   ├── main.cpp               # 主入口文件
│   │   └── main.h                 # 主头文件
│   └── ImGui Main.vcxproj         # Visual Studio 项目文件
├── ImGui Main.sln                 # Visual Studio 解决方案文件
└── README.md                      # 项目文档
```

### 架构设计原则

1. **模块化**：每个模块职责单一，接口清晰
2. **分层设计**：逻辑层与渲染层分离
3. **低耦合**：模块间依赖最小化
4. **高内聚**：相关功能集中在同一模块
5. **可扩展**：便于添加新功能和新模块

## 模块介绍

### main 模块

main 模块是应用程序的入口，负责初始化和管理整个应用程序的生命周期。

#### 主要功能

- GLFW 窗口初始化和管理
- OpenGL 上下文创建
- Dear ImGui 初始化和配置
- 主循环管理
- 事件处理
- 资源清理

#### 核心文件

- **main.cpp**：主入口文件，包含应用程序的主循环
- **main.h**：主头文件，包含全局变量和函数声明

#### 使用示例

```cpp
#include "main.h"

int main() {
    // 初始化 GLFW
    if (!glfwInit()) {
        return 1;
    }
    
    // 创建窗口
    window = glfwCreateWindow(1280, 720, "ImGui Application", NULL, NULL);
    if (!window) {
        return 1;
    }
    
    // 设置 OpenGL 上下文
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    // 初始化 ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    
    // 主循环
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        // 你的 UI 代码
        
        ImGui::Render();
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
    
    // 清理
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
```

### UI 模块

UI 模块提供了轻量级的即时模式 UI 控件库，支持按钮和文本输入框等常用控件。

#### 主要特性

- 即时模式渲染
- 状态管理
- 事件处理
- 密码模式支持
- 剪贴板支持

#### 核心类

- **Button**：交互式按钮控件
- **InputText**：文本输入框控件

#### 详细文档

详见 [UI.md](file:///c:/Users/xioayu/Desktop/ImGui%20Main/ImGui%20Main/main/UI/UI.md)

#### 使用示例

```cpp
#include "UI.h"
#include "render.h"

void ExampleUI() {
    using namespace render;
    
    static UI::ID next_id = 1;
    
    // 创建按钮
    if (button(next_id++, "Click Me", 100, 100, 120, 40, Color(60, 60, 60))) {
        // 按钮被点击
    }
    
    // 创建输入框
    const std::string& text = InputText(next_id++, "Input:", 100, 160, 200, 30, Color(30, 30, 30));
}
```

### render 模块

render 模块提供了丰富的绘图函数，支持各种图形效果和高级渲染功能。

#### 主要功能

- 基础图形绘制（线条、矩形、圆形、三角形）
- 渐变效果（双色渐变、多色渐变）
- 高级效果（发光、模糊）
- 加载动画
- 交互式控件渲染

#### 核心函数

- **基础绘图**：`line()`, `text()`, `rectangle()`, `circle()`, `triangle()`
- **渐变效果**：`gradient()`, `DrawGradientBar()`
- **高级效果**：`outline_glow()`, `blur()`, `blur_fake()`
- **动画效果**：`render_loading_circle()`, `loading_text()`
- **控件渲染**：`button()`, `InputText()`

#### 详细文档

详见 [render.md](file:///c:/Users/xioayu/Desktop/ImGui%20Main/ImGui%20Main/main/reneder/render.md)

#### 使用示例

```cpp
#include "render.h"

void ExampleRender() {
    using namespace render;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制渐变矩形
    gradient(100, 100, 200, 100, Color(255, 0, 0), Color(0, 0, 255), true);
    
    // 绘制发光效果
    outline_glow(100, 250, 200, 60, Color(0, 185, 255), 10);
    
    // 绘制加载动画
    loading_text(100, 350, Color(255, 255, 255), "Loading");
}
```

## 快速开始

### 环境要求

- **操作系统**：Windows 10/11
- **开发工具**：Visual Studio 2019 或更高版本
- **C++ 标准**：C++17 或更高

### 构建步骤

1. **打开解决方案**

   双击 `ImGui Main.sln` 文件，在 Visual Studio 中打开项目。

2. **选择配置**

   在 Visual Studio 顶部工具栏选择：
   - 配置：Debug 或 Release
   - 平台：x64 或 Win32

3. **构建项目**

   按 `F7` 或点击"生成" → "生成解决方案"。

4. **运行程序**

   按 `F5` 或点击"调试" → "开始调试"。

### 第一个程序

创建一个简单的 Hello World 程序：

```cpp
#include "main.h"
#include "render.h"

void RenderHelloWorld() {
    using namespace render;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 360, Color(255, 255, 255), "Hello World!", true);
}

int main() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        MessageBox(NULL, L"GLFW initialization failed.", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (window == NULL) {
        MessageBox(NULL, L"GLFW window creation failed.", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        MessageBox(NULL, L"Failed to initialize GLAD", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    io = &ImGui::GetIO();
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        RenderHelloWorld();
        
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
```

## 开发指南

### 项目结构

在开发新功能时，建议按照以下结构组织代码：

```
main/
├── UI/                    # UI 相关代码
│   ├── UI.h
│   ├── UI.cpp
│   └── UI.md
├── reneder/               # 渲染相关代码
│   ├── render.h
│   ├── render.cpp
│   └── render.md
├── main.cpp               # 主入口
└── main.h                 # 主头文件
```

### 添加新模块

1. **创建模块目录**

   在 `main/` 目录下创建新的模块目录。

2. **创建头文件**

   创建模块的头文件，声明公共接口。

3. **创建实现文件**

   创建模块的实现文件，实现具体功能。

4. **创建文档**

   创建模块的文档文件，说明 API 和使用方法。

5. **更新主头文件**

   在 `main.h` 中包含新模块的头文件。

### 代码风格

- **命名规范**：
  - 类名：大驼峰（PascalCase）
  - 函数名：小写加下划线（snake_case）
  - 变量名：小写加下划线（snake_case）
  - 常量名：全大写加下划线（UPPER_SNAKE_CASE）

- **缩进**：使用 4 个空格缩进

- **注释**：使用 `//` 进行单行注释，避免使用 `/* */`

- **头文件保护**：使用 `#pragma once`

### 调试技巧

1. **使用 Visual Studio 调试器**

   - 设置断点：在代码行号左侧点击
   - 查看变量：在调试窗口中查看变量值
   - 单步执行：使用 F10（单步跳过）和 F11（单步进入）

2. **输出调试信息**

   ```cpp
   #include <iostream>
   
   std::cout << "Debug message" << std::endl;
   ```

3. **使用 ImGui 内置调试工具**

   ```cpp
   ImGui::ShowDemoWindow();
   ImGui::ShowMetricsWindow();
   ```

## 最佳实践

### 1. 性能优化

- **避免频繁的内存分配**：在渲染循环中避免使用 `new` 和 `malloc`
- **使用栈内存**：优先使用栈变量而非堆变量
- **预分配内存**：对于频繁使用的对象，预先分配内存
- **减少绘制调用**：合并相似的绘制操作

```cpp
// 好的做法
static std::vector<ImVec2> points;
points.clear();
for (int i = 0; i < 100; i++) {
    points.push_back(ImVec2(i, i));
}

// 避免
for (int i = 0; i < 100; i++) {
    std::vector<ImVec2> points;
    points.push_back(ImVec2(i, i));
}
```

### 2. 状态管理

- **使用 static 变量**：对于需要持久化的状态，使用 static 变量
- **ID 管理**：确保每个控件的 ID 是唯一的
- **状态同步**：保持 UI 状态与渲染状态的同步

```cpp
// 好的做法
static UI::ID next_id = 1;
static std::string username;

// 避免
UI::ID next_id = 1;
std::string username;
```

### 3. 错误处理

- **检查返回值**：始终检查函数的返回值
- **处理异常**：使用 try-catch 处理异常
- **提供错误信息**：提供清晰的错误信息

```cpp
// 好的做法
if (!glfwInit()) {
    MessageBox(NULL, L"GLFW initialization failed.", L"Error", MB_OK | MB_ICONERROR);
    return 1;
}

// 避免
glfwInit();
```

### 4. 代码组织

- **模块化**：将相关功能组织在同一模块中
- **接口清晰**：提供清晰的公共接口
- **封装实现**：隐藏实现细节

```cpp
// 好的做法
namespace UI {
    class Button {
    public:
        bool Update();
    private:
        bool m_hovered;
    };
}

// 避免
class Button {
public:
    bool Update();
    bool m_hovered;
};
```

### 5. 资源管理

- **及时释放资源**：在不再需要时及时释放资源
- **使用 RAII**：使用 RAII 模式管理资源
- **避免内存泄漏**：确保所有分配的内存都被释放

```cpp
// 好的做法
{
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
}

// 避免
{
    Resource* resource = new Resource();
    // 忘记删除
}
```

## 常见问题

### Q1: 如何更改窗口大小？

在 `main.cpp` 中修改 `glfwCreateWindow` 的参数：

```cpp
window = glfwCreateWindow(1920, 1080, "ImGui Application", NULL, NULL);
```

### Q2: 如何更改窗口标题？

在 `main.cpp` 中修改 `glfwCreateWindow` 的第三个参数：

```cpp
window = glfwCreateWindow(1280, 720, "My Application", NULL, NULL);
```

### Q3: 如何启用全屏模式？

在 `glfwCreateWindow` 中使用 `glfwGetPrimaryMonitor()`：

```cpp
window = glfwCreateWindow(1920, 1080, "ImGui Application", glfwGetPrimaryMonitor(), NULL);
```

### Q4: 如何更改清除颜色？

在主循环中修改 `glClearColor`：

```cpp
glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
```

### Q5: 如何禁用垂直同步？

在创建窗口后设置 `glfwSwapInterval(0)`：

```cpp
glfwMakeContextCurrent(window);
glfwSwapInterval(0);
```

### Q6: 如何添加自定义字体？

在初始化 ImGui 后加载字体：

```cpp
ImGuiIO& io = ImGui::GetIO();
ImFont* font = io.Fonts->AddFontFromFileTTF("path/to/font.ttf", 18.0f);
ImGui_ImplOpenGL3_CreateFontsTexture();
```

### Q7: 如何处理窗口大小变化？

注册窗口大小回调：

```cpp
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
```

### Q8: 如何获取鼠标位置？

```cpp
ImVec2 mouse_pos = ImGui::GetIO().MousePos;
```

### Q9: 如何检测鼠标点击？

```cpp
if (ImGui::IsMouseClicked(0)) {
    // 左键被点击
}
```

### Q10: 如何检测键盘按键？

```cpp
if (ImGui::IsKeyPressed(ImGuiKey_A)) {
    // A 键被按下
}
```

## 文档索引

- [UI 模块文档](file:///c:/Users/xioayu/Desktop/ImGui%20Main/ImGui%20Main/main/UI/UI.md)
- [render 模块文档](file:///c:/Users/xioayu/Desktop/ImGui%20Main/ImGui%20Main/main/reneder/render.md)

## 贡献指南

欢迎贡献代码和建议！请遵循以下步骤：

1. Fork 项目
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

## 许可证

本项目采用 [MIT 许可证](LICENSE)。

## 联系方式

如有问题或建议，请通过以下方式联系：

- 提交 Issue
- 发送邮件
- 加入讨论组

---

**最后更新**：2026-02-05/15:19

**作者**：[xioayu](https://github.com/noob-xiaoyu)
