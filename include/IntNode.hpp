
#ifndef INTNODE_HPP
#define INTNODE_HPP
#include "NULL.hpp"
#include <iostream>

using namespace std;
class IntNode {
public:
	string name;
	int date;
	int height;
	IntNode* left;
	IntNode* right;

	IntNode(const string& ,const int&);
};
#endif