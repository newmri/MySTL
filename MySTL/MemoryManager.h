#pragma once

class CMemoryManager : public CObj
{
	DECLARE_SINGLETON(CMemoryManager)

public:
	virtual bool Init(void) override;

public:
	// 메모리 동적 할당, pData는 nullptr이 와야 한다.
	bool AllocMemory(void** pData, const size_t uSize);
	// 메모리 재 할당 및 데이터 복사, pData는 nullptr이 아니여야 한다.
	bool ReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewSize);

private:
	// 메모리 할당 가능 한지 체크
	bool CanAllocMemory(void** pData, const size_t uSize);
	// 메모리 재 할당 가능 및 데이터 복사 가능 한지 체크
	bool CanReAllocMemory(void** pData, const size_t uCurrSize, const size_t uNewSize);

};