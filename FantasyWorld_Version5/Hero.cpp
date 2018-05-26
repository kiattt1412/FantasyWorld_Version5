#include "Hero.h"
#include "Map.h"
#include "Monster.h"
#include <vector>
#include <memory>
using namespace std;
auto monster2 = std::make_shared<Monster>();

Hero::Hero()
{
	heroPositionX = 1;
	heroPositionY = 1;
	isFighting = false;
	isAlive = true;
	heroHP = 1900;
	heroAtkDamage = 150;
}


Hero::~Hero()
{
}

void Hero::heroMove(char c, Map &m, vector<std::shared_ptr<Monster>> &monStore)
{


	if (c == 'd' || c == 'D')
	{
		int numberInPosition = m.mapGrid[heroPositionY][heroPositionX + 1];
		if (heroPositionX < m.worldWidth - 2)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionX += 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX + 1, heroPositionY);
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionX += 1;
				monfightID = numberInPosition;
			}
		}

	}

	if (c == 's' || c == 'S')
	{
		int numberInPosition = m.mapGrid[heroPositionY + 1][heroPositionX];
		if (heroPositionY < m.worldHeight - 2)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionY += 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX, heroPositionY + 1);
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionY += 1;
				monfightID = numberInPosition;
			}
		}
	}

	else if (c == 'w' || c == 'W')
	{
		int numberInPosition = m.mapGrid[heroPositionY - 1][heroPositionX];
		if (heroPositionY > 1)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionY -= 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX, heroPositionY - 1);
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionY -= 1;
				monfightID = numberInPosition;
			}
		}
	}

	else if (c == 'a' || c == 'A')
	{
		int numberInPosition = m.mapGrid[heroPositionY][heroPositionX - 1];
		if (heroPositionX > 1)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionX -= 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX - 1, heroPositionY);
				m.mapGrid[heroPositionY][heroPositionX] = 0;
				heroPositionX -= 1;
				monfightID = numberInPosition;
			}
		}
	}

}

void Hero::heroMoveOut(char c, Map &m, vector<std::shared_ptr<Monster>> &monStore)
{
	if (c == 'd' || c == 'D')
	{
		int numberInPosition = m.mapGrid[heroPositionY][heroPositionX + 1];
		if (heroPositionX < m.worldWidth - 2)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionX += 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX + 1, heroPositionY);
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionX += 1;
				monfightID = numberInPosition;
			}
		}

	}

	if (c == 's' || c == 'S')
	{
		int numberInPosition = m.mapGrid[heroPositionY + 1][heroPositionX];
		if (heroPositionY < m.worldHeight - 2)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionY += 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX, heroPositionY + 1);
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionY += 1;
				monfightID = numberInPosition;
			}
		}
	}

	else if (c == 'w' || c == 'W')
	{
		int numberInPosition = m.mapGrid[heroPositionY - 1][heroPositionX];
		if (heroPositionY > 1)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionY -= 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX, heroPositionY - 1);
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionY -= 1;
				monfightID = numberInPosition;
			}
		}
	}

	else if (c == 'a' || c == 'A')
	{
		int numberInPosition = m.mapGrid[heroPositionY][heroPositionX - 1];
		if (heroPositionX > 1)
		{
			if (numberInPosition == 0)
			{
				isFighting = false;
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionX -= 1;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
				monfightID = 0;
			}
			else if (numberInPosition == 2 || numberInPosition == 3 || numberInPosition == 4 || numberInPosition == 5)
			{
				isFighting = true;
				heroAttack(monStore, m, heroPositionX, heroPositionY, heroPositionX - 1, heroPositionY);
				m.mapGrid[heroPositionY][heroPositionX] = monfightID;
				heroPositionX -= 1;
				monfightID = numberInPosition;
			}
		}
	}

}

void Hero::setHeroPosition(int x, int y, Map &m)
{
	m.mapGrid[y][x] = 1;
}

void Hero::heroAttack(vector<std::shared_ptr<Monster>> &monStore2, Map &m, int, int, int monposX, int monposY)
{
	for (int i = 0; i < monster2->MaxMonsterNumber; i++)
	{
		if (monStore2[i] != NULL)
		{
			if ((monStore2[i]->monsterPositionX == monposX) &&
				(monStore2[i]->monsterPositionY == monposY))
			{
				m.mapGrid[monposY][monposX] = 99;
				isFighting = true;
			}
		}
	}
}

void Hero::damageCal(vector<std::shared_ptr<Monster>> &monStore2, Map &m)
{
	for (int i = 0; i < monster2->MaxMonsterNumber; i++)
	{
		if (monStore2[i] != NULL)
		{
			if ((monStore2[i]->monsterPositionX == heroPositionX) &&
				(monStore2[i]->monsterPositionY == heroPositionY))
			{
				monStore2[i]->monsterHP -= heroAtkDamage;
				if (monStore2[i]->monsterHP > 0)
				{
					heroHP -= monStore2[i]->monsterAtkDamage;
					if (heroHP <= 0)
					{
						isAlive = false;
					}
				}
			}
			if (monStore2[i]->monsterHP <= 0)
			{
				isFighting = false;
				monStore2[i] = NULL;
				m.mapGrid[heroPositionY][heroPositionX] = 1;
			}
		}
	}
}