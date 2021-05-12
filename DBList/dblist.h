#pragma once
#include<iostream>
#include "dblist_class.h"

namespace DSA
{
    //destructor
    DBList::~DBList()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            head=head->next;
            delete temp;
            temp=head;   
        }
    }

        //Traversal
    void DBList::display() const
    {
        if(head==NULL)
            return;
        else
        {
            Node* temp=head;
            while(temp!=NULL)
            {
                std::cout<<temp->data<<"->";
                temp=temp->next;
            }
            std::cout<<"NULL"<<std::endl;
        }
    }


    //Inserting
    void DBList::push_front(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
            head=newnode;
        else
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void DBList::push_back(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
            head=newnode;
        else
        {
            Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
        }
    }

    //Deletion

    void DBList::pop_front()
    {
        if(head==NULL)
            return;
        Node* temp=head;
        if(head->next!=NULL)
            head->next->prev=NULL;
        head=head->next;
        delete temp;
    }

    void DBList::pop_back()
    {
        if(head==NULL)
            return;
        Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev!=NULL)
            temp->prev->next=NULL;
        delete temp;
    }

    void DBList::pop(int pos)
    {
        if(head==NULL)
            return;
        Node* temp=head;
        int count=1;
        while(temp!=NULL&&count<pos)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
            return;
        if(count==1)
        {
           this->pop_front();
           return;
        }
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        if(temp->prev!=NULL)
            temp->prev->next=temp->next;
        delete temp;
    }

    // Reversing
    void DBList::reverse()
    {
        Node* prevptr=NULL;
        Node* currptr=head;
        Node* nextptr;
        while(currptr!=NULL)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            currptr->prev=nextptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        this->head=prevptr;
    }

}