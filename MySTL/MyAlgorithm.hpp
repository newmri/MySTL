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

template<typename T, typename FUNC>
void BubbleSort(T* pStart, T* pEnd, FUNC Compare)
{
	if (pStart >= pEnd)
	{
		ERROR_LOG("pStart " << pStart << " is Greater than pEnd or Same " << pEnd);
		return;
	}

	size_t uLen = pEnd - pStart;

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