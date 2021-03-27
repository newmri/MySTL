#pragma once 

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#include <iostream>
#include <memory>
#include <mutex>
#include <chrono>
#include <VECTOR>
#include <thread>
#include <atomic>

using namespace std;

#include "Obj.h"
#include "MemoryManager.h"
#include "MySTL.h"
#include "MyVector.h"
#include "VECTOR.h"
#include "TestManager.h"
#include "MyAlgorithm.h"