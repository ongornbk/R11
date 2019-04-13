#include "pch.h"
#include "LuaManager.h"
#include "resource.h"
#include "Collector.h"

uint32_t _cdecl main(int argc,char* argv[])
{
	std::string file;
	std::string path;
	if (argc<2)
		return false;

	LuaManager lm;
	if (!lm.Initialize(argc, argv))
		getchar();

	free_collector();

	return true;
}
