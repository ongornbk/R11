#pragma once

extern lua_CFunction EventTimer;
extern lua_CFunction EventDestroy;
extern lua_CFunction EventPaint;
extern lua_CFunction EventHover;
extern lua_CFunction EventClose;
extern lua_CFunction EventQuit;
extern lua_CFunction EventKeyDown;

extern LRESULT __stdcall WindowProcedure(HWND window, uint32_t msg, WPARAM wp, LPARAM lp);

class Window
{
public:

	Window(lua_State* state);

	~Window();

	HWND window;
	static lua_State* m_state;
	static std::stack<lua_Integer>& GetStack();
};