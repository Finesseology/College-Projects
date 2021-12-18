/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#pragma once

#include "LinkedList.h"

class Queue{
    public:
        Queue() { size = 0; }          
        string About();
        void Enqueue(string item);
        string Dequeue();
        string Peek();
        bool IsEmpty();
    
    private:
        LinkedList<string> list;
        int size;
};