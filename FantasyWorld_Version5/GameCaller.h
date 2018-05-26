#pragma once

#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "Hero.h"
#include "Map.h"
#include "Monster.h"

class GameCaller
{
public:
	GameCaller();
	~GameCaller();
	char userInput;
	void InitGame();
	void PrintInfo();
	void gamePlay();
	//auto hero = std::make_shared<Hero>();
	//auto map = std::make_shared<Map>();
	//auto monster = std::make_shared<Monster>();
	std::vector<std::shared_ptr<Monster>> monsterStore;
	int playround = 1;
	int day = 1;
	int hour = 1;
	bool inGame = true;
	int locationX, locationY;
	float minute = 0;
};

