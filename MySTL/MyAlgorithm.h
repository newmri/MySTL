#pragma once

template<typename T>
void Swap(T& rLeft, T& rRight);

template<typename T>
bool AscendingOrder(const T& rLeft, const T& rRight);

template<typename T>
bool DescendingOrder(const T& rLeft, const T& rRight);

template<typename T, typename FUNC = bool(*)(const T&, const T&)>
void BubbleSort(T* pStart, T* pEnd, FUNC Compare);

template<typename T>
void BubbleSort(T* pStart, T* pEnd);

#include "MyAlgorithm.hpp"