#include "Global.h"

IMPLEMENT_SINGLETON(TestManager)

bool TestManager::Init(void)
{
	this->data[ESTL::MY_VECTOR].reset(new MyVector<STL_TEST_TYPE>());
	this->data[ESTL::VECTOR].reset(new Vector<STL_TEST_TYPE>());

	return SUCC;
}

void TestManager::Work(TestInfo testInfo)
{
	size_t testNumber = testInfo.testNumber;
	size_t size = 0;
	STL_TEST_TYPE lastData = 0;

	for (size_t threadNumber = testInfo.startThreadNumber; threadNumber <= testInfo.endThreadNumber; threadNumber *= testInfo.increaseThreadNumberTimes)
	{
		NORMAL_LOG("[threadNumber]: " << threadNumber);

		for (size_t i = 0; i < ESTL::STL_TYPE_END; ++i)
		{
			testInfo.stlType = static_cast<ESTL>(i);
			testInfo.testNumber = testNumber / threadNumber;

			vector<thread> threads;

			for (size_t j = 0; j < threadNumber; ++j)
				threads.emplace_back(thread([&]() { TestManager::Do(testInfo); }));

			this->start = chrono::system_clock::now();

			for (auto& d : threads)
				d.join();

			this->sec = chrono::system_clock::now() - this->start;

			size = this->data[testInfo.stlType]->size();
			lastData = (*this->data[testInfo.stlType])[size - 1];

			NORMAL_LOG("ESTL: [" << testInfo.stlType << "] " << "testNumber: " << testNumber << " size: " << size << " last data: " << lastData);
			NORMAL_LOG("ESTL: [" << testInfo.stlType << "] " << "seconds: " << this->sec.count());
		}

		Init();
	}
}

void TestManager::Do(const TestInfo testInfo)
{
	if (ESTL::STL_TYPE_END == testInfo.stlType)
	{
		ERROR_LOG("testInfo.stlType is invalid " << testInfo.stlType);
		return;
	}

	this->data[testInfo.stlType]->reserve(testInfo.testNumber / testInfo.reserveDevideNumber);

	for (size_t i = 0; i < testInfo.testNumber; ++i)
	{
		this->data[testInfo.stlType]->push_back(100);
		this->data[testInfo.stlType]->pop_back();
		this->data[testInfo.stlType]->push_back(300);
	}
}