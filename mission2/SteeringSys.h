#pragma once
#include "Common.h"

class ISteeringSys {
public:
	virtual SteeringSystem getType() = 0;
};

class Bosch_s : public ISteeringSys {
public:
	SteeringSystem getType() override {
		return SteeringSystem::BOSCH_S;
	}
};

class Mobis : public ISteeringSys {
public:
	SteeringSystem getType() override {
		return SteeringSystem::MOBIS;
	}
};

