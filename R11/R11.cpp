#include "pch.h"
#include "LuaManager.h"

uint32_t _cdecl main(int argc,char* argv[])
{
	std::string file;
	if (argc>1)
	{
		file = argv[1];
	}
	else
	{
		return false;
	}
	LuaManager lm;
	lm.Initialize(file);
	return true;
}
