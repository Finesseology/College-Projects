Author: Chris Lemke
Created October 2021
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Contact: clemke@csus.edu

You might be the first person to ever read one of these. Congrats! GG!

Please note:
    -This code was written for assignment 3 for CSC 130 at Sacramento State University

    -main.cpp makes a BinarySearchTree object

    -There was no reason to use LinkedList or Queue class, thus they are unused.

    -Due to lack of foresight, calling radixSort(infile, outfile, Queue) reads 
     in the correct file, then fills the queue, then sorts, then returns the Queue sorted.

    -There are is no output file. 
        -No real reason other than I just didn't make one.

    -The outputting messages do not show every possible step of the internal tree code.

    -I did actually did create a makefile, enjoy.