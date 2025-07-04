#include "EngineManager.h"

bool EngineManager::isValid(int select) {
	if (!(select > Engine::NONE_ENGINE && select < Engine::MAX_ENGINE_TYPE)) {
		printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
		return false;
	}
	return true;
}

void EngineManager::selectType(int select) {
	Engine type = static_cast<Engine>(select);
	switch (type) {
	case Engine::GM:
		printf("GM 엔진을 선택하셨습니다.\n");
		engine = std::make_unique<Gm>();
		break;
	case Engine::TOYOTA:
		printf("TOYOTA 엔진을 선택하셨습니다.\n");
		engine = std::make_unique<Toyota>();
		break;
	case Engine::WIA:
		printf("WIA 엔진을 선택하셨습니다.\n");
		engine = std::make_unique<Wia>();
		break;
	case Engine::BROKEN_ENGINE:
		printf("고장난 엔진을 선택하셨습니다.\n");
		engine = std::make_unique<BrokenEngine>();
		break;
	}
}

int EngineManager::getNextStep() {
	delay(800);
	return static_cast<int>(q_type) + 1;
}

Engine EngineManager::getType() {
	return engine->getType();
}