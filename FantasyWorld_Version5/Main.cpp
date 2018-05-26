#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include "GameCaller.h"
#define _CRTDBG_MAP_ALLOC

auto gamecall = std::make_shared<GameCaller>();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	gamecall->InitGame();
	gamecall->PrintInfo();
	gamecall->gamePlay();

	return 0;
}


