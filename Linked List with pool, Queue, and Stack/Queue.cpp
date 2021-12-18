/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44 
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#include "Queue.h"

//returns text about who wrote the class
string Queue::About(){
    return "Queue class written by: Chris Lemke.\n"; 
}

//pushes value into tail
void Queue::Enqueue(string item){
    list.AddTail(item);
    size++;
}

//removes item from top of the stack and returns the value
string Queue::Dequeue(){
    if(list.listSize() == 0){
        cout << "List is already empty. Cannot pop anything." << endl;
        return "";
    }

    string data = list.PeekHead();
    list.RemoveHead();
    size--;
    return data;
}

//returns value of head
string Queue::Peek(){
    if(list.listSize() == 0){
        return "";
    }
    return list.PeekHead();
}

//returns true if stack is empty, false if Queue has values
bool Queue::IsEmpty(){
    if(list.listSize() == 0){
        return true;
    }
    return false;
}