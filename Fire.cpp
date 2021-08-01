#include "fire.h"
#include <iostream>
#include "tree.h"

Fire::Fire(Forest* forest) { this->forest = forest; };

void Fire::spreadFire(Conditions* conditions)
{
	int numberOfElements = forest->getLinkedList()->getNumberOfElements();

	for (int i = 0; i < numberOfElements; i++)
	{
		Tree* current = forest->getLinkedList()->getTree(i);
		short currentX = current->getX();
		short currentY = current->getY();

		if (current->getState() == false)
		{
			if (forest->forestCharArray[currentY][currentX + 1] == 'X')
			{
				calculateProbability(conditions, "E");
				if (probability > 50)
					current->changeState();
			}
			else if (forest->forestCharArray[currentY][currentX - 1] == 'X')
			{
				calculateProbability(conditions, "W");
				if (probability > 50)
					current->changeState();
			}
			else if (forest->forestCharArray[currentY + 1][currentX] == 'X')
			{
				calculateProbability(conditions, "S");
				if (probability > 50)
					current->changeState();
			}
			else if (forest->forestCharArray[currentY - 1][currentX] == 'X')
			{
				calculateProbability(conditions, "N");
				if (probability > 50)
					current->changeState();
			}

			if (current->getState())
			{
				if ((extinguishProbability(conditions->getWeather()) > 50))
				{
					current->setCharred();
				}
			}
		}
	}
};

int Fire::windDirectionProbability(std::string windDirection, std::string treePostion)
{
	if (windDirection == treePostion)
		return 50 + (rand() % (70 - 50 + 1));

	else if ((windDirection == "N" && treePostion == "S") || (windDirection == "S" && treePostion == "N"))
		return rand() % 10;

	else if ((windDirection == "E" && treePostion == "W") || (windDirection == "W" && treePostion == "E"))
		return rand() % 10;

	else
		return 35 + (rand() % (55 - 35 + 1));
};

int Fire::seasonProbability(std::string season)
{
	if (season == "Winter")
		return 40 + (rand() % (60 - 40 + 1));

	else if (season == "Spring")
		return 45 + (rand() % (70 - 45 + 1));

	else if (season == "Summer")
		return 50 + (rand() % (83 - 50 + 1));

	else if (season == "Autumn")
		return 45 + (rand() % (60 - 45 + 1));
};

int Fire::extinguishProbability(std::string weather)
{
	if (weather == "Rainy")
		return rand() % 55;

	else
		return 0;
};

void Fire::calculateProbability(Conditions* conditions, std::string treeDirection)
{
	int wind = windDirectionProbability(conditions->getWindDirection(), treeDirection);
	int season = seasonProbability(conditions->getSeason());
	probability = (2 * wind + season) / 3;
};
