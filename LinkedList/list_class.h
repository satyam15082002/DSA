#pragma once 
#include<iostream>


namespace DSA
{

    class SList
    {
        struct Node
        {
            int data;
            Node* next;
            Node(int val):data(val),next(NULL){}
        };
        Node* head;
        public:
            //Constructor & destructor
            SList():head(NULL){}
            ~SList();

            //Traversal
            void display() const; //O(N) N-No. of Elements in List

            //Insertion
            void push_front(int val); //O(1)
            void push_back(int val);  //O(N)

            //Deletion
           void pop_front(); //O(1)
           void pop_back();  //O(N)
           void pop(int val);  //O(N)

           //Reversing
           void reverse(); //Non-recursive approach:-O(N)
           void reverseRecursive();     // recursive approach
           Node* reverseRecursive(Node*&); //recursive approach-O(N)
           void reverseK(int);
           Node* reverseK(Node*&,int);

           //Cycle
           bool detectCycle() const;
           void makeCycle(int);
           void removeCycle();


            //Length
            int length() const;
           //Appending
           void appendk(int k);
           //Put EvenNodesafter Odd
           void putEvenAfterOdd();

           //Merge two sorted list
           void mergeSorted(SList& l2);
    };
}

