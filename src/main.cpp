#include <iostream>
#include "Drawer3D/Window.h"
#include "learnopengl/camera.h"
int main(int argc, char const *argv[])
{
    Window window(500, 500, "Drawer");
    std::cout << "Test" << std::endl;
    while (!window.ShouldClose())
    {
        glfwPollEvents();
    }
    return 0;
}
