#include "Global.h"

IMPLEMENT_SINGLETON(MemoryManager)

bool MemoryManager::Init(void)
{
	return SUCC; 
}

bool MemoryManager::AllocMemory(void** data, const size_t size)
{
	if (FALSE == CanAllocMemory(data, size))
		return FAIL;

	try
	{
		*data = new char[size];
		memset(*data, 0, size);
	}

	catch (bad_alloc& badalloc)
	{
		ERROR_LOG("bad_alloc reason: " << badalloc.what());
		return FAIL;
	}

	return SUCC;
}

bool MemoryManager::ReAllocMemory(void** data, const size_t currSize, const size_t newSize)
{
	if (FALSE == CanReAllocMemory(data, currSize, newSize))
		return FAIL;

	void* newData = nullptr;

	// 새로운 데이터를 담을 메모리 할당
	if (AllocMemory((void**)&newData, newSize))
		return FAIL;

	// 데이터 복사
	memcpy_s(newData, newSize, *data, currSize);

	// 현재 메모리 삭제
	DeAllocMemory(data, currSize);

	// 새로운 포인터를 가리키자.
	*data = newData;

	return SUCC;
}

void MemoryManager::DeAllocMemory(void** data, const size_t size)
{
	if (!CanDeAllocMemory(data, size))
		return;

	if (1 == size)
	{
		SAFE_DELETE(*data);
	}

	else
	{
		SAFE_DELETE_ARRAY(*data);
	}
}

bool MemoryManager::CanDeAllocMemory(void** data, const size_t size)
{
	if (IS_NULL(*data))
	{
		ERROR_LOG("data is nullptr");
		return FALSE;
	}

	if (IS_ZERO(size))
	{
		ERROR_LOG("size is " << size);
		return FALSE;
	}

	return TRUE;
}

bool MemoryManager::CanAllocMemory(void** data, const size_t size)
{
	if (IS_NOT_NULL(*data))
	{
		ERROR_LOG("data is not nullptr");
		return FALSE;
	}

	if (IS_ZERO(size))
	{
		ERROR_LOG("size is " << size);
		return FALSE;
	}

	return TRUE;
}

bool MemoryManager::CanReAllocMemory(void** data, const size_t currSize, const size_t newSize)
{
	if (IS_NULL(*data))
	{
		ERROR_LOG("data is nullptr");
		return FALSE;
	}

	if (IS_ZERO(currSize))
	{
		ERROR_LOG("currSize is " << currSize);
		return FALSE;
	}

	if (IS_ZERO(newSize))
	{
		ERROR_LOG("newSize is " << newSize);
		return FALSE;
	}

	return TRUE;
}

