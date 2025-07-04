#pragma once
#include "Common.h"

class IBrakeSys {
public:
	virtual brakeSystem getType() = 0;
};

class Mando : public IBrakeSys {
public:
	brakeSystem getType() override {
		return brakeSystem::MANDO;
	}
};

class Continetial : public IBrakeSys {
public:
	brakeSystem getType() override {
		return brakeSystem::CONTINENTAL;
	}
};

class Bosch_b : public IBrakeSys {
public:
	brakeSystem getType() override {
		return brakeSystem::BOSCH_B;
	}
};