#include <string>
#include <filesystem.h>
#define DEFAULT_WINDOW_HEIGHT 1.0
#define DEFAULT_WINDOW_WIDTH 1.0

#define DEFAULT_MAXSPEED 10
#define DEFAULT_STEPX 1.0
#define DEFAULT_STEPY 1.0
#define DEFAULT_STEPZ 1.0
#define DEFAULT_FR 1.0

#define DEFAULT_AXISX 200.0
#define DEFAULT_AXISY 200.0
#define DEFAULT_AXISZ 200.0


class Settings
{
private:
    const int windowHeight;
    const int windowWidth;
    const std::string axisPaths[1];//Axis-Object-Paths
    int maxSpeedX;//Max-TiksRate per Steps
    int maxSpeedY;//Max-TiksRate per Steps
    int maxSpeedZ;//Max-TiksRate per Steps
    float stepX;//step-Size in mm
    float stepY;//step-Size in mm
    float stepZ;//step-Size in mm
    float stepFR;//step-FlowRate
    float axisX;//Axis-Length in mm
    float axisY;//Axis-Length in mm
    float axisZ;//Axis-Length in mm
    int maxStepX;//max Count of Steps
    float maxStepX_mm;//max Position in mm
    int maxStepY;//max Count of Steps
    float maxStepY_mm;//max Position in mm
    int maxStepZ;//max Count of Steps
    float maxStepZ_mm;//max Position in mm
    void calculateMaxStepX();
    void calculateMaxStepY();
    void calculateMaxStepZ();
    Settings();
    static Settings* instance;
public:
    static Settings* getInstance();
    void setAllDrawerSettings( int maxSpeedX,int maxSpeedY,int maxSpeedZ,float stepX,float stepY,float stepZ,float stepFR,float axisX,float axisY,float axisZ);


};