#pragma once
#include "Common.h"
#include "Car.h"

class CarManager {
public:
	bool isValid(int select) {
		if (!(select > CarType::NONE_CAR && select < CarType::MAX_CAR_TYPE)) {
			printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
			return false;
		}
		return true;
	}

	void selectType(int select) {
		CarType type = static_cast<CarType>(select);
		switch(type) {
		case CarType::SEDAN:
			printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
			Car = std::make_unique<Sedan>();
			break;
		case CarType::SUV:
			printf("차량 타입으로 SUV을 선택하셨습니다.\n");
			Car = std::make_unique<Suv>();
			break;
		case CarType::TRUCK:
			printf("차량 타입으로 Truck을 선택하셨습니다.\n");
			Car = std::make_unique<Truck>();
			break;
		}
	}

	int getNextStep() {
		delay(800);
		return static_cast<int>(q_type) + 1;
	}

	CarType getType()  {
		return Car->getType();
	}

private:
	QuestionType q_type = QuestionType::CarType_Q;
	std::unique_ptr<ICar> Car;
};