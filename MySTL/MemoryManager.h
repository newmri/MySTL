#pragma once

class CMemoryManager : public CObj
{
	DECLARE_SINGLETON(CMemoryManager)

public:
	virtual bool Init(void) override;

public:
	// �޸� ���� �Ҵ�, pData�� nullptr�� �;� �Ѵ�.
	bool AllocMemory(void** pData, const size_t uSize);
	// �޸� �� �Ҵ� �� ������ ����, pData�� nullptr�� �ƴϿ��� �Ѵ�.
	bool ReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewSize);

private:
	// �޸� �Ҵ� ���� ���� üũ
	bool CanAllocMemory(void** pData, const size_t uSize);
	// �޸� �� �Ҵ� ���� �� ������ ���� ���� ���� üũ
	bool CanReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewSize);

};