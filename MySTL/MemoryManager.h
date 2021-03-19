#pragma once

class MemoryManager : public Obj
{
	DECLARE_SINGLETON(MemoryManager)

public:
	virtual bool Init(void) override;

public:
	// 메모리 동적 할당, data는 nullptr이 와야 한다.
	bool AllocMemory(void** data, const size_t size);
	// 메모리 재 할당 및 데이터 복사, data는 nullptr이 아니여야 한다.
	bool ReAllocMemory(void** data, const size_t currSize, const size_t newSize);

private:
	// 메모리 할당 가능 한지 체크
	bool CanAllocMemory(void** data, const size_t size);
	// 메모리 재 할당 가능 및 데이터 복사 가능 한지 체크
	bool CanReAllocMemory(void** data, const size_t currSize, const size_t newSize);

};