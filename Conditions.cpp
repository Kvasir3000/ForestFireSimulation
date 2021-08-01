#include "conditions.h"
#include <iostream>

Conditions::Conditions()
{
	setSeason();
	setWindDirection();
	setWeather();
};

Conditions::Conditions(int directionInp, int seasonInp, int weatherInp)
{
	setWindDirection(directionInp);
	setSeason(seasonInp);
	setWeather(weatherInp);
}

/// <summary>
/// The probability of rainy weather depends on the season 
/// 1. In winter the probability is 1/2
/// 2. In spring the probability is 1/4
/// 3. In summer the probability is 1/3
/// 4. In autumn the probability is 3/4
/// </summary>
void Conditions::setWeather()
{
	if (season == "Winter" && ((rand() % 2) == 1))
		weather = "Rainy";

	else if (season == "Spring" && ((rand() % 4) == 1))
		weather = "Rainy";

	else if (season == "Summer" && ((rand() % 3) == 1))
		weather = "Rainy";

	else if (season == "Autumn" && ((rand() % 4) > 0))
		weather = "Rainy";

	else
		weather = "Sunny";
};

void Conditions::setSeason()
{
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		season = "Winter";
		break;
	case 1:
		season = "Spring";
		break;

	case 2:
		season = "Summer";
		break;

	case 3:
		season = "Autumn";
		break;
	}
};

void Conditions::setWindDirection()
{
	int random = rand() % 4;
	switch (random)
	{
	case 0:
		windDirection = "N";
		break;

	case 1:
		windDirection = "S";
		break;

	case 2:
		windDirection = "W";
		break;

	case 3:
		windDirection = "E";
		break;
	}

};

void Conditions::setWindDirection(int directionInp)
{
	switch (directionInp)
	{
	case 1:
		windDirection = "N";
		break;

	case 2:
		windDirection = "S";
		break;

	case 3:
		windDirection = "W";
		break;

	case 4:
		windDirection = "E";
		break;
	}
};

void Conditions::setSeason(int seasonInp)
{
	switch (seasonInp)
	{
	case 1:
		season = "Winter";
		break;

	case 2:
		season = "Spring";
		break;

	case 3:

		season = "Summer";
		break;

	case 4:
		season = "Autumn";
		break;
	}
}

void Conditions::setWeather(int weatherInp)
{
	if (weatherInp == 1)
		weather = "Sunny";
	else
		weather = "Rainy";
};

std::string Conditions::getWindDirection() { return windDirection; };

std::string Conditions::getSeason() { return season; };

std::string Conditions::getWeather() { return weather; };


