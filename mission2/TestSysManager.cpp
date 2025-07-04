#include "TestSysManager.h"

bool TestSysManager::isValid(int select) {
	if (!(select >= CheckResult::INIT && select < CheckResult::MAX_CHECK_TYPE)) {
		printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
		return false;
	}
	return true;
}

void TestSysManager::selectType(int select) {
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

void TestSysManager::getSelectedOptions(std::vector<int>& options) {
	SelectedOptions = std::move(options);
}

Result_ErrorCode TestSysManager::doAction() {
	return testsys->doAction(SelectedOptions);
}