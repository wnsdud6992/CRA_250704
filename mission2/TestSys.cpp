#include "TestSys.h"

Result_ErrorCode Test::doAction(const std::vector<int>& options) {
    printf("Test...\n");
    delay(1500);

    if (options[CarType_Q] == SEDAN && options[brakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        delay(2000);
        return Result_ErrorCode::Sedan_Unable_Continental_Brake;
    }
    else if (options[CarType_Q] == SUV && options[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        delay(2000);
        return Result_ErrorCode::SUV_Unable_Toyota_Engine;
    }
    else if (options[CarType_Q] == TRUCK && options[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
        delay(2000);
        return Result_ErrorCode::Truck_Unable_Wia_Engine;
    }
    else if (options[CarType_Q] == TRUCK && options[brakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
        delay(2000);
        return Result_ErrorCode::Truck_Unable_Mando_Brake;
    }
    else if (options[brakeSystem_Q] == BOSCH_B && options[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        delay(2000);
        return Result_ErrorCode::Bosch_Brake_Only_Able_Bosch_Steering;
    }
    printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    delay(2000);
    return Result_ErrorCode::Make_Success;
}


Result_ErrorCode Run::doAction(const std::vector<int>& options) {
    if (isValidCheck(options) == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        delay(2000);
        return Result_ErrorCode::Make_Failed;
    }
    else
    {
        if (options[Engine_Q] == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

            printf("�ڵ����� ���۵˴ϴ�.\n");
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