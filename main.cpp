#include <iostream>
#include "simulation.h"

int main() 
{
	srand(time(NULL));
	Simulation simulation;
	simulation.program();
	system("pause");
	return 0;
}