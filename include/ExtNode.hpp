
#ifndef EXTNODE_HPP
#define EXTNODE_HPP
#include "IntAVLTree.hpp"

class ExtNode {
public:
	string corp;
	int count;
    IntAVLTree* intAVLRoot;
    int height;
	ExtNode* left;
	ExtNode* right;

	ExtNode(const string& ,const int&,IntAVLTree*);
};
#endif