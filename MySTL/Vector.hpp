#pragma once

#include "Vector.h"

template<typename T>
bool Vector<T>::Init(void)
{
	return SUCC;
}

template<typename T>
void Vector<T>::push_back(const T Data)
{
	data.push_back(Data);
}

template<typename T>
void Vector<T>::pop_back(void)
{
	data.pop_back();
}

template<typename T>
void Vector<T>::reserve(const size_t uNewCapacity)
{
	data.reserve(uNewCapacity);
}

template<typename T>
void Vector<T>::clear(void)
{
	data.clear();
}

template<typename T>
size_t Vector<T>::size(void)
{
	return data.size();
}