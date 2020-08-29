#pragma once

#include "TestVector.h"

template<typename T>
void CTestVector<T>::Do(const size_t uTestNum)
{
	chrono::system_clock::time_point start = chrono::system_clock::now();

	for (size_t i = 0; i < uTestNum; ++i)
	{
		T t();
		m_vData.push_back(1);
	}

	chrono::duration<double> sec = chrono::system_clock::now() - start;

	std::cout << "PushBack() 함수를 수행하는 걸린 시간(초) : " << sec.count() << " seconds" << std::endl;

}