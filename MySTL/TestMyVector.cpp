#pragma once

#include "Global.h"

void CTestMyVector::Do(const size_t uTestNum)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();

	for (size_t i = 0; i < uTestNum; ++i)
	{
	}

	chrono::duration<double> sec = chrono::system_clock::now() - start;

	std::cout << "PushBack() �Լ��� �����ϴ� �ɸ� �ð�(��) : " << sec.count() << " seconds" << std::endl;

}