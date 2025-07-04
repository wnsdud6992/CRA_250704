#pragma once
#include "Common.h"

class ICar {
public:
	virtual CarType getType() = 0;
};

class Sedan : public ICar {
public:
	CarType getType() override {
		return CarType::SEDAN;
	}
};

class Suv : public ICar {
public:
	CarType getType() override {
		return CarType::SUV;
	}
};

class Truck : public ICar {
public:
	CarType getType() override {
		return CarType::TRUCK;
	}
};