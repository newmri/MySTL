#pragma once

#include "MyAlgorithm.h"

template<typename T>
void Swap(T& rLeft, T& rRight)
{
	T LeftBackup = rLeft;
	rLeft = rRight;
	rRight = LeftBackup;
}

template<typename T>
bool AscendingOrder(const T& rLeft, const T& rRight)
{
	return (rLeft > rRight);
}

template<typename T>
bool DescendingOrder(const T& rLeft, const T& rRight)
{
	return (rLeft < rRight);
}

template<typename T>
size_t GetLen(T* pStart, T* pEnd)
{
	if (pStart >= pEnd)
	{
		ERROR_LOG("pStart " << pStart << " is Greater than pEnd or Same " << pEnd);
		return FALSE;
	}

	return (pEnd - pStart);
}

template<typename T, typename FUNC>
void BubbleSort(T* pStart, T* pEnd, FUNC Compare)
{
	size_t uLen = GetLen(pStart, pEnd);

	if (FALSE == uLen) return;

	for (size_t i = 0; i < uLen; ++i)
	{
		for (size_t j = 0; j < uLen - i - 1; ++j)
		{
			if (Compare(pStart[j], pStart[j + 1]))
			{
				Swap(pStart[j], pStart[j + 1]);
			}
		}
	}
}

template<typename T>
void BubbleSort(T* pStart, T* pEnd)
{
	BubbleSort(pStart, pEnd, AscendingOrder);
}

template<typename T, typename FUNC>
void SelectionSort(T* pStart, T* pEnd, FUNC Compare)
{
	size_t uLen = GetLen(pStart, pEnd);

	if (FALSE == uLen) return;

	size_t uTargetIndex = 0;

	for (size_t i = 0; i < uLen - 1; ++i)
	{
		uTargetIndex = i;

		for (size_t j = i + 1; j < uLen; ++j)
		{
			if (Compare(pStart[uTargetIndex], pStart[j]))
			{
				uTargetIndex = j;
			}
		}

		if (i != uTargetIndex)
		{
			Swap(pStart[i], pStart[uTargetIndex]);
		}
	}
}

template<typename T>
void SelectionSort(T* pStart, T* pEnd)
{
	SelectionSort(pStart, pEnd, AscendingOrder);
}