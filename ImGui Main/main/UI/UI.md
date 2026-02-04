# UI 模块文档

## 目录
- [包含头文件](#包含头文件)
- [概述](#概述)
- [核心概念](#核心概念)
- [API 参考](#api-参考)
  - [基础类型和函数](#基础类型和函数)
  - [Button 类](#button-类)
  - [InputText 类](#inputtext-类)
- [使用示例](#使用示例)

## 包含头文件
```cpp
#include "UI.h"
```

## 概述

UI 模块是一个轻量级的即时模式 UI 库，基于 Dear ImGui 构建，提供了基础的交互式控件。该模块采用状态管理机制，支持按钮和文本输入框等常用控件。

### 主要特性

- **即时模式渲染**：每帧重新构建 UI 状态
- **状态管理**：自动管理激活、悬停等状态
- **事件处理**：支持鼠标点击、键盘输入等事件
- **密码模式**：支持密码输入框
- **剪贴板支持**：支持复制和粘贴操作

## 核心概念

### ID 系统

每个 UI 控件都需要一个唯一的标识符（ID），用于状态管理和事件处理。ID 是 `unsigned int` 类型，可以使用递增的整数或哈希值。

```cpp
using ID = unsigned int;

// 使用递增 ID
static UI::ID next_id = 1;
UI::ID button_id = next_id++;

// 使用哈希 ID
UI::ID input_id = std::hash<std::string>{}("username");
```

### 状态管理

UI 模块使用全局上下文来管理控件状态：

- **Active ID**：当前激活的控件 ID（例如正在输入的文本框）
- **Hot ID**：当前悬停的控件 ID（虽然定义了但当前未使用）

### 生命周期

1. **创建控件**：使用构造函数创建控件实例
2. **更新状态**：每帧调用 `Update()` 方法更新控件状态
3. **处理事件**：根据返回值处理用户交互
4. **渲染控件**：使用 `render` 模块绘制控件外观

## API 参考

### 基础类型和函数

#### ID 类型
```cpp
using ID = unsigned int;
```
控件唯一标识符类型。

#### Context 结构体
```cpp
struct Context {
    ID active_id = 0;
    ID hot_id = 0;
};
```
全局上下文，存储当前激活和悬停的控件 ID。

#### GetActiveID
```cpp
ID GetActiveID();
```
获取当前激活的控件 ID。

**返回值**：当前激活的控件 ID，如果没有则为 0。

#### SetActive
```cpp
void SetActive(ID id);
```
设置当前激活的控件 ID。

**参数**：
- `id`：要激活的控件 ID

#### ClearActive
```cpp
void ClearActive();
```
清除当前激活的控件 ID。

#### IsActive
```cpp
bool IsActive(ID id);
```
检查指定控件是否处于激活状态。

**参数**：
- `id`：要检查的控件 ID

**返回值**：如果控件处于激活状态则返回 true，否则返回 false。

### Button 类

#### 构造函数
```cpp
Button(ID id, const ImVec2& pos, const ImVec2& size);
```
创建按钮实例。

**参数**：
- `id`：按钮唯一标识符
- `pos`：按钮位置（左上角坐标）
- `size`：按钮大小（宽度和高度）

#### Update
```cpp
bool Update();
```
更新按钮状态，每帧调用一次。

**返回值**：如果按钮被点击则返回 true，否则返回 false。

**特性**：
- 自动检测鼠标悬停
- 自动处理鼠标点击事件
- 支持禁用状态
- 自动管理激活状态

#### SetEnabled
```cpp
void SetEnabled(bool enabled);
```
设置按钮是否启用。

**参数**：
- `enabled`：true 表示启用，false 表示禁用

#### Hovered
```cpp
bool Hovered() const;
```
检查按钮是否被鼠标悬停。

**返回值**：如果按钮被悬停则返回 true，否则返回 false。

#### Pressed
```cpp
bool Pressed() const;
```
检查按钮是否被按下。

**返回值**：如果按钮被按下则返回 true，否则返回 false。

#### Enabled
```cpp
bool Enabled() const;
```
检查按钮是否启用。

**返回值**：如果按钮启用则返回 true，否则返回 false。

#### Active
```cpp
bool Active() const;
```
检查按钮是否处于激活状态。

**返回值**：如果按钮处于激活状态则返回 true，否则返回 false。

#### SetPos
```cpp
void SetPos(const ImVec2& pos);
```
设置按钮位置。

**参数**：
- `pos`：新的位置（左上角坐标）

#### SetSize
```cpp
void SetSize(const ImVec2& size);
```
设置按钮大小。

**参数**：
- `size`：新的大小（宽度和高度）

### InputText 类

#### 构造函数
```cpp
InputText(ID id, ImVec2 pos, ImVec2 size);
```
创建文本输入框实例。

**参数**：
- `id`：输入框唯一标识符
- `pos`：输入框位置（左上角坐标）
- `size`：输入框大小（宽度和高度）

#### Update
```cpp
bool Update();
```
更新输入框状态，每帧调用一次。

**返回值**：如果输入框内容发生变化则返回 true，否则返回 false。

**特性**：
- 支持字符输入
- 支持退格键和删除键
- 支持左右箭头键移动光标
- 支持 Home/End 键
- 支持 Ctrl+C 复制
- 支持 Ctrl+V 粘贴
- 支持 Escape/Enter 键失焦
- 光标闪烁效果
- 密码模式支持

#### SetEnabled
```cpp
void SetEnabled(bool enabled);
```
设置输入框是否启用。

**参数**：
- `enabled`：true 表示启用，false 表示禁用

#### SetText
```cpp
void SetText(const std::string& text);
```
设置输入框文本内容。

**参数**：
- `text`：要设置的文本内容

#### GetText
```cpp
const std::string& GetText() const;
```
获取输入框当前文本内容。

**返回值**：输入框当前文本内容的引用。

#### IsActive
```cpp
bool IsActive() const;
```
检查输入框是否处于激活状态（有焦点）。

**返回值**：如果输入框处于激活状态则返回 true，否则返回 false。

#### IsCursorVisible
```cpp
bool IsCursorVisible() const;
```
检查光标是否可见。

**返回值**：如果光标可见则返回 true，否则返回 false。

#### IsHovered
```cpp
bool IsHovered() const;
```
检查输入框是否被鼠标悬停。

**返回值**：如果输入框被悬停则返回 true，否则返回 false。

#### GetCursorPosition
```cpp
int GetCursorPosition() const;
```
获取当前光标位置。

**返回值**：光标位置（字符索引）。

#### SetPasswordMode
```cpp
void SetPasswordMode(bool password);
```
设置是否为密码模式。

**参数**：
- `password`：true 表示密码模式，false 表示普通模式

#### IsPasswordMode
```cpp
bool IsPasswordMode() const;
```
检查是否为密码模式。

**返回值**：如果是密码模式则返回 true，否则返回 false。

#### TogglePasswordVisible
```cpp
void TogglePasswordVisible();
```
切换密码可见性（显示/隐藏密码）。

#### IsPasswordVisible
```cpp
bool IsPasswordVisible() const;
```
检查密码是否可见。

**返回值**：如果密码可见则返回 true，否则返回 false。

## 使用示例

### 基础按钮示例

```cpp
#include "UI.h"
#include "render.h"

void BasicButtonExample() {
    using namespace UI;
    using namespace render;
    
    static ID button_id = 1;
    
    // 创建按钮
    Button btn(button_id++, ImVec2(100, 100), ImVec2(120, 40));
    
    // 更新按钮状态
    bool clicked = btn.Update();
    
    // 渲染按钮
    Color bg_color;
    if (!btn.Enabled()) {
        bg_color = Color(50, 50, 50);
    } else if (btn.Active()) {
        bg_color = Color(80, 80, 80);
    } else if (btn.Hovered()) {
        bg_color = Color(70, 70, 70);
    } else {
        bg_color = Color(60, 60, 60);
    }
    
    rectangle(100, 100, 120, 40, bg_color, 5.0f);
    text(160, 120, Color(255, 255, 255), "Click Me", true);
    
    // 处理点击事件
    if (clicked) {
        // 按钮被点击
    }
}
```

### 使用 render::button 简化按钮

```cpp
void SimplifiedButtonExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    
    // 使用 render::button 简化按钮创建
    if (button(next_id++, "Click Me", 100, 100, 120, 40, Color(60, 60, 60))) {
        // 按钮被点击
    }
    
    // 禁用按钮
    button(next_id++, "Disabled", 100, 150, 120, 40, Color(60, 60, 60), false);
}
```

### 基础输入框示例

```cpp
#include "UI.h"
#include "render.h"

void BasicInputTextExample() {
    using namespace UI;
    using namespace render;
    
    static ID input_id = 1;
    
    // 创建输入框
    InputText input(input_id++, ImVec2(100, 100), ImVec2(200, 30));
    
    // 更新输入框状态
    bool changed = input.Update();
    
    // 渲染输入框
    Color bg_color;
    if (input.IsActive()) {
        bg_color = Color(86, 157, 229);
    } else if (input.IsHovered()) {
        bg_color = Color(126, 180, 234);
    } else {
        bg_color = Color(30, 30, 30);
    }
    
    rectangle(100, 100, 200, 30, Color(0, 0, 0));
    rectangle(102, 102, 196, 26, bg_color);
    text(100, 80, Color(255, 255, 255), "Username:", false);
    text(108, 108, Color(255, 255, 255), input.GetText().c_str(), false);
    
    // 渲染光标
    if (input.IsActive() && input.IsCursorVisible()) {
        int cursor_pos = input.GetCursorPosition();
        std::string text_before_cursor = input.GetText().substr(0, cursor_pos);
        ImVec2 text_size = ImGui::CalcTextSize(text_before_cursor.c_str());
        float cursor_x = 108 + text_size.x;
        rectangle(cursor_x, 108, 2, 22, Color(255, 255, 255));
    }
    
    // 处理内容变化
    if (changed) {
        // 输入框内容发生变化
    }
}
```

### 使用 render::InputText 简化输入框

```cpp
void SimplifiedInputTextExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    
    // 使用 render::InputText 简化输入框创建
    const std::string& username = InputText(next_id++, "Username:", 100, 100, 200, 30, Color(30, 30, 30));
    
    // 密码输入框
    const std::string& password = InputText(next_id++, "Password:", 100, 150, 200, 30, Color(30, 30, 30), true, true);
    
    // 禁用输入框
    InputText(next_id++, "Disabled:", 100, 200, 200, 30, Color(30, 30, 30), false);
}
```

### 登录界面示例

```cpp
void LoginScreenExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    static bool show_password = false;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 100, Color(255, 255, 255), "Login", true);
    
    // 用户名输入框
    const std::string& username = InputText(next_id++, "Username:", 540, 200, 200, 30, Color(30, 30, 30));
    
    // 密码输入框
    const std::string& password = InputText(next_id++, "Password:", 540, 280, 200, 30, Color(30, 30, 30), true, !show_password);
    
    // 显示/隐藏密码按钮
    if (button(next_id++, show_password ? "Hide" : "Show", 750, 280, 80, 30, Color(50, 50, 50))) {
        show_password = !show_password;
    }
    
    // 登录按钮
    if (button(next_id++, "Login", 540, 350, 200, 40, Color(0, 185, 255))) {
        if (!username.empty() && !password.empty()) {
            // 执行登录逻辑
        }
    }
    
    // 取消按钮
    if (button(next_id++, "Cancel", 540, 400, 200, 40, Color(100, 100, 100))) {
        // 取消登录
    }
}
```

### 表单示例

```cpp
void FormExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 50, Color(255, 255, 255), "Registration Form", true);
    
    // 表单字段
    const std::string& name = InputText(next_id++, "Full Name:", 440, 100, 400, 30, Color(30, 30, 30));
    const std::string& email = InputText(next_id++, "Email:", 440, 160, 400, 30, Color(30, 30, 30));
    const std::string& phone = InputText(next_id++, "Phone:", 440, 220, 400, 30, Color(30, 30, 30));
    const std::string& address = InputText(next_id++, "Address:", 440, 280, 400, 30, Color(30, 30, 30));
    const std::string& password = InputText(next_id++, "Password:", 440, 340, 400, 30, Color(30, 30, 30), true, true);
    const std::string& confirm_password = InputText(next_id++, "Confirm Password:", 440, 400, 400, 30, Color(30, 30, 30), true, true);
    
    // 提交按钮
    if (button(next_id++, "Submit", 440, 470, 190, 40, Color(0, 185, 255))) {
        if (!name.empty() && !email.empty() && !password.empty()) {
            if (password == confirm_password) {
                // 提交表单
            }
        }
    }
    
    // 重置按钮
    if (button(next_id++, "Reset", 650, 470, 190, 40, Color(100, 100, 100))) {
        // 重置表单
    }
}
```

### 设置面板示例

```cpp
void SettingsPanelExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 50, Color(255, 255, 255), "Settings", true);
    
    // 用户设置
    text(100, 100, Color(255, 255, 255), "User Settings", false);
    const std::string& username = InputText(next_id++, "Username:", 100, 130, 200, 30, Color(30, 30, 30));
    const std::string& display_name = InputText(next_id++, "Display Name:", 100, 180, 200, 30, Color(30, 30, 30));
    const std::string& email = InputText(next_id++, "Email:", 100, 230, 200, 30, Color(30, 30, 30));
    
    // 网络设置
    text(100, 300, Color(255, 255, 255), "Network Settings", false);
    const std::string& server_ip = InputText(next_id++, "Server IP:", 100, 330, 200, 30, Color(30, 30, 30));
    const std::string& server_port = InputText(next_id++, "Server Port:", 100, 380, 200, 30, Color(30, 30, 30));
    
    // 保存按钮
    if (button(next_id++, "Save", 100, 450, 95, 40, Color(0, 185, 255))) {
        // 保存设置
    }
    
    // 取消按钮
    if (button(next_id++, "Cancel", 205, 450, 95, 40, Color(100, 100, 100))) {
        // 取消更改
    }
}
```

### 动态控件示例

```cpp
void DynamicControlsExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    static std::vector<std::string> items;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    // 绘制标题
    text(640, 50, Color(255, 255, 255), "Dynamic Controls", true);
    
    // 添加项目输入框
    const std::string& new_item = InputText(next_id++, "New Item:", 440, 100, 200, 30, Color(30, 30, 30));
    
    // 添加按钮
    if (button(next_id++, "Add", 650, 100, 90, 30, Color(0, 185, 255))) {
        if (!new_item.empty()) {
            items.push_back(new_item);
        }
    }
    
    // 清空按钮
    if (button(next_id++, "Clear All", 750, 100, 90, 30, Color(255, 100, 100))) {
        items.clear();
    }
    
    // 显示项目列表
    float y = 160;
    for (size_t i = 0; i < items.size(); i++) {
        text(440, y, Color(255, 255, 255), items[i].c_str(), false);
        
        // 删除按钮
        if (button(next_id++, "Delete", 650, y - 10, 80, 30, Color(255, 100, 100))) {
            items.erase(items.begin() + i);
            break;
        }
        
        y += 50;
    }
}
```

### 综合示例

```cpp
void ComprehensiveExample() {
    using namespace render;
    
    static UI::ID next_id = 1;
    static bool logged_in = false;
    static std::string username;
    
    // 绘制背景
    rectangle(0, 0, 1280, 720, Color(20, 20, 20));
    
    if (!logged_in) {
        // 登录界面
        text(640, 150, Color(255, 255, 255), "Welcome", true);
        
        const std::string& user_input = InputText(next_id++, "Username:", 540, 220, 200, 30, Color(30, 30, 30));
        const std::string& pass_input = InputText(next_id++, "Password:", 540, 280, 200, 30, Color(30, 30, 30), true, true);
        
        if (button(next_id++, "Login", 540, 350, 200, 40, Color(0, 185, 255))) {
            if (!user_input.empty() && !pass_input.empty()) {
                username = user_input;
                logged_in = true;
            }
        }
    } else {
        // 主界面
        text(640, 50, Color(255, 255, 255), "Dashboard", true);
        text(640, 80, Color(200, 200, 200), ("Welcome, " + username).c_str(), true);
        
        // 功能按钮
        if (button(next_id++, "Profile", 100, 150, 150, 40, Color(50, 50, 50))) {
            // 打开个人资料
        }
        
        if (button(next_id++, "Settings", 270, 150, 150, 40, Color(50, 50, 50))) {
            // 打开设置
        }
        
        if (button(next_id++, "Logout", 440, 150, 150, 40, Color(255, 100, 100))) {
            logged_in = false;
            username.clear();
        }
        
        // 输入框区域
        const std::string& search = InputText(next_id++, "Search:", 100, 250, 300, 30, Color(30, 30, 30));
        const std::string& note = InputText(next_id++, "Note:", 100, 320, 300, 30, Color(30, 30, 30));
        
        // 操作按钮
        if (button(next_id++, "Search", 420, 250, 100, 30, Color(0, 185, 255))) {
            // 执行搜索
        }
        
        if (button(next_id++, "Save", 420, 320, 100, 30, Color(0, 185, 255))) {
            // 保存笔记
        }
    }
}
```

## 最佳实践

### 1. ID 管理

使用递增的 ID 或哈希值来确保每个控件的唯一性：

```cpp
// 方法 1：递增 ID
static UI::ID next_id = 1;
UI::ID my_button_id = next_id++;

// 方法 2：哈希 ID
UI::ID my_input_id = std::hash<std::string>{}("unique_name");
```

### 2. 状态持久化

对于需要持久化的控件，使用 `static` 变量：

```cpp
static UI::ID next_id = 1;
static std::string username;
static bool remember_me = false;
```

### 3. 渲染分离

将 UI 逻辑与渲染逻辑分离：

```cpp
// UI 逻辑
Button btn(id, pos, size);
bool clicked = btn.Update();

// 渲染逻辑
if (btn.Hovered()) {
    render::rectangle(pos.x, pos.y, size.x, size.y, hover_color);
} else {
    render::rectangle(pos.x, pos.y, size.x, size.y, normal_color);
}
```

### 4. 事件处理

在 `Update()` 返回 true 时处理事件：

```cpp
if (btn.Update()) {
    // 处理按钮点击
}

if (input.Update()) {
    // 处理输入变化
}
```

### 5. 性能优化

- 避免在渲染循环中创建临时对象
- 使用引用传递大对象
- 缓存常用计算结果

```cpp
// 好的做法
const std::string& text = input.GetText();
text(x, y, color, text.c_str(), centered);

// 避免
text(x, y, color, input.GetText().c_str(), centered);
```

## 注意事项

1. **ID 唯一性**：确保每个控件的 ID 在整个应用程序中是唯一的
2. **更新频率**：每帧都必须调用 `Update()` 方法
3. **状态同步**：UI 状态与渲染状态需要保持同步
4. **内存管理**：使用 `static` 变量持久化控件状态
5. **线程安全**：UI 模块不是线程安全的，只能在主线程中使用
6. **剪贴板**：剪贴板功能仅在 Windows 平台可用