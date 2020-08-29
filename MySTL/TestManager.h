#pragma once

// Å×½ºÆ® È½¼ö
static const size_t TEST_NUMBER = 10000000;

typedef int STL_TEST_TYPE;

enum ESTL
{
	eMyVector,
	eVector,
	eSTLTypeEND
};

class CTestManager : public CObj
{
	DECLARE_SINGLETON(CTestManager)
	
public:
	virtual bool Init(void) override;

public:
	void Do(const ESTL eSTLType = ESTL::eMyVector, const size_t uTestNumber = TEST_NUMBER);

private:
	chrono::system_clock::time_point m_start;
	chrono::duration<double> m_sec;
	unique_ptr<CMySTL<STL_TEST_TYPE>> m_pData[ESTL::eSTLTypeEND];
};