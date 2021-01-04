// AVL tree with return node type approach

#pragma once
#include<iostream>
namespace DSA
{

struct Node
{
    int val;
    Node* L;
    Node* R;
    Node(int val):val(val),L(NULL),R(NULL){}
};
class BST
{
    public:

    Node* root;
    BST():root(NULL){}
    void insert(int);
    Node* insert(int,Node*);
    void remove(int);
    Node* remove(int,Node*);

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


void BST::insert(int val)
{
    this->root=insert(val,this->root);
}
Node* BST::insert(int val,Node* node)
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
    
    return node;
}
void BST::remove(int val)
{
    this->root=remove(val,this->root);
}
Node* BST::remove(int val,Node* node)
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
   
    return node;
    
}
void BST::print() 
{
    print(this->root);
}
void BST::print(Node *node) 
{
    if(node!=NULL)
    {
        print(node->L);
        std::cout<<node->val<<"\t";
          print(node->R);
      
    }
}

}
