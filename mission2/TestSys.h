#pragma once
#include "Common.h"

class ITestSys {
public:
	virtual CheckResult getType() = 0;
	virtual Result_ErrorCode doAction(const std::vector<int> &options) = 0;
};

class Test : public ITestSys {
public:
    CheckResult getType() override;
    Result_ErrorCode doAction(const std::vector<int>& options) override;
};

class Run : public ITestSys {
public:
    CheckResult getType() override;
    Result_ErrorCode doAction(const std::vector<int>& options) override;
        
private:
    int isValidCheck(const std::vector<int>& options);
};

