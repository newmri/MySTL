#include "Global.h"

IMPLEMENT_SINGLETON(CTestManager)

bool CTestManager::Init(void)
{
	m_pData[ESTL::eMyVector].reset(new CMyVector<STL_TEST_TYPE>());
	m_pData[ESTL::eVector].reset(new CVector<STL_TEST_TYPE>());

	return SUCC;
}

void CTestManager::Do(const ESTL eSTLType, const size_t uTestNumber)
{
	if (ESTL::eSTLTypeEND == eSTLType)
	{
		ERROR_LOG("eSTLType is invalid " << eSTLType);
		return;
	}

	m_start = chrono::system_clock::now();

	m_pData[eSTLType]->reserve(uTestNumber / 5);

	for (size_t i = 0; i < uTestNumber; ++i)
	{
		m_pData[eSTLType]->push_back(100);
		m_pData[eSTLType]->pop_back();
		m_pData[eSTLType]->push_back(200);
	}

	m_sec = chrono::system_clock::now() - m_start;

	NORMAL_LOG("eSTLType: " << eSTLType << " size: " << m_pData[eSTLType]->size() << " has been passed time(sec) : " << m_sec.count() << " seconds");
}