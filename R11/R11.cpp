#include "pch.h"
#include "LuaManager.h"

uint32_t _cdecl main(int argc,char* argv[])
{
	LuaManager lm;
	lm.Initialize();
	return true;
}
