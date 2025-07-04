#pragma once
#include "TestSys.h"

class TestSysManager {
public:
	bool isValid(int select) {
		if (!(select >= CheckResult::INIT && select < CheckResult::MAX_CHECK_TYPE)) {
			printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
			return false;
		}
		return true;
	}

	void selectType(int select) {
		CheckResult type = static_cast<CheckResult>(select);
		switch (type) {
		case CheckResult::TEST:
			testsys = std::make_unique<Test>();
			break;
		case CheckResult::RUN:
			testsys = std::make_unique<Run>();
			break;
		}
	}

	void getSelectedOptions(std::vector<int> &options) {
		SelectedOptions = std::move(options);
	}

	Result_ErrorCode doAction() {
		return testsys->doAction(SelectedOptions);
	}

	CheckResult getType() {
		return testsys->getType();
	}

private:
	std::vector<int> SelectedOptions;
	QuestionType q_type = QuestionType::SteeringSystem_Q;
	std::unique_ptr<ITestSys> testsys;
};