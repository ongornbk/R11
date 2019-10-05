require "Sunflower/vector"

Sunflower = {}

Sunflower.window = 0
Sunflower.hwnd = 0
Sunflower.lpmsg = 0
Sunflower.msg = 0
Sunflower.wparam = 0
Sunflower.lparam = 0
Sunflower.result = 0
Sunflower.timers = vector.new()

function Sunflower.Start(title,show)
Sunflower.lpmsg = malloc(48)
bzero(Sunflower.lpmsg)
Sunflower.window = windows.CreateWindow()
Sunflower.hwnd = windows.GetWindowHandle(Sunflower.window)
windows.SetTitle(Sunflower.hwnd,title)
windows.Show(Sunflower.hwnd,show)
end

function Sunflower.Init()
    Sunflower.lpmsg = malloc(48)
    bzero(Sunflower.lpmsg)
end

function Sunflower.Run()
local val = windows.GetMessage(Sunflower.hwnd,Sunflower.lpmsg)
Sunflower.lparam,Sunflower.wparam,Sunflower.msg = windows.RetrieveMessage(Sunflower.lpmsg)
return val
end

function Sunflower.Peek()
local val = windows.PeekMessage(Sunflower.hwnd,Sunflower.lpmsg)
Sunflower.lparam,Sunflower.wparam,Sunflower.msg = windows.RetrieveMessage(Sunflower.lpmsg)
return val
end

function Sunflower.SetTimer(id,time)
windows.SetTimer(Sunflower.hwnd,time,id)
vector.push_back(Sunflower.timers,id)
end

function Sunflower.Proc()
Sunflower.result = windows.Proc(Sunflower.hwnd,Sunflower.msg,Sunflower.wparam,Sunflower.lparam)
end

function Sunflower.Close()
windows.DestroyWindow(Sunflower.window)

for i = 0,Sunflower.timers.size-1,1
do
windows.KillTimer(Sunflower.hwnd,vector.get(Sunflower.timers,i))
end

vector.delete(Sunflower.timers)
end

function Sunflower.HideMenu()
windows.HideMenu(Sunflower.hwnd)
end

function Sunflower.OnClose(foo)
windows.RegisterEvent(0x0010,foo)
end

function Sunflower.OnPaint(foo)
windows.RegisterEvent(0x000f,foo)
end