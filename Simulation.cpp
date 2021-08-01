#include "simulation.h"
#include "render.h"


void Simulation::mainScreen()
{
	std::cout << "*********** FOREST FIRE SIMULATION ***********\n\n";
	std::cout << "Choose one of the option from below: \n";
	std::cout << "1. Start the simulation with random conditions\n";
	std::cout << "2. Start the simulation with custom conditions\n";
	std::cout << "3. End Program\n:> ";
};

void Simulation::chooseMenuOptions(std::string userChoice)
{
	if (userChoice == "1")
	{
		system("CLS");
		startSimulation();
	}
	else if (userChoice == "2")
	{
		startSimulationCustomConditions();
	}
	else if (userChoice == "3")
	{
		end = true;
	}
};

void Simulation::startSimulation()
{
	Forest forest = Forest();

	Fire fire = Fire(&forest);

	Conditions conditions;

	forest.startFireAt(10, 10);
	simulation(forest, conditions, fire);
};

void Simulation::startSimulationCustomConditions()
{
	Forest forest;

	Fire fire = Fire(&forest);

	system("CLS");
	int windDirection, season, weather = -1;
	defineConditions(windDirection, season, weather, forest);
	Conditions conditions = Conditions(windDirection, season, weather);
	system("CLS");
	simulation(forest, conditions, fire);
};


void Simulation::simulation(Forest& forest, Conditions& conditions, Fire& fire)
{
	bool endSimulation = false;

	std::cin.get();
	Render::setCursorVisability(false);
	while (!endSimulation)
	{
		forest.displayForest(&conditions);

		fire.spreadFire(&conditions);

		std::cout << "\nPress Enter to continue or type 1 to finish simulation\n:> ";
		std::string userInput;
		std::getline(std::cin, userInput);

		if (userInput == "1")
			endSimulation = true;
		if (forest.getBurningTrees() == 0)
		{
			system("cls");
			std::cout << "There are no burning trees left, the simulation is over. \nPress Enter to continue.\n:>";
			std::cin.get();
			endSimulation = true;
		}
		Render::setCursorPosition(0, 0);
	}
};

void Simulation::defineConditions(int& windDirection, int& season, int& weather, Forest& forest)
{
	std::cout << "How many points do you want to start fire at: \n:> ";
	int numberOfFirePoints;
	std::cin >> numberOfFirePoints;


	bool flagForCorrectInput = false;

	for (int i = 0; i < numberOfFirePoints; i++)
	{
		std::cout << std::endl;
		while (!flagForCorrectInput)
		{
			std::cout << "Type the x position of fire point number " << i + 1 << ", the input number should be between 1 and 19\n:>";
			int x;
			std::cin >> x;
			std::cout << "Type the y position of fire point number " << i + 1 << ", the input number should be between 1 and 19\n:>";
			int y;
			std::cin >> y;
			if (x < 1 || x > 19 || y < 1 || y > 19)
				std::cout << "Your input values do not feet the range, please try again\n\n\n";
			else
			{
				flagForCorrectInput = true;
				forest.startFireAt(x, y);
			}
		}
		flagForCorrectInput = false;
	}

	while (!flagForCorrectInput)
	{
		std::cout << "\n\n\nChoose the wind direction:\n1.North \n2.South \n3.West \n4.East \n:> ";
		std::cin >> windDirection;
		if (windDirection < 1 || windDirection > 4)
			std::cout << "There is no such option, please try again\n\n\n";
		else
			flagForCorrectInput = true;
	}

	flagForCorrectInput = false;
	while (!flagForCorrectInput)
	{
		std::cout << "\n\n\nChoose the season: \n1.Winter \n2.Spring \n3.Summer \n4.Autumn \n:>";
		std::cin >> season;
		if (season < 1 || season > 4)
			std::cout << "There is no such option, please try again\n\n\n";
		else
			flagForCorrectInput = true;
	}


	flagForCorrectInput = false;
	while (!flagForCorrectInput)
	{
		std::cout << "\n\n\nChoose the weather: \n1.Sunny \n2.Rainy \n:>";
		std::cin >> weather;
		if (weather < 1 || weather > 2)
			std::cout << "There is no such option, please try again\n\n\n";
		else
			flagForCorrectInput = true;
	}
};

void Simulation::program()
{
	while (!end)
	{
		system("CLS");
		mainScreen();
		std::string userChoice;
		std::cin >> userChoice;
		chooseMenuOptions(userChoice);
	}
};

