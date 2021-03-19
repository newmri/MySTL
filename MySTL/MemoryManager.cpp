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

	// ���ο� �����͸� ���� �޸� �Ҵ�
	if (AllocMemory((void**)&newData, newSize))
		return FAIL;

	// ������ ����
	memcpy_s(newData, newSize, *data, currSize);

	// ���� �޸� ����
	SAFE_DELETE_ARRAY(*data);

	// ���ο� �����͸� ����Ű��.
	*data = newData;

	return SUCC;
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

	if (IS_SAME(currSize, newSize))
	{
		ERROR_LOG("currSize and newSize is same " << newSize);
		return FALSE;
	}

	return TRUE;
}

