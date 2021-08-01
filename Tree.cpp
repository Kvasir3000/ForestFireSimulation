#include "tree.h"

Tree::Tree() {};

Tree::Tree(int x, int y) { this->x = x; this->y = y; isOnFire = false; charred = false; };

int Tree::getX() { return x; };

int Tree::getY() { return y; };

bool Tree::getState() { return isOnFire; };

void Tree::changeState() { if (!isOnFire) isOnFire = true; };

void Tree::setCharred() { charred = true; };

bool Tree::getCharred() { return charred; };