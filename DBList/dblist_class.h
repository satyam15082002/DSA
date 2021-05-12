#pragma once
#include<iostream>

namespace DSA
{

    class DBList
    {
        private:
            struct Node
            {
                int data;
                Node* prev;
                Node* next;
                Node(int val):data(val),prev(NULL),next(NULL){}
            };
            Node* head;
        
        public:

            //Constructor & destructor
            DBList():head(NULL){}
            ~DBList();

            //Traversal
            void display() const; //O(N) N-No. of Elements in List


            //Insertion
            void push_front(int val); //O(1)
            void push_back(int val);  //O(N)
        

            //Deletion
            void pop_front(); //O(1)
            void pop_back();  //O(N)
            void pop(int pos);//O(N);

             //Reversing
            void reverse(); //Non-recursive approach:-O(N)
    };


}