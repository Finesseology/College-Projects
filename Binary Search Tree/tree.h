/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#pragma once

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class node {
	public:
		node *left;
		node *right;
		int key;
		string value;
		void print(int indent);
		void add(int newKey, string newValue);
		string find(int key);
};


class BinarySearchTree {
	public:
		BinarySearchTree();
		string about();
		void print();
		void add(int key, string value);
		string find(int key);
		node* getRoot();
	
	private:
		node *root;
};