#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include "Common.h"
#include "ScreenManager.h"
#include "CarManager.h"
#include "EngineManager.h"
#include "BrakeSysManager.h"
#include "SteeringSysManager.h"
#include "TestSysManager.h"

std::unique_ptr<ScreenManager> screenmanager = std::make_unique<ScreenManager>();
std::unique_ptr<CarManager> carmanager = std::make_unique<CarManager>();
std::unique_ptr<EngineManager> enginemanager = std::make_unique<EngineManager>();
std::unique_ptr<BrakeSysManager> brakesysmanager = std::make_unique<BrakeSysManager>();
std::unique_ptr<SteeringSysManager> steeringsysmanager = std::make_unique<SteeringSysManager>();
std::unique_ptr<TestSysManager> testsysmanager = std::make_unique<TestSysManager>();

std::pair<InputErrorCode, int> getUserInput();
void printCurrentStepScreen(int step);
void selectOption(int& step, int answer);
bool selectedGoBackOrInit(int answer, int& step);
bool isInputRangeValid(int step, int answer);


int main()
{
    
    int step = CarType_Q;
    while (1)
    {
        screenmanager->printCurrentStepScreen(step);

        auto [ErrorCode, answer] = getUserInput();

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

        if (selectedGoBackOrInit(answer, step)) {
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

bool selectedGoBackOrInit(int answer, int& step) {
    if (answer == 0) {
        if (step == Run_Test) {
            step = CarType_Q;
        }

        if (step > CarType_Q) {
            step -= 1;
        }
        return true;
    }
    return false;
}

void selectOption(int& step, int answer) {
    if (step == CarType_Q) {
        carmanager->selectType(answer);
        step = carmanager->getNextStep();
    }
    else if (step == Engine_Q) {
        enginemanager->selectType(answer);
        step = enginemanager->getNextStep();
    }
    else if (step == brakeSystem_Q) {
        brakesysmanager->selectType(answer);
        step = brakesysmanager->getNextStep();     
    }
    else if (step == SteeringSystem_Q) {
        steeringsysmanager->selectType(answer);
        step = steeringsysmanager->getNextStep();
    }
    else if (step == Run_Test) {
        std::vector<int> selectedOpt = { carmanager->getType(), enginemanager ->getType(), brakesysmanager->getType(), steeringsysmanager->getType()};
        testsysmanager->getSelectedOptions(selectedOpt);

        testsysmanager->selectType(answer);
        testsysmanager->doAction();
    }
}

bool isInputRangeValid(int step, int answer) {
    switch (step) {
    case CarType_Q:
        return carmanager->isValid(answer);
    case Engine_Q:
        return enginemanager->isValid(answer);
    case brakeSystem_Q:
        return brakesysmanager->isValid(answer);
    case SteeringSystem_Q:
        return steeringsysmanager->isValid(answer);
    case Run_Test:
        return testsysmanager->isValid(answer);
    default:
        printf("System Error.\n");
        return false;
    }
    return true;
}


#endif