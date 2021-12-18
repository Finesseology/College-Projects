/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623

**Note, using templates required functions to be created all in .h file.**
*/

#pragma once

//#include <stdio.h>
//#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

template <typename Object> 
class Node{
    public:
        Object value;
        Node   *next;
};

//LinkedList class using template
template <typename Object> 
class LinkedList{
    public: 
        //contructor for the class
        LinkedList() { 
            pool = NULL;
            head = NULL; 
            tail = NULL; 
            tempNode = NULL;

            linkedListSize = 0; 
            poolSize = 0;
            nodeInitSize = 10;
            nodeCapSize = 20;

            //create a pool of node with nodeInitSize amount of nodes
            createPool();
        } 

        //returns information about the author of the class
        string About() { 
            return "LinkedList class written by: Chris Lemke. I play WoW and sometimes write code.\n";
        }

        //adds a node to the head of the linked list
        void AddHead(Object item){
            checkNode(); //check to ensure the pool is full and able to be used
            tempNode = pool; //copy the pool node into temp
            pool = pool->next; //increment the pool list, removing the head node from pool

            if(head == NULL){
                tempNode->next = NULL; //set temp to point to nothing as it is the only node in list
                tempNode->value = item; //set temp to the value passed in
                head = tempNode; //make the head the created temp node
                tail = tempNode; //make the tail the created temp node
            }
            else{
                tempNode->next = head; //set temp to point to the current head of the list, making this node the new head
                tempNode->value = item; //set temp to the value passed in
                head = tempNode; //make the head the created temp node
            }
            linkedListSize++;
            poolSize--;
            tempNode = NULL;
        }

        //adds a node ot the end of a linked list
        void AddTail(Object item){
            checkNode(); //check to ensure the pool is full and able to be used
            tempNode = pool; //copy the pool node into temp
            pool = pool->next; //increment the pool list, removing the head node from pool
            tempNode->next = NULL; //set temp to point to nothing as it is the last node in list
            tempNode->value = item; //set temp to the value passed in

            if(head == NULL){
                head = tempNode; //make the head the created temp node
                tail = tempNode; //make the tail the created temp node
            }
            else{
                tail->next = tempNode; //set the tails next value to the new tempNode
                tail = tempNode; //make the tail the created temp node
            }
            linkedListSize++;
            poolSize--;
            tempNode = NULL;
        }

        //removes the node at the head of the list
        Object RemoveHead(){
            ofstream log;
            log.open("Log.txt", ios_base::app);
            if( !log ){
                cout << "Error opening the file." << endl;
            }
            tempNode = NULL;

            log << "\n\n\t\t\tRemoveHead():\n List: head:" << head << " head->value: " << head->value << " head->next " << head->next << endl;
            displayPool();

            if(head == NULL){ //if the list is empty, not much we can do.
                log << "The list was already empty, therefore we cannot remove the head." << endl;
                return head->value;
            }
            
            if(poolSize > nodeCapSize){ //if there is a full pool, let the removed node drift away 
                log << "Pool was full. Head: " << head << " head->value: " << head->value << " head->next " << head->next << endl;
                tempNode = head;
                head->value = '\0';
                head = head->next;
                linkedListSize--;
                return tempNode->value;
            }
            else{ //take the head of list, move it to the head of pool. yes there are a lot of comments in the function, I had to mentally trace the path
                log << "If the pool is less than 20:\n\tHead of list: " << head << " head->value: " << head->value << " head->next: " << head->next << endl;
                checkNode();
                displayPool();

                Object test = head->value; //save the value we want to return
                tempNode = head; //copy the head into a tempNode
                head = head->next; //increment the head to remove the head node
                tempNode->value = '\0'; //set value to null prior to putting it into node
                tempNode->next = pool; //set the node to be the front of the pool
                pool = tempNode; //place the head into the front of the pool

                linkedListSize--;
                poolSize++;

                displayPool();
                log << "\n\n" << endl;

                return test;
            }
        }

        //returns the value at the head without removing it
        Object PeekHead(){
            return head->value;
        }

        //Added functions-----------------------------------

        Object PeekTail(){
            return tail->value;
        }

        //prints the contents of the list to cout
        void displayList(){
            Node<Object> *temp = new Node<Object>;
            temp = head;

            cout << "The list contains: " << endl;
            if(temp == NULL) cout << "Nothing, it is an empty List." << endl; 

            while( temp != NULL){
                cout << temp->value << "  " << temp->next << "  ";
                temp = temp->next;
            } 
            cout << "\n";
        }
        
        //returns the size of the LinkedList
        int listSize(){
            return linkedListSize;
        }

        //print pool contents
        void displayPool(){
            //we will log each pool initialization to 'Log.txt'; appending each time it is called
            ofstream log;
            log.open("Log.txt", ios_base::app);
            if( !log ){
                cout << "Error opening the file." << endl;
            }

            log << "Display Pool: \n\tPool contains (Node->value Node->next): ";

            //make a temp node to test against the pool
            Node<Object> *temp = new Node<Object>;
            temp = pool;

            if(temp == NULL) { 
                log << "\tNothing, it is an empty List." << endl; 
            }

            while( temp != NULL){
                log << temp->value << "  " << temp->next << " > ";
                temp = temp->next;
            } 
            log << "\n\tpoolSize: " << poolSize << "\n" <<endl;
            log.close();
        }

        //initializes the pool to be used in the list
        void createPool(){
            //we will log each pool initialization to 'Log.txt'; appending each time it is called
            ofstream log;
            log.open("Log.txt", ios_base::app);
            if( !log ){
                cout << "Error opening the file." << endl; //changed from cerr
            }

            log << "\t\t --- New function call to create a Pool! --- \n\n"
                << "Start of pool creation gives us:\n" << " poolSize: " << poolSize << endl;


            for(size_t i = 0; i < nodeInitSize; i++){
                log << "Lets make a node: " << i << endl;
                addNewPoolNode();
            }
            
            displayPool(); //print pool
            log << "\t\t --- Done creating the pool! --- \n\n\n" << endl;

            log.close();

        }

        //checks to see if the pool is empty. if yes, make a new node for the pool, otherwise relax
        void checkNode(){
            ofstream log;
            log.open("Log.txt", ios_base::app);
            if( !log ){
                cout << "Error opening the file." << endl; //changed from cerr
            }

            log << "Entering CheckNode: poolsize: " << poolSize << endl;

            if(pool == NULL){
                log << "Pool was empty, so we must add a node." << "\n" << endl;
                addNewPoolNode();
                log << "now we have a poolsize of: " << poolSize << "\n" << endl;
            }
  
            log.close();
        }


        //adds a new node to the pool list
        void addNewPoolNode(){
            if(pool == NULL){ //we should make a new pool node at the head with next = NULL
                Node<Object> *temp = new Node<Object>;
                temp->value = '\0';
                temp->next = NULL;
                pool = temp;
            }
            else{ //if the pool isn't empty we should add another node at the head
                Node<Object> *temp = new Node<Object>;
                temp->value = '\0';
                temp->next = pool;
                pool = temp;
            }
            poolSize++;
        }


    private:
        Node<Object> *head, *tail, *pool, *tempNode;
        int linkedListSize, poolSize, nodeInitSize, nodeCapSize;

};