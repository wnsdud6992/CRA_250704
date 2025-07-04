#pragma once
#include "Common.h"

class ITestSys {
public:
	virtual Result_ErrorCode doAction(const std::vector<int> &options) = 0;
};

class Test : public ITestSys {
public:
    Result_ErrorCode doAction(const std::vector<int>& options) override;
};

class Run : public ITestSys {
public:
    Result_ErrorCode doAction(const std::vector<int>& options) override;
        
private:
    int isValidCheck(const std::vector<int>& options);
};

