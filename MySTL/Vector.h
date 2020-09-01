#pragma once

#include "MySTL.h"

template<typename T>
class CVector : public CMySTL<T>
{
public:
	virtual bool Init(void) override;

public:
	virtual void push_back(const T Data) override;
	virtual void pop_back(void) override;
	virtual void reserve(const size_t uNewCapacity) override;
	virtual void clear(void) override;
	virtual size_t size(void) override;

private:
	vector<T> m_vData;
};

#include "Vector.hpp"