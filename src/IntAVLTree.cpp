
#include "IntAVLTree.hpp"


int max(int a, int b);  

//Node un derinlik bilgisini dondurur  
int IntAVLTree::height(IntNode *node)  
{  
    if (node == NULL)  
        return 0;  
    return node->height;  
}  

//Iki değeri kıyaslar buyuk olanı doner   
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
//z nin solundaki node un sagina z yi aliyor. Yerine koydugu node u da z nin kopartilan dalina atiyor 
IntNode* IntAVLTree::rightRotate(IntNode *z)  
{  
    IntNode *y = z->left;  
    IntNode *T3 = y->right;  
  
    y->right = z;  
    z->left = T3;  
  
    z->height = max(height(z->left), 
                    height(z->right)) + 1;  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
  
    return y;  
}  
//Ustteki islemleri farkli yonde yapiyor
IntNode* IntAVLTree::leftRotate(IntNode *z)  
{  
    IntNode *y = z->right;  
    IntNode *T1 = y->left;  
  
    y->left = z;  
    z->right = T1;  
  
    z->height = max(height(z->left),     
                    height(z->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    return y;  
}  
//iki dalin uzunlugunu kıyaslıyor
int IntAVLTree::getBalance(IntNode *node)  
{  
    if (node == NULL)  
        return 0;  
    return height(node->left) - height(node->right);  
}  
  
IntNode* IntAVLTree::NewIntNode( string name , int date) {
	IntNode* node = new IntNode(name,date);
	return (node);
}

void IntAVLTree::Insert(string name, int date){
    intRoot=Insert(intRoot,name,date);
}

IntNode* IntAVLTree::Insert(IntNode* node,string name, int date)  
{  

    if (node == NULL)  
        return(NewIntNode(name,date));  
  
    if (date >= node->date)  
        node->left = Insert(node->left,name, date);  
    else if (date < node->date)  
        node->right = Insert(node->right,name, date);  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
  
    // Left Left Case  
    if (balance > 1 && date >= node->left->date)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && date < node->right->date)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && date <= node->left->date)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && date > node->right->date)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  
  
void IntAVLTree::postOrder(){
    postOrder(intRoot);
}  
void IntAVLTree::postOrder(IntNode *node)  
{  
    if (node == NULL)
        return;

    postOrder(node->left);

    postOrder(node->right);

    cout << node->name << "-";
    cout << node->date;
    if(node!=intRoot)
    cout<< " | ";  
}  
//Alttaki yazdırma fonksiyonları kontrol islemini kolaylastırmak icin kullanıldılar
void IntAVLTree::inOrder(){
    inOrder(intRoot);
}  
void IntAVLTree::inOrder(IntNode *node)  
{  
    if (node == NULL)
        return;

    inOrder(node->left);

    cout << node->name << " ";
    cout << node->date << " | ";  

    inOrder(node->right);

}  
void IntAVLTree::parentOrder(){
    parentOrder(intRoot);
}  
void IntAVLTree::parentOrder(IntNode *node){
        if (node == NULL)
        return;

    parentOrder(node->left);

    for(int i=0; i<node->height;i++){
        cout<<"-";
    }
    cout <<" Name:  "<< node->name << " ";
    cout <<" Height:  "<< node->height << " ";
    cout <<" Date:  "<< node->date << " "<<endl;  

    if(node->left!=NULL){
            for(int i=0; i<node->height;i++){
        cout<<"-";
    }
        cout << " -Left ";
        cout << node->left->name << " ";
        cout << node->left->height << " ";
        cout << node->left->date << " "<<endl;
    }

    if(node->right!=NULL){
                for(int i=0; i<node->height;i++){
        cout<<"-";
    }
        cout << " -Right ";
        cout << node->right->name << " ";
        cout << node->right->height << " ";
        cout << node->right->date << " "<<endl;
    }
    cout<<endl;
    parentOrder(node->right);


}
  
  