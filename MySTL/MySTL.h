#pragma once

template<typename T>
class CMySTL : public CObj
{
public:
	virtual bool Init(void) = 0;

public:
	// �����͸� �ڿ� ����
	virtual void push_back(const T Data) = 0;
	// ������ Ŭ����
	virtual void clear(void) = 0;
	// ������ ����(����) ������ ���´�.
	virtual size_t size(void) = 0;

protected:
	// ������ �Ѱ��� ������
	size_t m_uSize = 0;
	// ������ ����
	size_t m_uLen = 0;
};