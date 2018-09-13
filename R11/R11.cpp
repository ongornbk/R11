#include "pch.h"
#include "LuaManager.h"

uint32_t _cdecl main(int argc,char* argv[])
{
	std::string file;
	std::string path;
	if (argc>1)
	{
		path = argv[0];
		file = argv[1];
	}
	else
	{
		return false;
	}
	LuaManager lm;
	lm.Initialize(path,file);
	return true;
}
