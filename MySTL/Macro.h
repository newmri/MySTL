#pragma once

#define IS_ZERO(NUMBER) (0 == NUMBER)
#define IS_ABOVE_ZERO(NUMBER) (0 < NUMBER)
#define IS_UNDER_ONE(NUMBER) (1 > NUMBER)

#define IS_SAME(LEFT_NUMBER, RIGHT_NUMBER) (LEFT_NUMBER == RIGHT_NUMBER)
#define IS_VALID_RANGE(NUMBER, MAX_NUMBER) (0 <= NUMBER && MAX_NUMBER > NUMBER) 

#define ERROR_LOG(str) cout << "File: " __FILE__ << " Function: " __FUNCTION__ << " Line: " << __LINE__ <<" Error: " << str << endl;
#define NORMAL_LOG(str) cout << str << endl;


#define IS_NULL(ptr) (nullptr == ptr)
#define IS_NOT_NULL(ptr) (nullptr != ptr)

#define SAFE_DELETE(ptr) if(ptr) delete ptr; ptr = nullptr;
#define SAFE_DELETE_ARRAY(ptr) if(ptr) delete []ptr; ptr = nullptr;

#define DEFAULT_CONSTRUCTOR(CLASS) private: CLASS() = default;

#define NO_COPY(CLASS)								\
	private:										\
	CLASS(const CLASS&) = delete;					\
	CLASS& operator = (const CLASS&) = delete;		

#define DECLARE_SINGLETON(CLASS)					\
	DEFAULT_CONSTRUCTOR(CLASS)						\
	NO_COPY(CLASS)									\
													\
	static unique_ptr<CLASS> instance;				\
	static once_flag onceFlag;						\
													\
	public:											\
	static CLASS&	GetInstance(void);					

#define IMPLEMENT_SINGLETON(CLASS)					\
	unique_ptr<CLASS> CLASS::instance;				\
	once_flag CLASS::onceFlag;						\
													\
	CLASS& CLASS::GetInstance(void)					\
	{												\
		call_once(CLASS::onceFlag, []()				\
		{											\
			instance.reset(new CLASS);				\
			(*(instance.get())).Init();				\
		});											\
													\
		return *(instance.get());					\
	}

#define GET_INSTANCE(CLASS) CLASS::GetInstance()