#include "Global.h"

IMPLEMENT_SINGLETON(TestManager)

bool TestManager::Init(void)
{
	this->data[ESTL::MY_VECTOR].reset(new MyVector<STL_TEST_TYPE>());
	this->data[ESTL::VECTOR].reset(new Vector<STL_TEST_TYPE>());

	return SUCC;
}

void TestManager::Do(const ESTL stlType, const size_t testNumber)
{
	if (ESTL::STL_TYPE_END == stlType)
	{
		ERROR_LOG("stlType is invalid " << stlType);
		return;
	}

	this->start = chrono::system_clock::now();

	this->data[stlType]->reserve(testNumber / TEST_RESERVE_DEVIDE_NUMBER);

	for (size_t i = 0; i < testNumber; ++i)
	{
		this->data[stlType]->push_back(100);
		this->data[stlType]->pop_back();
		this->data[stlType]->push_back(300);
	}

	this->sec = chrono::system_clock::now() - this->start;

	NORMAL_LOG("ESTL: " << stlType << " size: " << this->data[stlType]->size() << " has been passed time(sec) : " << this->sec.count() << " seconds");
}