#pragma once
#include<iostream>
namespace DSA
{
    
class BST
{
    public:
  struct Node
  {
    int val;
    Node* L;
    Node* R;
    Node(int val):L(NULL),R(NULL),val(val){}
  };   
    Node* root;
    BST():root(NULL){}
    void insert(const int&,Node*&);
    void insert(const int&);
    void remove(const int&,Node*&);
    void remove(const int&);
    void print() const;
     void print(Node*) const;
     Node* minNode(Node* node)
{
        if(node==NULL)
        return node;
        while (node->L!=NULL)
            node=node->L;
        return node;
}
};
void BST::insert(const int& val)
{
    insert(val,this->root);
}
void BST::insert(const int& val,Node* &node)
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
}
void BST::remove(const int& val)
{
    remove(val,this->root);
}
void BST::remove(const int& val,Node* &node)
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
    
}
void BST::print() const
{
    print(this->root);
}
void BST::print(Node *node) const
{
    if(node!=NULL)
    {
        print(node->L);
        std::cout<<node->val<<"\t";
          print(node->R);
      
    }
}


}