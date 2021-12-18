/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44 
Using g++ (GCC) 4.8.5 20150623
*/

#include "LinkedList.h"
#include "Queue.h"
#include <math.h> 
#include <stdlib.h>

//reads the data from a file into a queue
void readData(ifstream& infile, Queue& q){
    string input;
    bool firstPass = true;

    //get the values of the file.
    while(getline(infile, input)){
        if(firstPass){
            firstPass = false;
        }
        else{
            Entry entry; //create an entry to hold the key, value
            string::size_type pos = input.find(','); //when we find ',' we split
            entry.key = input.substr(0, pos); //up to comma is key
            entry.value = input.substr(pos+1); //after comma is value
            q.Enqueue(entry);
        }
    }
}

void testQueue(ofstream& output, Queue& q){
    //test IsEmpty()
    output << "\n\nIs queue empty? 0 for no, 1 for yes: " << q.IsEmpty() << endl;

    //test Peek()
    output << "\nPeek head: " << q.Peek() << "\n" << endl;

    //test dequeue()
    for(size_t i = 0; i < 5; i++){
        output << "Dequeue head: \n\t" << q.Dequeue() << endl;
    }
    output << "\nPeek head: " << q.Peek() << endl;
}

//takes a queue and sizes and does radix sort
void radixSort(Queue& q, int& keySize, int& recordsSize){
    Queue bucket[10];
    Entry tempEntry;
    int digit, exp;

    for(int i = 0; i < keySize; i++){
        exp = pow(10, i); //get ith place bucket
        for(int j = 0; j < recordsSize; j++){
            //dequeue q as one entry
            tempEntry = q.Dequeue();
            //sort into 10 buckets based on key's values
            digit = (atoi(tempEntry.key.c_str()) / exp) % 10;
            bucket[digit].Enqueue(tempEntry);
        }
        //dequeue the 10 buckets from 0 to 10 into q
        for(int k = 0; k < 10; k++){
            while(!bucket[k].IsEmpty()){
                tempEntry = bucket[k].Dequeue();
                q.Enqueue(tempEntry);
            }
        }
    }
}


int main() {
    ofstream output;
    ifstream input;
    Queue q1;
    int keySize, recordsSize; //for getting initial data sizes for file

    //Open a .txt file that will log all of the testing
    output.open("output.txt");
    if(!output){
        cerr << "Error opening the file." << endl;
    }

    output << "\n\t*---------- Starting Assignment Testing ----------* \n" << endl;

    //Open the file we want to read from
    input.open("years.txt");
    if(!input){
        cerr << "Error opening the file." << endl;
    }

    //get initial data for file sizes
    input >> keySize >> recordsSize;
    output << "Key sizes: " << keySize << "\nRecord sizes: " << recordsSize << "\n" << endl;

    output << q1.About() << endl; //basic information about author

    readData(input, q1); //fill queue with information from input file into the queue

    //print the queue with unsorted data to output file
    output << "Before sorting: " << endl;
    q1.printQueueOS(output);

    radixSort(q1, keySize, recordsSize); //call radix for years file. pass sizes 

    //print the queue with the sorted data to output file
    output << "\n\nAfter sorting the queue: " << endl;
    q1.printQueueOS(output); 


    output << "\n\t*---------- Assignment   Testing   Done ----------* \n" << endl;
    output.close();

    return 0;
}