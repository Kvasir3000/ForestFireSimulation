#include "render.h"

void Render:: setCursorVisability(bool visable)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = visable; 
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Render::setCursorPosition(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(hConsole, pos);
}