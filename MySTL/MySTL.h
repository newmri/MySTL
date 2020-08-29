#pragma once

template<typename T>
class CMySTL : public CObj
{
public:
	virtual bool Init(void) = 0;

public:
	// 데이터를 뒤에 삽입
	virtual void push_back(const T Data) = 0;
	// 데이터 클리어
	virtual void clear(void) = 0;
	// 데이터 길이(원소) 갯수를 얻어온다.
	virtual size_t size(void) = 0;

protected:
	// 데이터 한개의 사이즈
	size_t m_uSize = 0;
	// 데이터 길이
	size_t m_uLen = 0;
};