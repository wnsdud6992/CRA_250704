#include "gmock/gmock.h"
#include "Common.h"
#include "ScreenManager.h"
#include "CarManager.h"
#include "EngineManager.h"
#include "BrakeSysManager.h"
#include "SteeringSysManager.h"
#include "TestSysManager.h"

class CarFactory_Fixture : public ::testing::Test {
public:
	std::unique_ptr<ScreenManager> screenmanager = std::make_unique<ScreenManager>();
	std::unique_ptr<CarManager> carmanager = std::make_unique<CarManager>();
	std::unique_ptr<EngineManager> enginemanager = std::make_unique<EngineManager>();
	std::unique_ptr<BrakeSysManager> brakesysmanager = std::make_unique<BrakeSysManager>();
	std::unique_ptr<SteeringSysManager> steeringsysmanager = std::make_unique<SteeringSysManager>();
	std::unique_ptr<TestSysManager> testsysmanager = std::make_unique<TestSysManager>();
		
};

TEST_F(CarFactory_Fixture, Success_Sedan_GM_MAdo_Bosch) {
	screenmanager->printCurrentStepScreen(CarType_Q);
	carmanager->selectType(SEDAN);
	carmanager->getNextStep();

	screenmanager->printCurrentStepScreen(Engine_Q);
	enginemanager->selectType(GM);
	enginemanager->getNextStep();

	screenmanager->printCurrentStepScreen(brakeSystem_Q);
	brakesysmanager->selectType(MANDO);
	brakesysmanager->getNextStep();

	screenmanager->printCurrentStepScreen(SteeringSystem_Q);
	steeringsysmanager->selectType(BOSCH_S);
	steeringsysmanager->getNextStep();

	screenmanager->printCurrentStepScreen(Run_Test);
	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Success_SUV_WIA_Continential_Mobis) {
	carmanager->selectType(SUV);
	enginemanager->selectType(WIA);
	brakesysmanager->selectType(CONTINENTAL);
	steeringsysmanager->selectType(MOBIS);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Success_TRUCK_Toyota_BoschB_BoschS) {
	carmanager->selectType(TRUCK);
	enginemanager->selectType(TOYOTA);
	brakesysmanager->selectType(BOSCH_B);
	steeringsysmanager->selectType(BOSCH_S);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());
}