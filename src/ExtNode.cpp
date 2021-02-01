
#include "ExtNode.hpp"

	ExtNode::ExtNode(const string& corp = string(),const int& count = int(), IntAVLTree* intAVLRoot=NULL) {
		this->corp = corp;
		this->count = count;
		this->left = NULL;
		this->right = NULL;
        this->height = 1;
        this->intAVLRoot=intAVLRoot;
	}
