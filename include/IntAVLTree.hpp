
#ifndef IntAVLTree_HPP
#define IntAVLTree_HPP
#include "IntNode.hpp"
using namespace std;

class IntAVLTree {
public:
    void Insert(string name, int date);
    void postOrder(IntNode *node);
    void postOrder();
    void inOrder(IntNode *node);
    void inOrder();
    void parentOrder();
    void parentOrder(IntNode* node);
private:
    IntNode* intRoot;
    IntNode* NewIntNode(string name ,int date);
    int height(IntNode* N);
    IntNode* rightRotate(IntNode *y);
    IntNode* leftRotate(IntNode *y);
    int getBalance(IntNode *N);
    IntNode* Insert(IntNode* node,string name, int date);

};
#endif