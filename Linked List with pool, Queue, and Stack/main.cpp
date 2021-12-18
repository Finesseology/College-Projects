/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44 
Using g++ (GCC) 4.8.5 20150623
*/

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

//these tests are UGLY. Don't mind them...
void testQueue(ofstream& output){
    output << "\n*----- Test Queue: -----* \n" << endl;
    
    //Queue init
    Queue queue_1;

    //test About
    output << "Testing about: \n" << queue_1.About() << "\n";

    //test Enqueue
    output << "Testing Enqueue(): " << "\n";
    output << "\tPeek before Enqueue (If empty, I returned an empty string): " << queue_1.Peek() << "\n";
    queue_1.Enqueue("Line 1");
    output << "\tEnqueue: Line 1\n\t\tPeek: " << queue_1.Peek() << "\n";
    queue_1.Enqueue("Line 2");
    output << "\tEnqueue: Line 2\n\t\tPeek: " << queue_1.Peek() << "\n\n";
    queue_1.Enqueue("Line 3");

    //test Dequeue
    output << "Testing Dequeue(): \n\tWe get: " << queue_1.Dequeue() << "\n\n";

    //test Peek
    output << "Testing Peek(): \n\tCurrent front of the queue is: " << queue_1.Peek() << "\n\n";

    //test IsEmpty
    output << "Testing IsEmpty(): \n\tIs the list empty? 0 for no, 1 for yes: " << queue_1.IsEmpty() << "\n";

    output << "\n*----- Queue Testing Done -----* \n" << endl;

}

void testStack(ofstream& output){
    output << "\n*----- Test Stack: -----* \n" << endl;
    
    //Stack init
    Stack stack_1; 

    //test About
    output << "Testing about: \n\t" << stack_1.About() << "\n";

    //test Push
    output << "Testing Push(): \n";
    output << "\tPeek before pushing: " << stack_1.Peek() << "\n";
    stack_1.Push(12.1);
    output << "\tPushing to stack: 12.1\n\t\tPeek: " << stack_1.Peek() << "\n";
    stack_1.Push(12.2);
    output << "\tPushing to stack: 12.2\n\t\tPeek: " << stack_1.Peek() << "\n";
    stack_1.Push(12.3);
    output << "\tPushing to stack: 12.3\n\t\tPeek: " << stack_1.Peek() << "\n\n";

    //test Pop
    for (size_t i = 0; i < 3; i++){
    output << "Testing Pop(): \n\tReturned: " << stack_1.Pop() << "\n\n";

    output << "Testing Peek(): \n\tPeek: " << stack_1.Peek() << "\n\n";

    output << "Testing IsEmpty(): \n\tIs the list empty? 0 for no, 1 for yes: " << stack_1.IsEmpty() << "\n";
    }

}

void testLinkedList(ofstream& output){
    output << "\n*----- Test LinkedList: -----* \n" << endl;

    //LinkedList init
    LinkedList<int> list_1;

    //test About
    output << "Testing about: \n\t" << list_1.About();

    //test AddHead
    output << "\nTesting AddHead(10): " << "\n";
    list_1.AddHead(10);
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    output << "\tPeekTail: " << list_1.PeekTail() << endl;
    //list_1.displayList();
    output << "\nTesting AddHead(9): " << "\n";
    list_1.AddHead(9);
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    output << "\tPeekTail: " << list_1.PeekTail() << endl;
    //list_1.displayList();

    //test AddTail
    output << "\nTesting AddTail(): " << "\n\n";
    //addtail 11
    output << "\tTesting AddTail(11): " << "\n";
    list_1.AddTail(11);
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    output << "\tPeekTail: " << list_1.PeekTail() << endl;
    //addtail 12
    output << "\n\tTesting AddTail(12): " << "\n";
    list_1.AddTail(12);
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    output << "\tPeekTail: " << list_1.PeekTail() << endl;
    //list_1.displayList();

    //test RemoveHead
    output << "\nTesting RemoveHead(): " << "\n";
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    list_1.RemoveHead();
    output << "\tPeekHead: " << list_1.PeekHead() << endl;
    //list_1.displayList();

    //test PeekHead
    output << "\nTesting PeekHead(): " << "\n\t" << list_1.PeekHead() << endl;

    output << "\n*----- LinkedList Testing Done -----* \n" << endl;
}

int main() {

    //Open a .txt file that will log all of the testing
    ofstream output;
    output.open("output.txt");
    if( !output ){
        cerr << "Error opening the file." << endl;
    }

    output << "\n\t*---------- Starting Assignment Testing ----------* \n" << endl;

    //LinkedList Class
    testLinkedList(output);

    //Stack Class
    //I use this test to check what happens when I remove everything from the list
    testStack(output);

    //Queue Class
    testQueue(output);

    output << "\n\t*----------   Assignment Testing Done   ----------* \n" << endl;

    output.close();

    //create a pool
    return 0;
}