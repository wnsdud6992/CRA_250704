#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <utility>


#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];
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

std::pair<InputErrorCode, int> getUserInput();
void printCurrentStepScreen(int step);
void selectOption(int& step, int answer);
void setStepIfAnswer0(int& step);
bool isInputRangeValid(int step, int answer);
void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);


void delay(int ms)
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

int main()
{
    int step = CarType_Q;

    while (1)
    {
        printCurrentStepScreen(step);
        
        auto[ErrorCode, answer] = getUserInput();

        if (ErrorCode == InputErrorCode::Exit) {
            printf("바이바이\n");
            break;
        }
        if (ErrorCode == InputErrorCode::Error_NotInteger) {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        if (isInputRangeValid(step, answer) == false) {
            delay(800);
            continue;
        }
        
        if (answer == 0) {
            setStepIfAnswer0(step);
            continue;
        }
       
        selectOption(step, answer);
    }
}

std::pair<InputErrorCode, int> getUserInput() {
    char buf[100];
    printf("INPUT > ");
    fgets(buf, sizeof(buf), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);

    if (!strcmp(buf, "exit"))
    {
        return { InputErrorCode::Exit, 0 };
    }

    // 숫자로 된 대답인지 확인
    char* checkNumber;
    int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        return { InputErrorCode::Error_NotInteger, 0 };
    }
    return { InputErrorCode::Success, answer };
}

void printCarTypeScreen() {
    printf(CLEAR_SCREEN);
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void printEngineScreen() {
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}
void printBreakSystemScreen() {
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}
void printSteeringSystemScreen() {
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}
void printRunTestScreen() {
    printf(CLEAR_SCREEN);
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void printCurrentStepScreen(int step) {
    switch (step) {
    case CarType_Q:
        printCarTypeScreen();
        break;
    case Engine_Q:
        printEngineScreen();
        break;
    case brakeSystem_Q:
        printBreakSystemScreen();
        break;
    case SteeringSystem_Q:
        printSteeringSystemScreen();
        break;
    case Run_Test:
        printRunTestScreen();
        break;
    default:
        printf("System Error.\n");
        return;
    }
    printf("===============================\n");
}

void selectOption(int &step, int answer) {
    if (step == CarType_Q)
    {
        selectCarType(answer);
        delay(800);
        step = Engine_Q;
    }
    else if (step == Engine_Q)
    {
        selectEngine(answer);
        delay(800);
        step = brakeSystem_Q;
    }
    else if (step == brakeSystem_Q)
    {
        selectbrakeSystem(answer);
        delay(800);
        step = SteeringSystem_Q;
    }
    else if (step == SteeringSystem_Q)
    {
        selectSteeringSystem(answer);
        delay(800);
        step = Run_Test;
    }
    else if (step == Run_Test && answer == CheckResult::RUN)
    {
        runProducedCar();
        delay(2000);
    }
    else if (step == Run_Test && answer == CheckResult::TEST)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
}

void setStepIfAnswer0(int &step) {
    if (step == Run_Test) {
        step = CarType_Q;
    }

    if (step > CarType_Q) {
        step -= 1;
    }
}

bool isInputRangeValid(int step, int answer) {
    switch (step) {
    case CarType_Q:
        if (!(answer > CarType::NONE_CAR && answer < CarType::MAX_CAR_TYPE)) {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            return false;
        }
        break;
    case Engine_Q:
        if (!(answer > Engine::NONE_ENGINE && answer < Engine::MAX_ENGINE_TYPE)) {
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            return false;
        }
        break;
    case brakeSystem_Q:
        if (!(answer > brakeSystem::NONE_BREAKSYS && answer < brakeSystem::MAX_BREAKSYS_TYPE)) {
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            return false;
        }
        break;
    case SteeringSystem_Q:
        if (!(answer > SteeringSystem::NONE_STEERING && answer < SteeringSystem::MAX_STEERINGSYS_TYPE)) {
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            return false;
        }
        break;
    case Run_Test:
        if (!(answer >= CheckResult::INIT && answer < CheckResult::MAX_CHECK_TYPE)) {
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            return false;
        }
        break;
    default:
        printf("System Error.\n");
        return false;
    }
    return true;
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;
    if (answer == SEDAN)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;
    if (answer == GM)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void selectbrakeSystem(int answer)
{
    stack[brakeSystem_Q] = answer;
    if (answer == MANDO)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    if (answer == BOSCH_S)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (stack[Engine_Q] == Engine::BROKEN_ENGINE)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (stack[CarType_Q] == CarType::SEDAN)
                printf("Car Type : Sedan\n");
            if (stack[CarType_Q] == CarType::SUV)
                printf("Car Type : SUV\n");
            if (stack[CarType_Q] == CarType::TRUCK)
                printf("Car Type : Truck\n");
            if (stack[Engine_Q] == Engine::GM)
                printf("Engine : GM\n");
            if (stack[Engine_Q] == Engine::TOYOTA)
                printf("Engine : TOYOTA\n");
            if (stack[Engine_Q] == Engine::WIA)
                printf("Engine : WIA\n");
            if (stack[brakeSystem_Q] == brakeSystem::MANDO)
                printf("Brake System : Mando");
            if (stack[brakeSystem_Q] == brakeSystem::CONTINENTAL)
                printf("Brake System : Continental\n");
            if (stack[brakeSystem_Q] == brakeSystem::BOSCH_B)
                printf("Brake System : Bosch\n");
            if (stack[SteeringSystem_Q] == SteeringSystem::BOSCH_S)
                printf("SteeringSystem : Bosch\n");
            if (stack[SteeringSystem_Q] == SteeringSystem::MOBIS)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

#endif