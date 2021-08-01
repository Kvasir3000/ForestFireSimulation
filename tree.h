#ifndef TREE
#define TREE

class Tree
{
protected:
	int x, y;			// stores the coordinates of the tree
	bool isOnFire;		// true => the tree is burning, false => the tree is not burning
	bool charred;       // true => the tree is charred 
public :
	Tree();

	/// <summary>
	/// Constructor which for Tree class which sets the coordinates of Tree object.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Tree(int x, int y);

	/// <summary>
	/// Returns the x coordinate of the tree
	/// </summary>
	/// <returns> x variable </returns>
	int getX();

	/// <summary>
	/// Returns the y coordinate of the tree
	/// </summary>
	/// <returns> y variable </returns>
	int getY();
	
	/// <summary>
	/// Returns the state of the tree (if tree is on fire or not)
	/// </summary>
	/// <returns> isOnFire variable </returns>
	bool getState();

	/// <summary>
	/// Sets the isOnFire to true
	/// </summary>
	void changeState();

	/// <summary>
	/// Sets the charred variable to true value
	/// </summary>
	void setCharred();

	/// <summary>
	/// Shows whether the tree is charred or not 
	/// </summary>
	/// <returns> charred variable </returns>
	bool getCharred();
};
#endif // !TREE
