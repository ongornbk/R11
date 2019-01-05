#pragma once
#include <windows.h>
#include <cstdint>
#include <sal.h>
#include <mmsystem.h>


struct lua64uint
{
	explicit lua64uint(const _In_ uint32_t f, const uint32_t s) : first(f), second(s) {}

	uint32_t first;
	uint32_t second;
};

union ptrtype
{
	ptrtype(void* v)
	{
		ptr = v;
	}
	ptrtype(uint32_t first, uint32_t second)
	{
		lua = lua64uint(first, second);
	}
	ptrtype(uint64_t i)
	{
		val = i;
	}
	ptrtype(lua64uint l)
	{
		lua = l;
	}
	__unaligned void* ptr;
    uint64_t          val;
	lua64uint         lua;
};


