#pragma once

#include "MySTL.h"

// 기본 벡터 사이즈 할당량
static const size_t VECTOR_DEFAULT_CAPACITY = 2;
// 기본 벡터 사이즈 풀일 때 사이즈 상승 배수 EX) 2: 2배 5: 5배, 현재의 사이즈의 배수.
static const size_t VECTOR_INCREASE_CAPACITY = 10;

template<typename T>
class CMyVector : public CMySTL<T>
{
public:
	virtual bool Init(void) override;

public:
	CMyVector(const size_t uCapacity = VECTOR_DEFAULT_CAPACITY, const size_t uIncreaseCapacity = VECTOR_INCREASE_CAPACITY);
	~CMyVector();

public:
	virtual void push_back(const T Data) override;
	virtual void pop_back(void) override;
	virtual void reserve(const size_t uNewCapacity) override;
	virtual void clear(void) override;
	virtual size_t size(void) override;

public:
	T operator[](const size_t uIndex);

private:
	bool AllocMemory(const size_t uCapacity);
	bool ReAllocMemory(const size_t uNewCapacity);

private:
	size_t m_uCapacity = 0;
	size_t m_uIncreaseCapacity = 0;
	T* m_pData = nullptr;
};

#include "MyVector.hpp"