#include "SteeringSysManager.h"

bool SteeringSysManager::isValid(int select) {
	if (!(select > SteeringSystem::NONE_STEERING && select < SteeringSystem::MAX_STEERINGSYS_TYPE)) {
		printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
		return false;
	}
	return true;
}

void SteeringSysManager::selectType(int select) {
	SteeringSystem type = static_cast<SteeringSystem>(select);
	switch (type) {
	case SteeringSystem::BOSCH_S:
		printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
		steeringsys = std::make_unique<Bosch_s>();
		break;
	case SteeringSystem::MOBIS:
		printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
		steeringsys = std::make_unique<Mobis>();
		break;
	}
}

int SteeringSysManager::getNextStep() {
	delay(800);
	return static_cast<int>(q_type) + 1;
}

SteeringSystem SteeringSysManager::getType() {
	return steeringsys->getType();
}