/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#include "Stack.h"

//returns text about who wrote the class
string Stack::About(){
    return "Stack class written by: Chris Lemke.\n"; 
}

//pushes value into head
void Stack::Push(double item){
    list.AddHead(item);
    size++;
}

//removes item from top of the stack and returns the value
double Stack::Pop(){
    if(list.listSize() == 0){
        cout << "List is already empty. Cannot pop anything." << endl;
        return 0.0;
    }

    double data = list.PeekHead();
    list.RemoveHead();
    size--;
    return data;
}

//returns value of head
double Stack::Peek(){
    if(list.listSize() == 0){
        return 0;
    }
    return list.PeekHead();
}

//returns true if stack is empty, false if stack has values
bool Stack::IsEmpty(){
    if(list.listSize() == 0){
        return true;
    }
    return false;
}