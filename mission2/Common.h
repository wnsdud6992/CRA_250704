#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <utility>
#include<memory>
#include<vector>

#define CLEAR_SCREEN "\033[H\033[2J"

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    NONE_CAR = 0,
    SEDAN = 1,
    SUV,
    TRUCK,
    MAX_CAR_TYPE,
};

enum Engine
{
    NONE_ENGINE = -1,
    BACK_ENGINE = 0,
    GM = 1,
    TOYOTA,
    WIA,
    BROKEN_ENGINE,
    MAX_ENGINE_TYPE,
};

enum brakeSystem
{
    NONE_BREAKSYS = -1,
    BACK_BREAKSYS = 0,
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
    MAX_BREAKSYS_TYPE
};

enum SteeringSystem
{
    NONE_STEERING = -1,
    BACK_STEERING = 0,
    BOSCH_S = 1,
    MOBIS,
    MAX_STEERINGSYS_TYPE
};

enum CheckResult
{
    INIT = 0,
    TEST = 1,
    RUN,
    MAX_CHECK_TYPE
};

enum InputErrorCode
{
    Success = 0,
    Exit,
    Error_NotInteger
};

enum Result_ErrorCode {
    Make_Success = 0,
    Make_Failed,
    Sedan_Unable_Continental_Brake,
    SUV_Unable_Toyota_Engine,
    Truck_Unable_Wia_Engine,
    Truck_Unable_Mando_Brake,
    Bosch_Brake_Only_Able_Bosch_Steering,
    Engine_Broken,
};

static void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}