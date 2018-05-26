#pragma once
#include<string>
#include <fstream>
#include "Map.h"


class Monster
{
public:
	Monster();
	~Monster();
	double monsterHP;
	double monsterAtkDamage;
	int monsterPositionX;
	int monsterPositionY;
	int MaxMonsterNumber = 10;
	int monsterID;
	std::string monsterType;

	void setMonsterHP();
	void setMonsterPosition(int x, int y, Map &m, int type);
	void setMonsterID(int monID);
	void setMonsterType(int montype);
	void monsterStronger();
	Monster(const Monster& ms) = default;
	Monster& operator = (Monster& ms) = default;

};