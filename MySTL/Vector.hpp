#pragma once

#include "Vector.h"

template<typename T>
bool CVector<T>::Init(void)
{
	return SUCC;
}

template<typename T>
void CVector<T>::push_back(const T Data)
{
	m_vData.push_back(Data);
}

template<typename T>
void CVector<T>::pop_back(void)
{
	m_vData.pop_back();
}

template<typename T>
void CVector<T>::reserve(const size_t uNewCapacity)
{
	m_vData.reserve(uNewCapacity);
}

template<typename T>
void CVector<T>::clear(void)
{
	m_vData.clear();
}

template<typename T>
size_t CVector<T>::size(void)
{
	return m_vData.size();
}