#include "pch.h"
#include "LuaManager.h"
#include "resource.h"
#include "Collector.h"

#include <iostream>

int CALLBACK WinMain(
	HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow
)
{
	std::string file;
	std::string path;
	if (__argc < 2)
	{
		char* argv[2] = { "C:\\Users\\Szymon\\source\\repos\\R11\\x64\\Release\\R11.exe",
		  "C:\\Users\\Szymon\\source\\repos\\R11\\x64\\Release\\test.qpp" };
		LuaManager lm;
		lm.Initialize(2,argv);
	
		//push_ptr(argv);
	}
	else
	{
		LuaManager lm;
		lm.Initialize(__argc, __argv);
	}
	



	return true;
}
