#include<iostream>
#include "Monster.h"
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


Monster::Monster()
{


}


Monster::~Monster()
{
}

void Monster::setMonsterHP()
{


}

void Monster::setMonsterPosition(int x, int y, Map &m, int type)
{
	monsterPositionX = x;
	monsterPositionY = y;
	m.mapGrid[monsterPositionY][monsterPositionX] = type + 1;
}

void Monster::setMonsterID(int monID)
{
	monsterID = monID;
}

void Monster::setMonsterType(int montype)
{
	//1Orc Warrior 2Orc Elder 3Zombie Warrior 4 Zombie Elder
	if (montype == 1) { monsterType = "Orc_Warrior"; }
	else if (montype == 2) { monsterType = "Orc_Elder"; }
	else if (montype == 3) { monsterType = "Zombie_Warrior"; }
	else if (montype == 4) { monsterType = "Zombie_Elder"; }
	string line;
	ifstream myfile("MonsterInformation.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::vector<std::string> inforstore;
			std::istringstream ss(line);
			std::string token;

			while (getline(ss, token, ','))
			{
				inforstore.push_back(token);
			}

			for (unsigned int i = 0; i < inforstore.size(); i++)
			{
				if (inforstore.at(i) == monsterType)
				{
					monsterHP = std::stoi(inforstore.at(i + 1));
					monsterAtkDamage = std::stoi(inforstore.at(i + 2));
				}
				else break;
			}

			inforstore.clear();

		}
		myfile.close();
	}
	else cout << "Error No File Founded";

}

void Monster::monsterStronger()
{
	monsterAtkDamage *= 1.01;
	monsterHP *= 1.01;
}