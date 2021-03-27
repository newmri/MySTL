#pragma once

#include "Vector.h"

template<typename T>
bool Vector<T>::Init(void)
{
	return SUCC;
}

template<typename T>
inline Vector<T>::~Vector()
{
	this->data.clear();
	this->data.reserve(0);
}

template<typename T>
void Vector<T>::push_back(const T Data)
{
	lock_guard<mutex> guard(this->lock);

	this->data.push_back(Data);
}

template<typename T>
void Vector<T>::pop_back(void)
{
	lock_guard<mutex> guard(this->lock);

	if(this->data.size())
		this->data.pop_back();
}

template<typename T>
void Vector<T>::reserve(const size_t uNewCapacity)
{
	lock_guard<mutex> guard(this->lock);

	this->data.reserve(uNewCapacity);
}

template<typename T>
void Vector<T>::clear(void)
{
	lock_guard<mutex> guard(this->lock);

	this->data.clear();
}

template<typename T>
size_t Vector<T>::size(void)
{
	lock_guard<mutex> guard(this->lock);

	return this->data.size();
}

template<typename T>
T Vector<T>::operator[](const size_t index)
{
	lock_guard<mutex> guard(this->lock);

	if (IS_VALID_RANGE(index, this->data.size()))
		return this->data[index];

	else
	{
		ERROR_LOG("index is invalid index: " << index << " len: " << this->data.size());
		return T();
	}
}