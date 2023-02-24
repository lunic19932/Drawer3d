#include "Settings.h"
Settings *Settings::instance = nullptr;
void Settings::calculateMaxStepX()
{
    maxStepX = axisX / stepX;
    maxStepX_mm = maxStepX * stepX;
}

void Settings::calculateMaxStepY()
{
    maxStepY = axisY / stepY;
    maxStepY_mm = maxStepY * stepY;
}

void Settings::calculateMaxStepZ()
{
    maxStepZ = axisZ / stepZ;
    maxStepZ_mm = maxStepZ * stepZ;
}

Settings::Settings() : windowHeight(DEFAULT_WINDOW_HEIGHT),
                       windowWidth(DEFAULT_WINDOW_WIDTH),
                       axisPaths({"resources/objects/backpack/backpack.obj"}),
                       stepX(DEFAULT_STEPX),
                       stepY(DEFAULT_STEPY),
                       stepZ(DEFAULT_STEPZ),
                       stepFR(DEFAULT_FR),
                       axisX(DEFAULT_AXISX),
                       axisY(DEFAULT_AXISY),
                       axisZ(DEFAULT_AXISZ)
{
    calculateMaxStepX();
    calculateMaxStepY();
    calculateMaxStepZ();
}

Settings *Settings::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Settings();
    }
    return instance;
}

void Settings::setAllDrawerSettings(int maxSpeedX, int maxSpeedY, int maxSpeedZ, float stepX, float stepY, float stepZ, float stepFR, float axisX, float axisY, float axisZ)
{
    this->maxSpeedX = maxSpeedX;
    this->maxSpeedY = maxSpeedY;
    this->maxSpeedZ = maxSpeedZ;
    this->stepX = stepX;
    this->stepY = stepY;
    this->stepZ = stepZ;
    this->stepFR = stepFR;
    this->axisX = axisX;
    this->axisY = axisY;
    this->axisZ = axisZ;

    calculateMaxStepX();
    calculateMaxStepY();
    calculateMaxStepZ();
}
