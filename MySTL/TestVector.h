#pragma once

#include "Test.h"

class CTestVector : public CTest
{
public:
	virtual void Do(const size_t uTestNum = TEST_VECTOR_NUMBER) override;
};