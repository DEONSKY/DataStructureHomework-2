
#include "IntNode.hpp"

	IntNode::IntNode(const string& name = string(),const int& date= int()) {
		this->name = name;
		this->date = date;
		this->left = NULL;
		this->right = NULL;
		this->height = 1;
	}
