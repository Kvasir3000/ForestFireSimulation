#include "linkedList.h"
#include <iostream>

TreeNode::TreeNode(int x, int y) :Tree(x, y) {};

void TreeNode::setNext(TreeNode* next) { this->next = next; };

void TreeNode::setPrevious(TreeNode* previous) { this->previous = previous; };

TreeNode* TreeNode::getNext() { return next; };

TreeNode* TreeNode::getPrevious() { return previous; };


LinkedList::LinkedList() { start = NULL, end = NULL; numberOfElements = 0; }

void LinkedList::addTree(int x, int y)
{
	if (start == NULL)
	{
		TreeNode* current = new TreeNode(x, y);
		start = current;
		end = current;
	}
	else
	{
		TreeNode* current = new TreeNode(x,y);
		end->setNext(current);

		if (start == end)
			current->setPrevious(start);
		else
			current->setPrevious(end);

		end = current;
	}
	numberOfElements++;
};

void LinkedList::deleteTreeAt(int x, int y) 
{
	TreeNode* current = start;

	while (current->getX() != x || current->getY() != y) 
	{
		current = current->getNext();
	}

	if (current == start) 
	{
		start = current->getNext();

		if (start != NULL) 
			start->setPrevious(NULL);
		
		delete current;
	}
	else if (current == end)
	{
		end = current->getPrevious();
		end->setNext(NULL);
		delete current;
	}
	else 
	{
		current->getPrevious()->setNext(current->getNext());
		current->getNext()->setPrevious(current->getPrevious());
		delete current;
	}
	--numberOfElements;
};

TreeNode* LinkedList::getTree(int x, int y) 
{
	TreeNode* current = start;
	
	while (current->getX() != x || current->getY() != y) 
	{
		current = current->getNext();
		
		if (current == end && (current->getX() != x && current->getY() != y))
		{
			current = NULL;
			break;
		}
	}
	return current;
};

TreeNode* LinkedList::getTree(int index)
{
	TreeNode* current = start;

	for (int i = 0; i < index; i++)
		current = current->getNext();

	return current;
};

int LinkedList::getNumberOfElements() { return numberOfElements; }; 