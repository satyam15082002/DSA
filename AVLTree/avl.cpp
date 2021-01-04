/* AVL tree with return node type approach*/
#pragma once
#include<iostream>
#include<climits>

namespace DSA
{

struct Node
{
    int val;
    int height;
    Node* L;
    Node* R;
    Node(int val):val(val),height(1),L(NULL),R(NULL){}
};
class AVL
{
    public:
    Node* root;
    AVL():root(NULL){}
    void insert(int);
    Node* insert(int,Node*);
    void remove(int);
    Node* remove(int,Node*);
    int getBF(Node*);
    int getHeight(Node*);
    int maxHeight(Node*);
    Node* LRotate(Node*);
    Node* RRotate(Node*);
      void print() ;
      void print(Node*) ;
    Node* minNode(Node* node)
    {
        Node* curr=node;
        while (curr->L!=NULL)
            curr=curr->L;
        return curr;
    }
};

int AVL::getBF(Node* node)
{
    return getHeight(node->L)-getHeight(node->R);
}
int AVL::maxHeight(Node* node)
{
return max(getHeight(node->L),getHeight(node->R));
}
//getting height
int AVL::getHeight(Node* node)
{
if(node==NULL)
return 0;
return node->height;
}
//Rotations For Avl Tree
Node* AVL::LRotate(Node* x)
{
Node* y=x->R;
Node* temp=y->L;
y->L=x;
x->R=temp;
y->height=1+maxHeight(y);
x->height=1+maxHeight(x);
return y;
}
//RRtotations
Node* AVL::RRotate(Node* y)
{
Node* x=y->L;
Node* temp=x->R;
x->R=y;
y->L=temp;
y->height=1+maxHeight(y);
x->height=1+maxHeight(x);
return x;    
}
void AVL::insert(int val)
{
    this->root=insert(val,this->root);
}
Node* AVL::insert(int val,Node* node)
{
    if(node==NULL)
    {
        node=new Node(val);
        return node;
    }
    else if(val<node->val)
      node->L=insert(val,node->L);
    else if(val>node->val)
      node->R=insert(val,node->R);
    else
       return node;
    node->height=1+maxHeight(node);
    int BF=getBF(node);
    if(BF>1)
    {
        if(val<node->L->val)
        return RRotate(node);
        else
        {
            node->L=LRotate(node);
            return RRotate(node);
        }
    }
    if(BF<-1)
    {
        if(val>node->R->val)
        return LRotate(node);
        else
        {
            node->R=RRotate(node->R);
            return LRotate(node);
        }
        
    }
    return node;
}
void AVL::remove(int val)
{
    this->root=remove(val,this->root);
}
Node* AVL::remove(int val,Node* node)
{
    if(node==NULL)
    return node;
    else if(val<node->val)
       node->L=remove(val,node->L);
    else if(val>node->val)
       node->R=remove(val,node->R);
    else if (node->L==NULL||node->R==NULL)
    {
        Node* temp;
        temp=node->L==NULL?node->R:node->L;
        if(temp==NULL)
        {
            temp=node;
            node=NULL;
        }
        else
          *node=*temp;
        delete temp;
    }
    else
    {
        Node* temp;
        temp=minNode(node->R);
        node->val=temp->val;
        node->R=remove(temp->val,node->R);
    }
    if(node==NULL)
    return node;
    node->height=1+maxHeight(node);
    int BF=getBF(node);
    if(BF>1)
    {
        if(getBF(node->L)>=0)
        return RRotate(node);
        else
        {
            node->L=LRotate(node);
            return RRotate(node);
        }
    }
    if(BF<-1)
    {
        if(getBF(node->R)<=0)
        return LRotate(node);
        else
        {
            node->R=RRotate(node->R);
            return LRotate(node);
        }
        
    }
    return node;
    
}
void AVL::print() 
{
    print(this->root);
}
void AVL::print(Node *node) 
{
    if(node!=NULL)
    {
        print(node->L);
        std::cout<<node->val<<"\t";
          print(node->R);
      
    }
}


}