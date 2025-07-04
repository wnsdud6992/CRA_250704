#pragma once
#include "Common.h"

class ScreenManager {
public:
    void printCurrentStepScreen(int step);
private:
    void printCarTypeScreen();
    void printEngineScreen();
    void printBreakSystemScreen();
    void printSteeringSystemScreen();
    void printRunTestScreen();

};