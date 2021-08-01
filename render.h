#ifndef RENDER
#define RENDER
#include <Windows.h>

/// <summary>
/// This class contains two static methods to draw the forest properly on the screen, without flicker
/// </summary>
class Render
{
public:
	/// <summary>
	/// Makes cursor unvisible, if the false value is inputted to the parametr
	/// This is done, so that the user will not be able to see how the cursor is moving during the drawing
	/// </summary>
	/// <param name="visable"></param>
	static void setCursorVisability(bool visable);

	/// <summary>
	/// This function located the cursos to the given coordinates.
	/// Instead of using system("cls"), this function will place the cursor at start of the console and the ouput will be redrawn without the need to clear
	/// the console (which is a very long proccess), as a result the screen stops flickering
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	static void setCursorPosition(int x, int y);
};
#endif