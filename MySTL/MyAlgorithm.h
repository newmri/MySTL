#pragma once

template<typename T>
void Swap(T& left, T& right);

template<typename T>
bool AscendingOrder(const T& left, const T& right);

template<typename T>
bool DescendingOrder(const T& left, const T& right);

template<typename T>
size_t GetLen(T* start, T* end);

template<typename T, typename FUNC = bool(*)(const T&, const T&)>
void BubbleSort(T* start, T* end, FUNC Compare);

template<typename T>
void BubbleSort(T* start, T* end);

template<typename T, typename FUNC = bool(*)(const T&, const T&)>
void SelectionSort(T* start, T* end, FUNC Compare);

template<typename T>
void SelectionSort(T* start, T* end);

template<typename T, typename FUNC = bool(*)(const T&, const T&)>
void InsertionSort(T* start, T* end, FUNC Compare);

template<typename T>
void InsertionSort(T* start, T* end);

#include "MyAlgorithm.hpp"