#ifndef  MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include "forest.h"
#include "linkedList.h"
#include "fire.h"
#include <ctime>
#include "conditions.h"

class Simulation
{
	bool end = false;

	/// <summary>
	/// Function to output the menu
	/// </summary>
	void mainScreen();

	/// <summary>
	/// Function to start simulation with the fire at the center of the forest, with randomly chosen season, wind direction and weather
	/// </summary>
	void startSimulation();

	/// <summary>
	/// Function to start simulation with custom conditions,
	/// User can define number of initial fire points, their positions, wind direction, season and weather
	/// </summary>
	void startSimulationCustomConditions();

	void chooseMenuOptions(std::string userChoice);

	void defineConditions(int& windDirection, int& season, int& weather, Forest& forest);

	void simulation(Forest& forest, Conditions& conditions, Fire& fire);
public:

	/// <summary>
	/// This function is called in main() to start the program.
	/// </summary>
	void program();
};
#endif // ! MENU_H
