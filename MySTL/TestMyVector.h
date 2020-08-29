#pragma once

#include "Test.h"

class CTestMyVector : public CTest
{
public:
	virtual void Do(const size_t uTestNum = TEST_VECTOR_NUMBER) override;
};
