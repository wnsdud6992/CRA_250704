#pragma once
#include "Common.h"
#include "Car.h"

class CarManager {
public:
	bool isValid(int select);
	void selectType(int select);
	int getNextStep();
	CarType getType();

private:
	QuestionType q_type = QuestionType::CarType_Q;
	std::unique_ptr<ICar> Car;
};