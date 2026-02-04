#include "main.h"

int main() {
	glfwSetErrorCallback(glfw_error_callback);
    // 初始化GLFW
	if (!glfwInit()){
        MessageBox(NULL, L"GLFW initialization failed.\nGLFW初始化失败", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
	
    const char* glsl_version = "#version 130";
    // 窗口提示: 使用 OpenGL 3.0+ 上下文
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    // 创建GLFW窗口
    window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 Example", NULL, NULL);
    
    // 检查窗口是否创建成功
    if (window == NULL){
        MessageBox(NULL, L"GLFW window creation failed.\nGLFW创建窗口失败", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    // 设置当前上下文为GLFW窗口
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);// 启用垂直同步
    
    // 初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        MessageBox(NULL, L"Failed to initialize GLAD", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    // 初始化ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    io = &ImGui::GetIO();
    // 主循环
    while (!glfwWindowShouldClose(window)){
        // 轮询和处理事件 (输入, 窗口尺寸变化等)
        glfwPollEvents();

        // 开始新的 ImGui 帧
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        // 开始新的 ImGui 帧
        ImGui::NewFrame();
        {
            
        }
        // 渲染 (Rendering)
        ImGui::Render();
        // 渲染 ImGui 绘制列表到当前 OpenGL 上下文
        int display_w, display_h;
        // 获取当前窗口的帧缓冲大小 (可能与窗口大小不同)
        glfwGetFramebufferSize(window, &display_w, &display_h);
        // 设置视口 (Viewport) 为帧缓冲大小
        glViewport(0, 0, display_w, display_h);
        // 清除颜色缓冲区 (使用 ImGui 配置的清除颜色)
        glClear(GL_COLOR_BUFFER_BIT);
        // 渲染 ImGui 绘制列表到当前 OpenGL 上下文
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // 交换缓冲区 (显示渲染结果)
        glfwSwapBuffers(window);
    }
    // 清理ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    // 清理GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
	return 0;
}