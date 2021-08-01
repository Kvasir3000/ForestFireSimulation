#ifndef FIRE
#define FIRE

#include <string>
#include  "forest.h"
#include "conditions.h"

class Fire
{
	
	Forest* forest;
	/// <summary>
	/// Variable used to store the overall probability of catching a fire for a particular tree
	/// </summary>
	int probability;

	/// <summary>
	/// This function calculates the probability of a particular tree to catch a fire, 
	/// based the wind direction and the tree position in relation to it's neighbors.
	/// If both direction concide the probability is high 
	/// If directions are opposite the probability in almost 0
	/// If none of the above the probability exists, but not very high
	/// </summary>
	/// <param name="windDirection"></param>
	/// <param name="treeDirection"></param>
	/// <returns> The value which will be calculated in the final probability</returns>
	int windDirectionProbability(std::string windDirection, std::string treeDirection);

	/// <summary>
	/// This function calculates probability of a particular tree to catch a fire based on the season 
	/// In summer the probability is very high 
	/// In autumn and spring the probability is smaller than in summer
	/// In winter the probability is low
	/// </summary>
	/// <param name="season"></param>
	/// <returns> The value which will be calculated in the final probability </returns>
	int seasonProbability(std::string season);

	/// <summary>
	/// This function calculates the probability to put out a particular tree from fire, based on the weather 
	/// If the weather is sunny, the tree will not stop burning 
	/// If the weather is rainy, there is a 1/10 probability that it will stop burning and will become charred tree
	/// </summary>
	/// <param name="weather"></param>
	/// <returns></returns>
	int extinguishProbability(std::string weather);

	/// <summary>
	/// This function calculates the average probability of a particular tree to catch a fire based on the values,
	/// returned by seasonProbability() and winDirectionProbability() fuctions, to make simulation more realistic the 
	/// windDirection() output has more weigth in than seasonProbability() output
	/// </summary>
	/// <param name="condition"> Used to pass values to the seasonProbability and windDirectionProbability() parametres </param>
	/// <param name="treeDirection"> Used to pass value to the windDirection() parametre</param>
	void calculateProbability(Conditions* condition, std::string treeDirection);

public:
	/// <summary>
	/// This constructor for the Fire class
	/// </summary>
	/// <param name="forest"> Used to set up the value of this->forest </param>
	Fire(Forest* forest);

	/// <summary>
	/// This function is used to calculate the fire spread in the forest
	/// It takes each tree from the linked list, stored in the *forest objec.
	/// Checks if any of neighbors of the currently chosen tree is burning,
	/// If yes, the  probability to catch the fire for this tree is calculated, in case it exceeds 50%, it will start burning.
	/// </summary>
	/// <param name="conditions"> Used to pass value to the calculateProbability() parametre </param>
	void spreadFire(Conditions* conditions);
};
#endif // !FIRE
