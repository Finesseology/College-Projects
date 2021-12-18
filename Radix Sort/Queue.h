/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#pragma once

#include "LinkedList.h"

class Entry{
    public:
        string key;
        string value;
        friend ostream& operator<<(ostream& os, const Entry& entry);
};

class Queue{
    public:
        Queue() { size = 0; }        
        string About();
        void Enqueue(Entry& entry);
        Entry Dequeue();
        Entry Peek();
        bool IsEmpty();
        void printQueue();
        void printQueueOS(ostream& os);
    
    private:
        LinkedList<Entry> list;
        int size;
};