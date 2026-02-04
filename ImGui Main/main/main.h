#pragma once
#include "glad/glad.h"
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#pragma comment(lib, "opengl32.lib")

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

GLFWwindow* window;
ImGuiIO* io;

static int window_width = 1280;
static int window_height = 720;

