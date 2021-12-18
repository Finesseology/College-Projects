/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#pragma once

#include "LinkedList.h"

class Stack{
    public:
        Stack() { size = 0; }          
        string About();
        void Push(double item);
        double Pop();
        double Peek();
        bool IsEmpty();
    
    private:
        LinkedList<double> list;
        int size;
};