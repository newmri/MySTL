#pragma once

#include "MySTL.h"

// 기본 벡터 사이즈 할당량
static const size_t VECTOR_DEFAULT_CAPACITY = 2;
// 기본 벡터 사이즈 풀일 때 사이즈 상승 배수 EX) 2: 2배 5: 5배, 현재의 사이즈의 배수.
static const size_t VECTOR_INCREASE_CAPACITY = 2;

template<typename T>
class MyVector : public MySTL<T>
{
public:
	virtual bool Init(void) override;

public:
	MyVector(const size_t capacity = VECTOR_DEFAULT_CAPACITY, const size_t increaseCapacity = VECTOR_INCREASE_CAPACITY);
	~MyVector();

public:
	virtual void push_back(const T data) override;
	virtual void pop_back(void) override;
	virtual void reserve(const size_t newCapacity) override;
	virtual void clear(void) override;
	virtual size_t size(void) override;
	virtual T operator[](const size_t index) override;

private:
	bool AllocMemory(const size_t capacity);
	bool ReAllocMemory(const size_t newCapacity);

private:
	size_t capacity = 0;
	size_t increaseCapacity = 0;
	T* data = nullptr;
	mutex lock;
};

#include "MyVector.hpp"