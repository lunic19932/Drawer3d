#ifndef DRAWERSIM_H
#define DRAWERSIM_H
#include "Window.h"
#include <learnopengl/shader.h>
#include <learnopengl/model.h>
#include <learnopengl/filesystem.h>

#pragma once

class DrawerSim
{
public:
    DrawerSim();
    ~DrawerSim();

    void run();
    void setBGColor(float r,float g,float b,float t);
 
    Window window;
    std::vector<Model> axis_Model;

    float BGColor[4];
    Shader modelShader;


};

#endif