#pragma once
#include<iostream>
#include"list_class.h"


namespace DSA
{
    //destructor
    SList::~SList()
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
    void SList::display() const
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

    void SList::push_front(int val)
    {

        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    void SList::push_back(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
            temp=newnode;
        }
    }


    //Deletion
    void SList::pop_front()
    {
        if(head==NULL)
            return;
        else
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void SList::pop_back()
    {
        if(head==NULL)
            return;
        else if(head->next==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            Node* temp=head;
            while(temp->next->next!=NULL)
                temp=temp->next;
            delete temp->next;
            temp->next=NULL;
        }
    }

    void SList::pop(int val)
    {
        if(head==NULL)
            return;
        else if(head->data==val)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            Node* temp=head;
            while(temp!=NULL&&temp->next->data!=val)
            {
                temp=temp->next;
            }
            if(temp==NULL)
                return;
            else
            {
                Node* del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
        }
    }
    // Reversing
    void SList::reverse()
    {
        Node* prevptr=NULL;
        Node* currptr=head;
        Node* nextptr;
        while(currptr!=NULL)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        this->head=prevptr;
    }

    void SList::reverseRecursive()
    {
        this->head=reverseRecursive(this->head);
    }
    SList::Node* SList::reverseRecursive(Node* &fhead)
    {
        if(fhead==NULL||fhead->next==NULL)
            return fhead;
        
        Node* newhead=reverseRecursive(fhead->next);
        fhead->next->next=fhead;
        fhead->next=NULL;
        return newhead;
    }

    void SList::reverseK(int k)
    {
        this->head=reverseK(this->head,k);
    }

    SList::Node* SList::reverseK(Node* &fhead,int k)
    {
        Node* prevptr=NULL;
        Node* currptr=fhead;
        Node* nextptr;
        int count=0;
        while(currptr!=NULL&&count<k)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        if(nextptr!=NULL)
        {
            fhead->next=reverseK(nextptr,k);
        }
        return prevptr;
    }


    //Cycle
    bool SList::detectCycle() const
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }

    void SList::makeCycle(int pos)
    {
        Node* startnode;
        Node* temp=this->head;
        int count=0;
        while(temp->next!=NULL)
        {
            count++;
            if(pos==count)
                startnode=temp;
            temp=temp->next;
        }
        temp->next=startnode;
    }

    void SList::removeCycle()
    {
        Node* slow=head;
        Node* fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        fast=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=NULL;
    }

    //Length
    int SList::length() const
    {
        Node* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    //KAppend

    void SList::appendk(int k)
    {
        Node* newTail;
        Node* newHead;
        Node* tail=head;
        int count=1;
        int l=this->length();
        k=k%l;
        while(tail->next!=NULL)
        {
            if(count==l-k)
                newTail=tail;
            if(count==l-k+1)
                newHead=tail;
            tail=tail->next;
            count++;
        }
        if(k==1)
            newHead=tail;
        newTail->next=NULL;
        tail->next=head;
        head=newHead;
    }

    //putEvenAfterOdd
    void SList::putEvenAfterOdd()
    {
        Node* odd=head;
        Node* even=head->next;
        Node* evenStart=even;
        while(even->next!=NULL&&odd->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            if(odd->next!=NULL)
             even=even->next;
        }
        odd->next=evenStart;

    }
    //Merge sorted List
    void SList::mergeSorted(SList &l2)
    {
       Node* dummyNode=new Node(-1);
       Node* newHead=dummyNode;
       Node* &head2=l2.head;
       while(head!=NULL&&head2!=NULL)
       {
           if(head->data<head2->data)
           {
               dummyNode->next=head;
               dummyNode=dummyNode->next;
               head=head->next;
           }
           else
           {
                dummyNode->next=head2;
                dummyNode=dummyNode->next;
                head2=head2->next;
           }
       }
       if(head!=NULL)
       {
           dummyNode->next=head;
       }
       if(head2!=NULL)
       {
           dummyNode->next=head2;
       }
       head=newHead->next;
       head2=NULL;
    }

}