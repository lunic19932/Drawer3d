#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <iostream>
#include <learnopengl/camera.h>
#include "stb_image.h"
class Window
{
public:
    Window(unsigned int width, unsigned int height, const char *title);
    ~Window();
    bool ShouldClose();
    GLFWwindow *GetGLFWWindow();
    void processInput();
    void update();
    Camera getCamera();
       int getWidth() const { return width; }
    void setWidth(int width_) { width = width_; }
    int getHeight() const { return height; }
    void setHeight(int height_) { height = height_; }
private:
private:
    void initWindow(unsigned int width, unsigned int height, const char *title);
    void setCallbacks();
    void mouseCallback(GLFWwindow *window, double xpos, double ypos);
    void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);
    void framebufferSizeCallback(GLFWwindow *window, int width, int height);
    GLFWwindow *m_Window;
    // settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    static Camera camera;
    float lastX = SCR_WIDTH / 2.0f;
    float lastY = SCR_HEIGHT / 2.0f;
    bool firstMouse = true;

    // timing
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

        int height;
    int width;
};

#endif