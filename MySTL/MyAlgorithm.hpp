#pragma once

#include "MyAlgorithm.h"

template<typename T>
void Swap(T& left, T& right)
{
	T leftBackup = left;
	left = right;
	right = leftBackup;
}

template<typename T>
bool AscendingOrder(const T& left, const T& right)
{
	return (left > right);
}

template<typename T>
bool DescendingOrder(const T& left, const T& right)
{
	return (left < right);
}

template<typename T>
size_t GetLen(T* start, T* end)
{
	if (start >= end)
	{
		ERROR_LOG("start " << start << " is Greater than end or Same " << end);
		return FALSE;
	}

	return (end - start);
}

template<typename T, typename FUNC>
void BubbleSort(T* start, T* end, FUNC Compare)
{
	size_t len = GetLen(start, end);

	if (FALSE == len) return;

	for (size_t i = 0; i < len; ++i)
	{
		for (size_t j = 0; j < len - i - 1; ++j)
		{
			if (Compare(start[j], start[j + 1]))
				Swap(start[j], start[j + 1]);
		}
	}
}

template<typename T>
void BubbleSort(T* start, T* end)
{
	BubbleSort(start, end, AscendingOrder);
}

template<typename T, typename FUNC>
void SelectionSort(T* start, T* end, FUNC Compare)
{
	size_t len = GetLen(start, end);

	if (FALSE == len) return;

	size_t targetIndex = 0;

	for (size_t i = 0; i < len - 1; ++i)
	{
		targetIndex = i;

		for (size_t j = i + 1; j < len; ++j)
		{
			if (Compare(start[targetIndex], start[j]))
				targetIndex = j;
		}

		if (i != targetIndex)
		{
			Swap(start[i], start[targetIndex]);
		}
	}
}

template<typename T>
void SelectionSort(T* start, T* end)
{
	SelectionSort(start, end, AscendingOrder);
}

template<typename T, typename FUNC>
void InsertionSort(T* start, T* end, FUNC Compare)
{
	size_t len = GetLen(start, end);

	if (FALSE == len)
		return;

	size_t targetIndex;

	T target;

	for (size_t i = 1; i < len; ++i)
	{
		target = start[i];

		for (targetIndex = i; targetIndex > 0; --targetIndex)
		{
			if (Compare(start[targetIndex - 1], target))
				start[targetIndex] = start[targetIndex - 1];

			else
				break;
		}

		start[targetIndex] = target;
	}
}

template<typename T>
void InsertionSort(T* start, T* end)
{
	InsertionSort(start, end, AscendingOrder);
}