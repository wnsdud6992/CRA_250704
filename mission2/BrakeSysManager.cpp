#include "BrakeSysManager.h"

bool BrakeSysManager::isValid(int select) {
	if (!(select > brakeSystem::NONE_BREAKSYS && select < brakeSystem::MAX_BREAKSYS_TYPE)) {
		printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
		return false;
	}
	return true;
}

void BrakeSysManager::selectType(int select) {
	brakeSystem type = static_cast<brakeSystem>(select);
	switch (type) {
	case brakeSystem::MANDO:
		printf("MANDO 제동장치를 선택하셨습니다.\n");
		brakesys = std::make_unique<Mando>();
		break;
	case brakeSystem::CONTINENTAL:
		printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
		brakesys = std::make_unique<Continetial>();
		break;
	case brakeSystem::BOSCH_B:
		printf("BOSCH 제동장치를 선택하셨습니다.\n");
		brakesys = std::make_unique<Bosch_b>();
		break;
	}
}

int BrakeSysManager::getNextStep() {
	delay(800);
	return static_cast<int>(q_type) + 1;
}

brakeSystem BrakeSysManager::getType() {
	return brakesys->getType();
}