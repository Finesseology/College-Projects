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
void Queue::Enqueue(Entry& entry){
    list.AddTail(entry);
    size++;
}

//removes item from top of the stack and returns the value
Entry Queue::Dequeue(){
    Entry e;
    if(list.listSize() == 0){
        cout << "List is already empty. Cannot pop anything." << endl;
        return e;
    }

    e = list.PeekHead();
    list.RemoveHead();
    size--;
    return e;
}

//returns value of head
Entry Queue::Peek(){
    if(list.listSize() == 0){
        Entry e;
        e.key = '\0';
        e.value = '\0';
        cout << "List is empty." << endl;
        return e;
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

//prints to cout
void Queue::printQueue(){
    list.displayList();
}

//prints to defined ostream file
void Queue::printQueueOS(ostream& os){
    list.printQueueOS(os);
}

//overloads so I can print entry
ostream& operator<<(ostream& os, const Entry& entry){
    os << "Key: " << entry.key << "\tValue: " << entry.value;
    return os;
}


