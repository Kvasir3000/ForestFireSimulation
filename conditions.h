#ifndef CONDITIONS_H
#define CONDITIONS_H
#include <string>
class Conditions
{
	std::string windDirection; // variable to store wind direction
	std::string season;		   // variable to store season
	std::string weather;	   // variable to store weather 

	/// <summary>
	/// Function to define wind direction with randomizer
	/// </summary>
	void setWindDirection();

	/// <summary>
	/// Function to define season with randomizer
	/// </summary>
	void setSeason();

	/// <summary>
	/// Function to define weather with  randomizer
	/// </summary>
	void setWeather();

	/// <summary>
	/// Function which lets user to define the wind direction  
	/// </summary>
	/// <param name="weatherInp"> Parameter to set the wind direction </param>
	void setWindDirection(int directionInp);

	/// <summary>
	/// Function which lets user to define the wind season  
	/// </summary>
	/// <param name="weatherInp"> Parameter to set the season </param>
	void setSeason(int seasonInp);

	/// <summary>
	/// Function which lets user to define the weather  
	/// </summary>
	/// <param name="weatherInp"> Parameter to set the weather </param>
	void setWeather(int weatherInp);
public:
	/// <summary>
	/// Constructor for the Conditions object, when the user chooses to run simulation with arbitrary parameters
	/// The constructor calls: setWindDirection(), setSeason(), setWeather()
	/// </summary>
	Conditions();

	/// <summary>
	/// Constructor for the Conditions object, when the user chooses to run simulation with customized parameters
	/// The constructor calls: setWindDirection(int directionInp), setSeason(int seasonInp), setWeather(int weatherInp)
	/// The parametres in the Constructor are passed to the functions above 
	/// </summary>
	Conditions(int directionInp, int seasonInp, int weatherInp);

	/// <summary>
	/// Returns the windDirection variable
	/// </summary>
	std::string getWindDirection();

	/// <summary>
	/// Returns the season variable
	/// </summary>
	std::string getSeason();

	/// <summary>
	/// Returns the weather variable
	/// </summary>
	std::string getWeather();
};
#endif // !CONDITIONS_H

