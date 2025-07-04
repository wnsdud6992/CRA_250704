#pragma once
#include "Common.h"
#include "BrakeSys.h"

class BrakeSysManager {
public:
	bool isValid(int select);
	void selectType(int select);
	int getNextStep();
	brakeSystem getType();

private:
	QuestionType q_type = QuestionType::brakeSystem_Q;
	std::unique_ptr<IBrakeSys> brakesys;
};