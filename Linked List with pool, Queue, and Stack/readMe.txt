Author: Chris Lemke
Created Septemeber 2021
Developed for C++ on Red Hat 4.8.5-44
Using g++ (GCC) 4.8.5 20150623
Contact: clemke@csus.edu

You might be the first person to ever read one of these. Congrats! GG!

Please note:
    -This code was written for assignment 1 for CSC 130 at Sacramento State University

    -C++ does not have a generic "Object" type, thus a template is used to pass multiple data types into the LinkedList class

    -There are 2 testing files. 
        -output.txt is the output from the tests ran in main. These test the core functions such as:
        the AddHead, AddTail, RemoveHead, etc from the LinkedList class, and all of the other functions from the    
        Stack and Queue classes. The Stack and Queue classes require the LinkedList.h files

        -Log.txt is the log file for monitoring the pool. Each time I run a test from main,
        there will be a chunk of Log data that will show the nodes being initialized into the pool. 
        Then will track "CheckNode," where it will determine if the pool needs more nodes. Remove head will show 
        the before and after of the list and pool. 

        -null characters might appear as either a 0 or a unknown character (diamond box thing <?>) or as white space, all 3 are null in this case.
        It is because I used a null character for the strings and not a NULL pointer.

        -Log.txt IS an appending log file.

        -output.txt is NOT an appending file.

    -The outputting messages do clutter the code. It could have been done cleaner.

    -I did not create a makefile. 
        -In linux I ran: g++ main.cpp Stack.cpp Queue.cpp -o main