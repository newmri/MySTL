#pragma once

// Å×½ºÆ® È½¼ö
static const size_t TEST_NUMBER = 50000000;

static const size_t TEST_RESERVE_DEVIDE_NUMBER = 10;

typedef int STL_TEST_TYPE;

enum ESTL
{
	MY_VECTOR,
	VECTOR,
	STL_TYPE_END
};

class TestManager : public Obj
{
	DECLARE_SINGLETON(TestManager)
	
public:
	virtual bool Init(void) override;

public:
	void Do(const ESTL stlType = ESTL::MY_VECTOR, const size_t testNumber = TEST_NUMBER);

private:
	chrono::system_clock::time_point start;
	chrono::duration<double> sec;
	unique_ptr<MySTL<STL_TEST_TYPE>> data[ESTL::STL_TYPE_END];
};