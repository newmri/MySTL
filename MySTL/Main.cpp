#include "Global.h"

int main(void)
{
	for (size_t i = 0; i < ESTL::STL_TYPE_END; ++i)
	{
		GET_INSTANCE(TestManager).Do(static_cast<ESTL>(i));
	}

	return SUCC;
}