#include "Global.h"

int main(void)
{
	for (size_t i = 0; i < ESTL::eSTLTypeEND; ++i)
	{
		GET_INSTANCE(CTestManager).Do(static_cast<ESTL>(i));
	}
	
	return SUCC;
}