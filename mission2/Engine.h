#pragma once
#include "Common.h"

class IEngine {
public:
	virtual Engine getType() = 0;
};

class Gm : public IEngine {
public:
	Engine getType() override {
		return Engine::GM;
	}
};

class Toyota : public IEngine {
public:
	Engine getType() override {
		return Engine::TOYOTA;
	}
};

class Wia : public IEngine {
public:
	Engine getType() override {
		return Engine::WIA;
	}
};