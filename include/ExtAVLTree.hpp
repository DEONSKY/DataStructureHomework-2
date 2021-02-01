
#ifndef ExtAVLTree_HPP
#define ExtAVLTree_HPP
#include "ExtNode.hpp"

class ExtAVLTree {
public:
    void Insert(string corp,string name,int date);
    void postOrder(ExtNode *root)  ;
    void postOrder();
    void parentOrder(ExtNode *node);
    void parentOrder();
private:
    ExtNode* extRoot;
    ExtNode* NewExtNode(string corp,int count, string name ,int date);
    ExtNode* NewExtNode( ExtNode* node );
    int height(ExtNode* node);
    ExtNode* rightRotate(ExtNode *node);
    ExtNode* leftRotate(ExtNode *node);
    int getBalance(ExtNode *node);
    ExtNode* Insert(ExtNode* node,string corp,string name,int date);
    ExtNode* SearchInsert(ExtNode* node,string corp, string name,int date,ExtNode* tempExtNode);
    ExtNode* Delete(ExtNode* node,string corp,int count);
    ExtNode* InsertNode(ExtNode* node,ExtNode* newNode);
    ExtNode* minValueRightNode(ExtNode* node);
    ExtNode* maxValueLeftNode(ExtNode* node);

};
#endif