#include <iostream>
#include "forest.h"


Forest::Forest()
{
	forest = LinkedList();
	forestCharArray = new char* [441];
	for (int i = 0; i < 21; i++)
	{
		forestCharArray[i] = new char[21];
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 || i == 20)
				forestCharArray[i][j] = '#';
			else if (j == 0 || j == 20)
				forestCharArray[i][j] = '#';
			else
				forestCharArray[i][j] = '^';
		}
	}
	populateForest();
	frame = 1;
	trees = 19 * 19;
	burntTrees = percentage = burningTrees = charredTrees = 0;
};

void Forest::populateForest()
{
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			forest.addTree(j, i);
		}
	}
};

void Forest::updateMap()
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (forestCharArray[i][j] == 'X' && forest.getTree(j, i)->getCharred())
			{
				forestCharArray[i][j] = '*';
				forest.deleteTreeAt(j, i);
				charredTrees++;
				burningTrees--;
			}
			else if (forestCharArray[i][j] == 'X')
			{
				forestCharArray[i][j] = ' ';
				forest.deleteTreeAt(j, i);
				trees--;
				burntTrees++;
				burningTrees--;
			}
			else if (i != 0 && i != 20 && j != 0 && j != 20 && forestCharArray[i][j] != ' ' && forestCharArray[i][j] != '*')
			{
				if (forest.getTree(j, i)->getState())
				{
					forestCharArray[i][j] = 'X';
					burningTrees++;
				}
			}
		}
	}
	percentage = (burntTrees * 100) / (19 * 19);
};

void Forest::displayForest(Conditions* conditions)
{
	updateMap();
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			std::cout << forestCharArray[i][j];
		}

		if (i == 0)
			std::cout << "       # - Border;   ^ - Tree;   X - Fire;   * - Charred Trees;";

		if (i == 2)
		{
			std::cout << "       FRAME: " << frame << "                        ";

			if (frame >= 10)
				std::cout << "\b";
			std::cout << "NUMBER OF TRESS: " << trees;
		}

		if (i == 3)
			std::cout << "       WIND DIRECTION: " <<
			conditions->getWindDirection() << "               NUMBER OF BURNING TREES: " << burningTrees;

		if (i == 4)
			std::cout << "       SEASON: " << conditions->getSeason() << "                  NUBMBER OF BURNT TREES: " << burntTrees;

		if (i == 5)
			std::cout << "       WEATHER: " << conditions->getWeather() << "                  BURNT TREES IN PERCENTAGE: " << percentage << "%";
		if (i == 6)
			std::cout << "                                       NUMBER OF CHARRED TREES: " << charredTrees;
		std::cout << std::endl;
	}
	frame++;
};

void Forest::startFireAt(int x, int y) { if (!forest.getTree(x, y)->getState()) forest.getTree(x, y)->changeState(); };

int Forest::getBurningTrees() { return burningTrees; };

LinkedList* Forest::getLinkedList() { return &forest; };
