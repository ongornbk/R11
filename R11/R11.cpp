#include "pch.h"
#include "LuaManager.h"
#include "resource.h"
#include "Collector.h"

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
	if (!lm.Initialize(path, file))
		getchar();

	free_collector();

	return true;
}
