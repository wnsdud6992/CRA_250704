#pragma once
#include "Common.h"
#include "SteeringSys.h"

class SteeringSysManager {
public:
	bool isValid(int select) {
		if (!(select > SteeringSystem::NONE_STEERING && select < SteeringSystem::MAX_STEERINGSYS_TYPE)) {
			printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
			return false;
		}
		return true;
	}

	void selectType(int select) {
		SteeringSystem type = static_cast<SteeringSystem>(select);
		switch (type) {
		case SteeringSystem::BOSCH_S:
			printf("BOSCH 조향장치를 선택하셨습니다.\n");
			steeringsys = std::make_unique<Bosch_s>();
			break;
		case SteeringSystem::MOBIS:
			printf("MOBIS 조향장치를 선택하셨습니다.\n");
			steeringsys = std::make_unique<Mobis>();
			break;
		}
	}

	int getNextStep() {
		delay(800);
		return static_cast<int>(q_type) + 1;
	}

	SteeringSystem getType() {
		return steeringsys->getType();
	}

private:
	QuestionType q_type = QuestionType::SteeringSystem_Q;
	std::unique_ptr<ISteeringSys> steeringsys;
};