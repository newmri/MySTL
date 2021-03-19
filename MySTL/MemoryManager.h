#pragma once

class MemoryManager : public Obj
{
	DECLARE_SINGLETON(MemoryManager)

public:
	virtual bool Init(void) override;

public:
	// �޸� ���� �Ҵ�, data�� nullptr�� �;� �Ѵ�.
	bool AllocMemory(void** data, const size_t size);
	// �޸� �� �Ҵ� �� ������ ����, data�� nullptr�� �ƴϿ��� �Ѵ�.
	bool ReAllocMemory(void** data, const size_t currSize, const size_t newSize);

private:
	// �޸� �Ҵ� ���� ���� üũ
	bool CanAllocMemory(void** data, const size_t size);
	// �޸� �� �Ҵ� ���� �� ������ ���� ���� ���� üũ
	bool CanReAllocMemory(void** data, const size_t currSize, const size_t newSize);

};