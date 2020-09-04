#pragma once

#include "MyVector.h"

template<typename T>
bool CMyVector<T>::Init(void)
{
	return SUCC;
}

template<typename T>
CMyVector<T>::CMyVector(const size_t uCapacity, const size_t uIncreaseCapacity)
{
	this->m_uSize = sizeof(T);

	if (IS_UNDER_ONE(uIncreaseCapacity))
	{
		ERROR_LOG("uIncreaseCapacity is " << uIncreaseCapacity);
		m_uIncreaseCapacity = VECTOR_INCREASE_CAPACITY;
		ERROR_LOG("m_uIncreaseCapacity is Changed To " << m_uIncreaseCapacity);
	}

	else m_uIncreaseCapacity = uIncreaseCapacity;
	
	AllocMemory(uCapacity);
}

template<typename T>
CMyVector<T>::~CMyVector()
{
	clear();
}

template<typename T>
void CMyVector<T>::push_back(const T Data)
{
	if (this->m_uLen == m_uCapacity && ReAllocMemory(m_uCapacity * m_uIncreaseCapacity)) return;

	m_pData[this->m_uLen++] = Data;
}

template<typename T>
void CMyVector<T>::pop_back(void)
{
	--this->m_uLen;
}

template<typename T>
void CMyVector<T>::reserve(const size_t uNewCapacity)
{
	ReAllocMemory(uNewCapacity);
}

template<typename T>
void CMyVector<T>::clear(void)
{
	SAFE_DELETE_ARRAY(m_pData);
	this->m_uLen = 0;
}

template<typename T>
size_t CMyVector<T>::size(void)
{
	return this->m_uLen;
}

template<typename T>
T CMyVector<T>::operator[](const size_t uIndex)
{
	if (IS_VALID_RANGE(uIndex, this->m_uLen)) return m_pData[uIndex];

	else
	{
		ERROR_LOG("uIndex is invalid uIndex: " << uIndex << " m_uLen: " << this->m_uLen);
		return T();
	}
}


template<typename T>
bool CMyVector<T>::AllocMemory(const size_t uCapacity)
{
	if (IS_ZERO(uCapacity))
	{
		ERROR_LOG("uCapacity is " << uCapacity);
		m_uCapacity = VECTOR_DEFAULT_CAPACITY;
		ERROR_LOG("m_uCapacity is Changed To " << m_uCapacity);
	}

	else m_uCapacity = uCapacity;

	return GET_INSTANCE(CMemoryManager).AllocMemory((void**)&m_pData, this->m_uSize * m_uCapacity);
}

template<typename T>
bool CMyVector<T>::ReAllocMemory(const size_t uNewCapacity)
{
	if (m_uCapacity >= uNewCapacity)
	{
		ERROR_LOG("m_uCapacity " << m_uCapacity << " >= uNewCapacity " << uNewCapacity);
		return FAIL;
	}

	if (GET_INSTANCE(CMemoryManager).ReAllocMemory((void**)&m_pData, this->m_uSize * m_uCapacity, this->m_uSize * uNewCapacity))
		return FAIL;

	m_uCapacity = uNewCapacity;

	return SUCC;
}
