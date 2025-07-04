#pragma once
#include "TestSys.h"

class TestSysManager {
public:
	bool isValid(int select);

	void selectType(int select);

	void getSelectedOptions(std::vector<int>& options);

	Result_ErrorCode doAction();

private:
	std::vector<int> SelectedOptions;
	QuestionType q_type = QuestionType::SteeringSystem_Q;
	std::unique_ptr<ITestSys> testsys;
};