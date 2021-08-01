#ifndef LINKED_LIST
#define LINKED_LIST

#include "tree.h"

class TreeNode: public Tree 
{
	TreeNode* next, *previous;

	public: 
		TreeNode(int x, int y);
		TreeNode* getNext();
		TreeNode* getPrevious();
		void setNext(TreeNode* next);
		void setPrevious(TreeNode* previous);	
};

class LinkedList
{
	TreeNode* start, * end;
	int numberOfElements;

public:
	LinkedList();
	void addTree(int x, int y);
	void deleteTreeAt(int x, int y);
	TreeNode* getTree(int  x, int y);
	int getNumberOfElements();
	TreeNode* getTree(int index);

};
#endif // !LINKED_LIST
