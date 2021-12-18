Author: Chris Lemke
Created October 2021
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Contact: clemke@csus.edu

You might be the first person to ever read one of these. Congrats! GG!

Please note:
    -This code was written for assignment 2 for CSC 130 at Sacramento State University

    -Main makes a queue for the file data. buckets in radixSort are queues.

    -Change the input file where it says: " input.open("years.txt") "

    -Call radixSort(queueToSort, keySize, recordsSize)
        -takes a queue to sort
        -the size of the largest key's value (keySize)
        -the size of the values in the file (recordsSize)

    -There are is 1 output file. 
        -output.txt is the output from the tests ran in main. Honestly I got lazy
        and did not overload for easy printing. It's just a print function. Oh well.

    -The outputting messages do not show every possible step of the sorting code.

    -I could have made the code more efficient with better use of references and pointers and overloading.
     Oh well, time is short and I have other things to do.

    -I did not create a makefile. I am lazy.
        -In linux I ran: g++ main.cpp Queue.cpp -o main