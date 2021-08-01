#ifndef FOREST
#define FOREST

#include "linkedList.h"
#include "conditions.h"
class Forest
{
	/// <summary>
	/// Linked list which stores the trees of the forest
	/// </summary>
	LinkedList forest;
	
	/// <summary>
	/// Variables to store the statistics about the forest
	/// </summary>
	int frame, trees, burningTrees, burntTrees, charredTrees, percentage;

	/// <summary>
	/// Adds trees to the this->forest object, setting up the proper X and Y coordinates 
	/// </summary>
	void populateForest();

	/// <summary>
	/// This function updates the forestCharArray according to the state of the trees in the this->forest list
	/// and updates the statics variables 
	/// </summary>
	void updateMap();

public:

	/// <summary>
	/// Constructor of the class
	/// Creates the LinkedList object, populates forestCharArray with proper symbols, calls populateForest()
	/// </summary>
	Forest();

	/// <summary>
	/// Draws the forestCharArray on hte screen with the statics 
	/// </summary>
	/// <param name="conditions"></param>
	void displayForest(Conditions* conditions);

	/// <summary>
	/// Start fire at given X and Y coordinates when the simulation is started
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void startFireAt(int x, int y);

	/// <summary>
	/// This function gives access to this->forest linked list
	/// </summary>
	/// <returns></returns>
	LinkedList* getLinkedList();

	/// <summary>
	/// This function returns the burningTrees variable
	/// </summary>
	/// <returns></returns>
	int getBurningTrees();

	/// <summary>
	/// A pointer to a two dimensional char array 
	/// </summary>
	char** forestCharArray;

};
#endif // !FOREST

