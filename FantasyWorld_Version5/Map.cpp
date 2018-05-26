#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()
{

}


Map::~Map()
{
}

void Map::printMap()
{

	cout << endl;
	for (int i = 0; i < worldHeight; i++)
	{
		for (int j = 0; j < worldWidth; j++)
		{
			if (i == 0 || i == worldHeight - 1) { cout << "---"; }
			else if (j == 0 || j == worldWidth - 1) { cout << " I "; }

			else if (mapGrid[i][j] == 0)
			{
				cout << "   ";
			}
			else if (mapGrid[i][j] == 1)
			{
				cout << " H ";
			}
			else if (mapGrid[i][j] == 2)
			{
				cout << " OW";
			}
			else if (mapGrid[i][j] == 3)
			{
				cout << " OE";
			}
			else if (mapGrid[i][j] == 4)
			{
				cout << " ZW";
			}
			else if (mapGrid[i][j] == 5)
			{
				cout << " ZE";
			}
			else if (mapGrid[i][j] == 99)
			{
				cout << " F ";
			}

			if (j == 31)
			{
				cout << endl;
			}
		}
	}

}