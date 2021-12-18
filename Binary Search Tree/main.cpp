/*
Author: Chris Lemke
Developed for C++ on Red Hat 4.8.5-44 
Using g++ (GCC) 4.8.5 20150623
*/

#include "tree.h"


int main() {

    cout << "\n\t*---------- Starting Assignment Testing ----------* \n" << endl;

    BinarySearchTree tree;

    cout << tree.about() << "\n" << endl;

    tree.add(10, "Bufallo Wings");
    tree.add(43, "Cheez Whiz");
    tree.add(18, "Root beer");
    tree.add(6, "Pringles");
    tree.add(50, "Ice Cream");
    tree.add(8, "Chocolate");
    cout << "Printing BST tree: \n" << endl;   
    tree.print();
    cout << "\nFind: \tKey: 8: Value: Chocolate. \n\tWhat was found: " << tree.find(8) << endl;
    cout << "\nFind: \tKey: 4: Value: No node. \n\tWhat was found: " << tree.find(4) << endl;

    cout << "\n\t*---------- Assignment   Testing   Done ----------* \n" << endl;

    return 0;
}