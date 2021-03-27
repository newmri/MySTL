#pragma once

#include "MyVector.h"

template<typename T>
bool MyVector<T>::Init(void)
{
	return SUCC;
}

template<typename T>
MyVector<T>::MyVector(const size_t capacity, const size_t increaseCapacity)
{
	this->dataSize = sizeof(T);

	if (IS_UNDER_ONE(increaseCapacity))
	{
		ERROR_LOG("increaseCapacity is " << increaseCapacity);
		this->increaseCapacity = VECTOR_INCREASE_CAPACITY;
		ERROR_LOG("this->increaseCapacity is Changed To " << this->increaseCapacity);
	}

	else this->increaseCapacity = increaseCapacity;
	
	AllocMemory(capacity);
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	lock_guard<mutex> guard(this->lock);

	GET_INSTANCE(MemoryManager).DeAllocMemory((void**)&this->data, this->capacity);

	this->data = nullptr;
	this->len = 0;
	this->capacity = 0;
}

template<typename T>
void MyVector<T>::push_back(const T data)
{
	lock_guard<mutex> guard(this->lock);

	if (this->len == this->capacity)
	{
		if(ReAllocMemory(this->capacity * this->increaseCapacity))
			return;
	}

	this->data[this->len++] = data;
}

template<typename T>
void MyVector<T>::pop_back(void)
{
	lock_guard<mutex> guard(this->lock);

	if (this->len)
		--this->len;
}

template<typename T>
void MyVector<T>::reserve(const size_t newCapacity)
{
	lock_guard<mutex> guard(this->lock);

	ReAllocMemory(newCapacity);
}

template<typename T>
void MyVector<T>::clear(void)
{
	lock_guard<mutex> guard(this->lock);

	this->len = 0;
}

template<typename T>
size_t MyVector<T>::size(void)
{
	lock_guard<mutex> guard(this->lock);

	return this->len;
}

template<typename T>
T MyVector<T>::operator[](const size_t index)
{
	lock_guard<mutex> guard(this->lock);

	if (IS_VALID_RANGE(index, this->len))
		return this->data[index];

	else
	{
		ERROR_LOG("index is invalid index: " << index << " len: " << this->len);
		return T();
	}
}


template<typename T>
bool MyVector<T>::AllocMemory(const size_t capacity)
{
	if (IS_ZERO(capacity))
	{
		ERROR_LOG("capacity is " << this->capacity);
		this->capacity = VECTOR_DEFAULT_CAPACITY;
		ERROR_LOG("capacity is Changed To " << capacity);
	}

	else
		this->capacity = capacity;

	return GET_INSTANCE(MemoryManager).AllocMemory((void**)&this->data, this->dataSize * this->capacity);
}

template<typename T>
bool MyVector<T>::ReAllocMemory(const size_t newCapacity)
{
	if (this->capacity >= newCapacity)
	{
		return FAIL;
	}

	if (GET_INSTANCE(MemoryManager).ReAllocMemory((void**)&this->data, this->dataSize * this->capacity, this->dataSize * newCapacity))
		return FAIL;

	this->capacity = newCapacity;

	return SUCC;
}
