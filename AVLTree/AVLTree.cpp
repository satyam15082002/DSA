// AVL TREE with passing by refrence pointer approach

#pragma once
#include<iostream>
#include<climits>
namespace DSA
{

class AVL
{
    public:
  struct Node
{
    int val;
    Node* L;
    Node* R;
    int height;
    Node(int val):L(NULL),R(NULL),val(val),height(1){}
};   
    Node* root;
    
    AVL():root(NULL){}
    void insert(const int&,Node*&);
    void insert(const int&);
    void remove(const int&,Node*&);
    void remove(const int&);
    void print() ;
    int maxHeight(Node*);
    int getHeight(Node*);
    int getBF(Node*); //For getting balance factor
     void print(Node*) ;
       void LRotate(Node*&);
     void RRotate(Node*&);
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
void AVL::LRotate(Node*& x)
{
Node* y=x->R;
x->R=y->L;
y->L=x;
y->height=1+maxHeight(y);
x->height=1+maxHeight(x);
x=y;    
}
//RRtotations
void AVL::RRotate(Node*& y)
{
Node* x=y->L;
y->L=x->R;
x->R=y;
y->height=1+maxHeight(y);
x->height=1+maxHeight(x);
y=x;    
}

void AVL::insert(const int& val)
{
    insert(val,this->root);
}
void AVL::insert(const int& val,Node* &node)
{
    if(node==NULL)
    {
        node=new Node(val);
        if(this->root==NULL)
         this->root=node;
    }
    else if(val>node->val)
        insert(val,node->R);
    else if(val<node->val)
        insert(val,node->L);
    else{}
    node->height=1+maxHeight(node);
   int BF=getBF(node);
   if(BF>1)
    {
        if(val<node->L->val)
           RRotate(node);
        else
        {
            LRotate(node->L);
            RRotate(node);
        }
        
    }
    if(BF<-1)
    {
        if(val>node->R->val)
            LRotate(node);
        else
        {
            RRotate(node->R);
            LRotate(node);
        }
    }
   
}
void AVL::remove(const int& val)
{
    remove(val,this->root);
}
void AVL::remove(const int& val,Node* &node)
{
    //performing deletion
    if(node==NULL)
    return;
    
    if(val>node->val)
      remove(val,node->R);
    else if(val<node->val)
      remove(val,node->L);
    else if(node->L==NULL||node->R==NULL)
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
        Node *temp;
        temp=minNode(node->R);
        node->val=temp->val;
        remove(temp->val,node->R);
    }
    if(node==NULL)
    return;
      node->height=1+maxHeight(node);
   int BF=getBF(node);
   if(BF>1)
    {
        if(getBF(node->L)>=0)
           RRotate(node);
        else
        {
            LRotate(node->L);
            RRotate(node);
        }
        
    }
    if(BF<-1)
    {
        if(getBF(node->R)<=0)
            LRotate(node);
        else
        {
            RRotate(node->R);
            LRotate(node);
        }
    }
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