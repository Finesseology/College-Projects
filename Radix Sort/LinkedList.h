/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623

**Note, using templates required functions to be created all in .h file.**
*/

#pragma once

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

//if using templates, entire thing must be done in .h file
template <typename Object> 
class LinkedList{
    public: 
        //contructor for the class
        LinkedList() { head = NULL; tail = NULL; size = 0; } 

        //returns information about the author of the class
        string About() { 
            //cout << "Written by: Chris Lemke. I play WoW, distract myself often, and sometimes write code.\n" << endl; 
            return "LinkedList class written by: Chris Lemke. I play WoW and sometimes write code.\n";
        }

        //adds a node to the head of the linked list
        void AddHead(Object item){
            size++;
            Node<Object> *temp = new Node<Object>;
            temp->value = item;
            temp->next = head;
            
            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else{
                head = temp;
            }
        }

        //adds a node ot the end of a linked list
        void AddTail(Object item){
            size++;
            Node<Object> *temp = new Node<Object>;
            temp->value = item;
            temp->next = NULL;
            
            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else{	
                tail->next = temp;
                tail = temp;
            }
        }

        //removes the node at the head of the list
        Object RemoveHead(){
            size--;
            Node<Object> *temp = new Node<Object>;
            temp = head;

            if(head == NULL){
                cout << "The list was already empty, therefore we cannot remove the head." << endl;
                return head->value;
            }
            else{
                head = head->next;
                return temp->value;
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
            if(temp == NULL) { cout << "Nothing, it is an empty List." << endl; }

            while(temp != NULL){
                cout << temp->value << "\n";
                temp = temp->next;
            } 
            cout << "\n";
        }

        //prints the contents of the list to ostream
        void printQueueOS(ostream& os){
            Node<Object> *temp = new Node<Object>;
            temp = head;

            os << "Contains: " << endl;
            if(temp == NULL) { os << "Nothing, it is an empty List." << endl; }

            while(temp != NULL){
                os << temp->value << "\n";
                temp = temp->next;
            } 
            os << "\n";
        }
        
        //returns the size of the LinkedList
        int listSize(){
            return size;
        }

    private:
        Node<Object> *head, *tail;
        int size;
};



        //maybe use this later?
        /*
        void makeNode(Object item){
            Node<Object> *temp = new Node<Object>;
            temp->value = item;
            temp->next = NULL;
            
            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else{	
                tail->next = temp;
                tail = temp;
            }
        }
        */