#include "TestSys.h"

Result_ErrorCode Test::doAction(const std::vector<int>& options) {
    printf("Test...\n");
    delay(1500);

    if (options[CarType_Q] == SEDAN && options[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
        delay(2000);
        return Result_ErrorCode::Sedan_Unable_Continental_Brake;
    }
    else if (options[CarType_Q] == SUV && options[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
        delay(2000);
        return Result_ErrorCode::SUV_Unable_Toyota_Engine;
    }
    else if (options[CarType_Q] == TRUCK && options[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
        delay(2000);
        return Result_ErrorCode::Truck_Unable_Wia_Engine;
    }
    else if (options[CarType_Q] == TRUCK && options[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
        delay(2000);
        return Result_ErrorCode::Truck_Unable_Mando_Brake;
    }
    else if (options[brakeSystem_Q] == BOSCH_B && options[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        delay(2000);
        return Result_ErrorCode::Bosch_Brake_Only_Able_Bosch_Steering;
    }
    printf("자동차 부품 조합 테스트 결과 : PASS\n");
    delay(2000);
    return Result_ErrorCode::Make_Success;
}


Result_ErrorCode Run::doAction(const std::vector<int>& options) {
    if (isValidCheck(options) == false)
    {
        printf("자동차가 동작되지 않습니다\n");
        delay(2000);
        return Result_ErrorCode::Make_Failed;
    }
    else
    {
        if (options[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
            delay(2000);
            return Result_ErrorCode::Engine_Broken;
        }
        else
        {
            if (options[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (options[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (options[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (options[Engine_Q] == 1)
                printf("Engine : GM\n");
            if (options[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (options[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (options[brakeSystem_Q] == 1)
                printf("Brake System : Mando");
            if (options[brakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (options[brakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (options[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (options[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
            delay(2000);
            return Result_ErrorCode::Make_Success;
        }
    }

}

int Run::isValidCheck(const std::vector<int>& options)
{
    if (options[CarType_Q] == SEDAN && options[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (options[CarType_Q] == SUV && options[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (options[CarType_Q] == TRUCK && options[Engine_Q] == WIA)
    {
        return false;
    }
    else if (options[CarType_Q] == TRUCK && options[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (options[brakeSystem_Q] == BOSCH_B && options[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    return true;
}