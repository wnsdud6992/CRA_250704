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
	int test_userinput = 8;
	std::unique_ptr<ScreenManager> screenmanager = std::make_unique<ScreenManager>();
	std::unique_ptr<CarManager> carmanager = std::make_unique<CarManager>();
	std::unique_ptr<EngineManager> enginemanager = std::make_unique<EngineManager>();
	std::unique_ptr<BrakeSysManager> brakesysmanager = std::make_unique<BrakeSysManager>();
	std::unique_ptr<SteeringSysManager> steeringsysmanager = std::make_unique<SteeringSysManager>();
	std::unique_ptr<TestSysManager> testsysmanager = std::make_unique<TestSysManager>();
		
};

TEST_F(CarFactory_Fixture, Success_Sedan_GM_MAdo_Bosch) {
	screenmanager->printCurrentStepScreen(CarType_Q);
	EXPECT_TRUE(carmanager->isValid(SEDAN));
	carmanager->selectType(SEDAN);
	carmanager->getNextStep();

	screenmanager->printCurrentStepScreen(Engine_Q);
	EXPECT_TRUE(enginemanager->isValid(GM));
	enginemanager->selectType(GM);
	enginemanager->getNextStep();

	screenmanager->printCurrentStepScreen(brakeSystem_Q);
	EXPECT_TRUE(brakesysmanager->isValid(MANDO));
	brakesysmanager->selectType(MANDO);
	brakesysmanager->getNextStep();

	screenmanager->printCurrentStepScreen(SteeringSystem_Q);
	EXPECT_TRUE(steeringsysmanager->isValid(BOSCH_S));
	steeringsysmanager->selectType(BOSCH_S);
	steeringsysmanager->getNextStep();

	screenmanager->printCurrentStepScreen(Run_Test);
	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	EXPECT_TRUE(testsysmanager->isValid(CheckResult::RUN));
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

TEST_F(CarFactory_Fixture, Error_Sedan_Unable_Continental_Brake) {
	carmanager->selectType(SEDAN);
	enginemanager->selectType(TOYOTA);
	brakesysmanager->selectType(CONTINENTAL);
	steeringsysmanager->selectType(BOSCH_S);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Failed, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Sedan_Unable_Continental_Brake, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_SUV_Unable_Toyota_Engine) {
	carmanager->selectType(SUV);
	enginemanager->selectType(TOYOTA);
	brakesysmanager->selectType(CONTINENTAL);
	steeringsysmanager->selectType(BOSCH_S);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Failed, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::SUV_Unable_Toyota_Engine, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_Truck_Unable_Wia_Engine) {
	carmanager->selectType(TRUCK);
	enginemanager->selectType(WIA);
	brakesysmanager->selectType(CONTINENTAL);
	steeringsysmanager->selectType(BOSCH_S);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Failed, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Truck_Unable_Wia_Engine, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_Truck_Unable_Mando_Brake) {
	carmanager->selectType(TRUCK);
	enginemanager->selectType(GM);
	brakesysmanager->selectType(MANDO);
	steeringsysmanager->selectType(BOSCH_S);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Failed, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Truck_Unable_Mando_Brake, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_Bosch_Brake_Only_Able_Bosch_Steering) {
	carmanager->selectType(TRUCK);
	enginemanager->selectType(GM);
	brakesysmanager->selectType(BOSCH_B);
	steeringsysmanager->selectType(MOBIS);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Make_Failed, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Bosch_Brake_Only_Able_Bosch_Steering, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_Engine_Broken) {
	carmanager->selectType(SUV);
	enginemanager->selectType(BROKEN_ENGINE);
	brakesysmanager->selectType(CONTINENTAL);
	steeringsysmanager->selectType(MOBIS);

	std::vector<int> selectedOpt = { carmanager->getType(), enginemanager->getType(), brakesysmanager->getType(), steeringsysmanager->getType() };
	testsysmanager->getSelectedOptions(selectedOpt);

	testsysmanager->selectType(CheckResult::RUN);
	EXPECT_EQ(Result_ErrorCode::Engine_Broken, testsysmanager->doAction());

	testsysmanager->selectType(CheckResult::TEST);
	EXPECT_EQ(Result_ErrorCode::Make_Success, testsysmanager->doAction());
}

TEST_F(CarFactory_Fixture, Error_UserInput_Range) {
	EXPECT_FALSE(carmanager->isValid(test_userinput));
	EXPECT_FALSE(enginemanager->isValid(test_userinput));
	EXPECT_FALSE(brakesysmanager->isValid(test_userinput));
	EXPECT_FALSE(steeringsysmanager->isValid(test_userinput));
}