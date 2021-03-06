#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <sal.h>
#include <mmsystem.h>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <type_traits>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <stack>
#include <list>

#include "luaH.h"

#include "types.hpp"

#pragma region
template <class _Out_ ReturnType, class _In_ Type>
inline ReturnType& memory_cast(const Type& obj)
{
	return *(ReturnType*)(obj);
}

template <class _Out_ ReturnType, class _In_ Type>
inline ReturnType* mmalloc(const Type nitems)
{
	return (ReturnType*)malloc((nitems) * sizeof(ReturnType));
}

template <class _Out_ ReturnType, class _In_ Type>
inline ReturnType* mcalloc(const Type nitems)
{
	return (ReturnType*)calloc(nitems, sizeof(ReturnType));
}

template <class ReturnType, class A, class _In_ Type>
inline ReturnType* mrealloc(A& ptr, const Type nitems)
{
	return (ReturnType*)realloc(ptr, (nitems) * sizeof(ReturnType));
}

template <class A>
inline void mfree(A& ptr)
{
	return free(ptr);
}
#pragma endregion

extern "C"
{
	struct cpair
	{
		constexpr cpair(const char* _key,lua_CFunction _value) : key(_key), value(_value) {}

		const char* key;
		lua_CFunction value;
	};
}



