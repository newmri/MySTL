#pragma once

static const size_t TEST_START_THREAD_NUMBER = 4;
static const size_t TEST_END_THREAD_NUMBER = 64;
static const size_t TEST_INCREASE_THREAD_NUMBER_TIMES = 2;

static const size_t TEST_NUMBER = 1000000;
static const size_t TEST_RESERVE_DEVIDE_NUMBER = 10;

typedef int STL_TEST_TYPE;

enum ESTL
{
	MY_VECTOR,
	VECTOR,
	STL_TYPE_END
};

typedef struct
{
	ESTL stlType = ESTL::MY_VECTOR;
	size_t startThreadNumber = TEST_START_THREAD_NUMBER;
	size_t endThreadNumber = TEST_END_THREAD_NUMBER;
	size_t increaseThreadNumberTimes = TEST_INCREASE_THREAD_NUMBER_TIMES;
	size_t testNumber = TEST_NUMBER;
	size_t reserveDevideNumber = TEST_RESERVE_DEVIDE_NUMBER;
}TestInfo;

class TestManager : public Obj
{
	DECLARE_SINGLETON(TestManager)

public:
	virtual bool Init(void) override;

public:
	void Work(TestInfo testInfo = TestInfo());

private:
	void Do(const TestInfo testInfo);

private:
	unique_ptr<MySTL<STL_TEST_TYPE>> data[ESTL::STL_TYPE_END];
	chrono::system_clock::time_point start;
	chrono::duration<double> sec;
	mutex lock;
};