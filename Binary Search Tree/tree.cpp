/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Requires LinkedList.h file
*/

#include "tree.h"  


void node::print(int indent) {
    for(int i = 0; i < indent * 4; i++){
        cout << " ";
    }
    cout << "+-- " << key << ": " << value << endl;

    if(left) {
        left->print(indent + 1);
    }
    if(right) {
        right->print(indent + 1);
    }
}


void node::add(int newKey, string newValue) {
    //make a left child
    if(key > newKey) {
        if(left) {
            left->add(newKey, newValue);
        }
        else {
            node *temp = new node();
            temp->right = NULL;
            temp->left = NULL;
            temp->key = newKey;
            temp->value = newValue;
            left = temp;
        }
    }
    //make a right child
    if(key < newKey) {
        if(right) {
            right->add(newKey, newValue);
        }
        else {
            node *temp = new node();
            temp->right = NULL;
            temp->left = NULL;
            temp->key = newKey;
            temp->value = newValue;
            right = temp;
        }
    }
}


string node::find(int findKey) {
    if(key == findKey){
        return value;
    }
    //find left child
    if(key > findKey) {
        if(left) {
            return left->find(findKey);
        }
        else {
            return "";
        }
    }
    //find a right child
    if(key < findKey) {
        if(right) {
            return right->find(findKey);
        }
        else {
            return "";
        } 
    }

}




BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

string BinarySearchTree::about() {
    return "Chris Lemke wrote this BinarySearchTree class.";
}

void BinarySearchTree::print() {
    root->print(0);
}

void BinarySearchTree::add(int key, string value) {
    if(root == NULL){
        node *temp = new node();
        temp->key = key;
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else {
        root->add(key, value);
    }
}

string BinarySearchTree::find(int key) {
    return root->find(key);
}

node* BinarySearchTree::getRoot(){
    return root;
}
