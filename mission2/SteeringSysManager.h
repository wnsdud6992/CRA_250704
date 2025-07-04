#pragma once
#include "Common.h"
#include "SteeringSys.h"

class SteeringSysManager {
public:
	bool isValid(int select);

	void selectType(int select);

	int getNextStep();

	SteeringSystem getType();

private:
	QuestionType q_type = QuestionType::SteeringSystem_Q;
	std::unique_ptr<ISteeringSys> steeringsys;
};