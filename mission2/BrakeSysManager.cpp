#include "BrakeSysManager.h"

bool BrakeSysManager::isValid(int select) {
	if (!(select > brakeSystem::NONE_BREAKSYS && select < brakeSystem::MAX_BREAKSYS_TYPE)) {
		printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
		return false;
	}
	return true;
}

void BrakeSysManager::selectType(int select) {
	brakeSystem type = static_cast<brakeSystem>(select);
	switch (type) {
	case brakeSystem::MANDO:
		printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
		brakesys = std::make_unique<Mando>();
		break;
	case brakeSystem::CONTINENTAL:
		printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
		brakesys = std::make_unique<Continetial>();
		break;
	case brakeSystem::BOSCH_B:
		printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
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