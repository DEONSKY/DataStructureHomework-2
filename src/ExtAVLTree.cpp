
#include "ExtAVLTree.hpp"

int max(int a, int b);  
  
int ExtAVLTree::height(ExtNode* node)  
{  
    if (node == NULL)  
        return 0;  
    return node->height;  
}  

ExtNode* ExtAVLTree::minValueRightNode(ExtNode* node)  
{  
    ExtNode* current = node;  
  

    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
//Opsiyonel yazıldı gerek kalmadı
ExtNode* ExtAVLTree::maxValueLeftNode(ExtNode* node)  
{  
    ExtNode* current = node;  
  

    while (current->right != NULL)  
        current = current->right;  
  
    return current;  
}  

ExtNode* ExtAVLTree::rightRotate(ExtNode *z)  
{  
    ExtNode *y = z->left;  
    ExtNode *T3 = y->right;  
  
    y->right = z;  
    z->left = T3;  
  
    z->height = max(height(z->left), 
                    height(z->right)) + 1;  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
  
    return y;  
}  

ExtNode* ExtAVLTree::leftRotate(ExtNode *z)  
{  
    ExtNode *y = z->right;  
    ExtNode *T1 = y->left;  
  
    y->left = z;  
    z->right = T1;  
  
    z->height = max(height(z->left),     
                    height(z->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    return y;  
}  

int ExtAVLTree::getBalance(ExtNode *node)  
{  
    if (node == NULL)  
        return 0;  
    return height(node->left) - height(node->right);  
}  
  
ExtNode* ExtAVLTree::NewExtNode( string corp,int count,string name,int date ) {
    IntAVLTree *root = new IntAVLTree();
    root->Insert(name,date);
	ExtNode* node = new ExtNode(corp,count,root);
    node->intAVLRoot=root;
	return (node);
}
ExtNode* ExtAVLTree::NewExtNode( ExtNode* node ) {
    string corp = node->corp;
    int count =  node->count;
	ExtNode* newNode = new ExtNode(node->corp,node->count,node->intAVLRoot);
	return (newNode);
}

void ExtAVLTree::Insert(string corp,string name,int date){
    extRoot=Insert(extRoot,corp,name,date);
    //cout<<"extroot: "<<extRoot->corp<<endl;
}
ExtNode* ExtAVLTree::InsertNode(ExtNode* node,ExtNode* newNode){
    if (node == NULL)  {
        //cout<<"corp added : "<<newNode->corp<<endl;
        return (NewExtNode(newNode));
		
    }
    
    if (newNode->count <= node->count){
        //cout<<"inserted left"<<endl;
        node->left = InsertNode(node->left,newNode);  
    }  
    else if (newNode->count > node->count) {
        //cout<<"inserted right"<<endl;
        node->right = InsertNode(node->right,newNode);
    } 

    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
  
/*  //Debug icin
    cout<<endl<<"Insert  :  Node Corp : "<<node->corp<<" height: "<<node->height<<" balance : "<<balance<<" Node count : "<<node->count<<endl;
    if(node->left!=NULL){
        cout<<"Node left count : "<<node->left->count<<endl;
        if(node->left->right!=NULL)
        cout<<"Node left right count : "<<node->left->right->count<<endl;
        if(node->left->left!=NULL)
        cout<<"Node left left count : "<<node->left->left->count<<endl;

    }
    if(node->right!=NULL){
        cout<<"Node right count : "<<node->right->count<<endl;
        if(node->right->left!=NULL)
        cout<<"Node right left count : "<<node->right->left->count<<endl;
        if(node->right->right!=NULL)
        cout<<"Node right right count : "<<node->right->right->count<<endl;
    }
*/
        // Left Left Case  
        if (balance > 1 && newNode->count <= node->left->count){
            //cout<<"LL"<<endl;
            return rightRotate(node);  
        }  

        // Right Right Case
        
        if (balance < -1 && newNode->count > node->right->count) {
            //cout<<"RR"<<endl;
            return leftRotate(node);
        }    

        // Left Right Case  
        if (balance > 1 && newNode->count >= node->left->count)  
        {  
            //cout<<"LR"<<endl;
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  

        //cout<<"new node count"<<newNode->count<<endl;
        // Right Left Case  
        if (balance < -1 && newNode->count < node->right->count)  
        {  
            //cout<<"RL"<<endl;
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  


    return node;
}

ExtNode* ExtAVLTree::SearchInsert(ExtNode* node,string corp, string name,int date,ExtNode* tempExtNode){
    if(node==NULL){
        //cout<<"there is null"<<endl;
        return NULL;
    }

    if(corp== node->corp){

        int tempCount = node->count;
        IntAVLTree *copyOfIntAVLTree = node->intAVLRoot;
        copyOfIntAVLTree->Insert(name,date);
		ExtNode* copyOfExtNode = new ExtNode(corp,tempCount,copyOfIntAVLTree);
        tempExtNode = copyOfExtNode;
        //cout<<node->count<<endl;
        //cout<<"Found corp "<<tempExtNode->corp<<" "<<tempExtNode->count<<endl;
        return tempExtNode;

    }else{
        ExtNode* nl;
        ExtNode* nr;
        nl = SearchInsert(node->left,corp,name, date,tempExtNode);
        if(nl!=NULL)
        tempExtNode=nl;
        
        nr =SearchInsert(node->right,corp,name, date,tempExtNode);
        if(nr!=NULL)
        tempExtNode=nr;

        node->height = 1 + max(height(node->left),  
        height(node->right));  

        if(nr!=NULL||nl!=NULL){
            //cout<<"corps "<<tempExtNode->corp<<endl;
            return tempExtNode;
        }
        return NULL;
    }
}


ExtNode* ExtAVLTree::Delete(ExtNode* node,string corp,int count){
    if (node == NULL)  
        return node;  
    
    if(corp!=node->corp){

        if (count < node->count)  
            node->left = Delete(node->left,corp,count)  ;
        else if (count> node->count)  
            node->right = Delete(node->right,corp,count);
        else{
            node->left = Delete(node->left,corp,count);
            node->right =Delete(node->right,corp,count);
        }
        
        node->height = 1 + max(height(node->left),  
                        height(node->right));  

        //cout<<"Delete on corps "<<node->corp<<endl;
        return node;
      
    }
    else
    {  
        //cout<<"Deleting"<<node->corp<<endl;
        if( (node->left == NULL) || 
            (node->right == NULL) )  
        {  
            ExtNode *temp = node->left ?  
                         node->left :  
                         node->right;  
  
            if (temp == NULL)  
            {  
                temp = node;  
                node = NULL;  
            }  
            else 
            *node = *temp; 
            
            free(temp);  
        }  
        else
        {  

            ExtNode* temp = minValueRightNode(node->right);  
            //cout<<"Min value"<<temp->count<<endl;

            node->corp = temp->corp;
            node->count= temp->count;
            node->intAVLRoot=temp->intAVLRoot;
  
            node->right = Delete(node->right,temp->corp,temp->count);  
        }  
    }  
  
    if (node == NULL)  {
        //cout<<"node is null"<<endl;
        return node;  
    }

    
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
  
/*    Debug için
    cout<<endl<<"  Delete  :  Node Corp : "<<node->corp<<" height: "<<node->height<<" balance : "<<balance<<" Node count : "<<node->count<<endl;
    if(node->left!=NULL){
        cout<<"Node left count : "<<node->left->count<<endl;
        if(node->left->right!=NULL)
        cout<<"Node left right count : "<<node->left->right->count<<endl;
        if(node->left->left!=NULL)
        cout<<"Node left left count : "<<node->left->left->count<<endl;

    }
    if(node->right!=NULL){
        cout<<"Node right count : "<<node->right->count<<endl;
        if(node->right->left!=NULL)
        cout<<"Node right left count : "<<node->right->left->count<<endl;
        if(node->right->right!=NULL)
        cout<<"Node right right count : "<<node->right->right->count<<endl;
    }

*/    
        // Left Left Case  
        if (balance > 1 && getBalance(node->left)>=0){
            //cout<<"LL"<<endl;
            return rightRotate(node);  
        }  

        // Left Right Case  
        if (balance > 1 && getBalance(node->left)<0)  
        {  
            //cout<<"LR"<<endl;
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  


      
    
        // Right Right Case
        
        if (balance < -1 && getBalance(node->right)<=0) {
            //cout<<"RR"<<endl;
            return leftRotate(node);
        }    

        // Right Left Case  
        if (balance < -1 && getBalance(node->left)>0)  
        {  
            //cout<<"RL"<<endl;
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    

    return node;
}

ExtNode* ExtAVLTree::Insert(ExtNode* node,string corp, string name,int date)  
{  
    //cout<<"Start Add "<<corp<<endl;
    ExtNode* tempExtNode;
    tempExtNode = SearchInsert(node,corp,name,date,tempExtNode);

    if(NULL==tempExtNode){

        //cout<<"first add"<<endl;
        tempExtNode=NewExtNode(corp,1,name,date);
        node=InsertNode(node,tempExtNode); 
    }else{
                
        int count = tempExtNode->count;
        node=Delete(node,corp,count);
        tempExtNode->count=count+1;
        node=InsertNode(node,tempExtNode);
        free(tempExtNode);

    }
    //cout<<"Stop Add "<<corp<<endl;
    return node;  
}  

void ExtAVLTree::postOrder(){
    postOrder(extRoot);
}  
void ExtAVLTree::postOrder(ExtNode *node)  
{  
    if (node == NULL)
        return;

    postOrder(node->left);

    postOrder(node->right);

    cout << node->corp << " ";
    //cout << node->height << " ";
    //cout << node->count << " "
    cout<<endl;  
    node->intAVLRoot->postOrder();
    cout<<endl<<endl;
}  

//Debug icin olusturulmus agac yazma fonksiyonları
void ExtAVLTree::parentOrder(){
    parentOrder(extRoot);
}  
void ExtAVLTree::parentOrder(ExtNode *node){
        if (node == NULL)
        return;

    parentOrder(node->left);

    for(int i=0; i<node->height;i++){
        cout<<"-";
    }
    cout <<" Corp:  "<< node->corp << " ";
    cout <<" Height:  "<< node->height << " ";
    cout <<" Count:  "<< node->count << " "<<endl;  

    if(node->left!=NULL){
            for(int i=0; i<node->height;i++){
        cout<<"-";
    }
        cout << " -Left ";
        cout << node->left->corp << " ";
        cout << node->left->height << " ";
        cout << node->left->count << " "<<endl;
    }

    if(node->right!=NULL){
                for(int i=0; i<node->height;i++){
        cout<<"-";
    }
        cout << " -Right ";
        cout << node->right->corp << " ";
        cout << node->right->height << " ";
        cout << node->right->count << " "<<endl;
    }
    node->intAVLRoot->parentOrder();
    //Daha basit görünüm için
    //node->intAVLRoot->inOrder();
    cout<<endl<<endl;

    parentOrder(node->right);


}