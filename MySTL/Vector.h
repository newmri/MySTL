#pragma once

#include "MySTL.h"

template<typename T>
class Vector : public MySTL<T>
{
public:
	virtual bool Init(void) override;
	~Vector();

public:
	virtual void push_back(const T Data) override;
	virtual void pop_back(void) override;
	virtual void reserve(const size_t uNewCapacity) override;
	virtual void clear(void) override;
	virtual size_t size(void) override;
	virtual T operator[](const size_t index) override;

private:
	vector<T> data;
	mutex lock;
};

#include "Vector.hpp"