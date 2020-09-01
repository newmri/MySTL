#include "Global.h"

IMPLEMENT_SINGLETON(CMemoryManager)

bool CMemoryManager::Init(void)
{
	return SUCC; 
}

bool CMemoryManager::AllocMemory(void** pData, const size_t uSize)
{
	if (FALSE == CanAllocMemory(pData, uSize)) return FAIL;

	// try�� ���� CanAllocMemory���� �޸� ��뷮�� üũ�ؼ�
	// �����Ҵ� ���� ���θ� �߰� �ұ�?

	try
	{
		*pData = new char[uSize];
		memset(*pData, 0, uSize);
	}

	catch (bad_alloc& badalloc)
	{
		ERROR_LOG("bad_alloc reason: " << badalloc.what());
		return FAIL;
	}

	return SUCC;
}

bool CMemoryManager::ReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewSize)
{
	if (FALSE == CanReAllocMemory(pData, uCurrSize, uNewSize)) return FAIL;

	void* pNewData = nullptr;

	// ���ο� �����͸� ���� �޸� �Ҵ�
	if (AllocMemory((void**)&pNewData, uNewSize)) return FAIL;

	// ������ ����
	memcpy_s(pNewData, uNewSize, *pData, uCurrSize);

	// ���� �޸� ����
	SAFE_DELETE_ARRAY(*pData);

	// ���ο� �����͸� ����Ű��.
	*pData = pNewData;

	return SUCC;
}

bool CMemoryManager::CanAllocMemory(void** pData, const size_t uSize)
{
	if (IS_NOT_NULL(*pData))
	{
		ERROR_LOG("pData is not nullptr");
		return FALSE;
	}

	if (IS_ZERO(uSize))
	{
		ERROR_LOG("uSize is " << uSize);
		return FALSE;
	}

	return TRUE;
}

bool CMemoryManager::CanReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewsize)
{
	if (IS_NULL(*pData))
	{
		ERROR_LOG("pData is nullptr");
		return FALSE;
	}

	if (IS_ZERO(uCurrSize))
	{
		ERROR_LOG("uCurrSize is " << uCurrSize);
		return FALSE;
	}

	if (IS_ZERO(uNewsize))
	{
		ERROR_LOG("uNewsize is " << uNewsize);
		return FALSE;
	}

	if (IS_SAME(uCurrSize, uNewsize))
	{
		ERROR_LOG("uCurrSize and uNewsize is same " << uNewsize);
		return FALSE;
	}

	return TRUE;
}

