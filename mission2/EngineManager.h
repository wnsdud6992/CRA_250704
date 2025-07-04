#pragma once
#include "Engine.h"

class EngineManager {
public:
	bool isValid(int select);

	void selectType(int select);

	int getNextStep();

	Engine getType();

private:
	QuestionType q_type = QuestionType::Engine_Q;
	std::unique_ptr<IEngine> engine;
};