# CISC 4080 lab2

## Goal:

1. Implement  binarysearch, insertionsort, quicksort, selection, distinct, and sameset functions.
2. Comment on the running time of your algorithms. 
3. Familiarize with C++ STL class **vector**, **unordered_set**.
4. Practice using make and Makefile to compile and test program.
5. Practice reading/writing testcases. 

## Starter Code:

You can download the starter code by download it as a zip file. 

Since a Makefile is provided, you can simply type command make to compile the program.

```
$ cd Lab2/
$ ls
.  ..  main.cpp	Makefile  util.cpp  util.h
$ make
g++ -g --std=c++11 -c main.cpp
g++ -g --std=c++11 -c util.cpp
g++ -o lab2.exe -g --std=c++11 main.cpp util.cpp 

``` 

## General Guidance: 

The provided main.cpp basically test each of the functions one by one using several test cases, and compare the output/result versus the expected ones. You can modify main.cpp to add more test case in order to help debug your code. But you only submit util.cpp, and it will be linked with the original main.cpp. 

You can simply use the following command to compile: 

```
make lab2.exe
```

The above command will use the rules specified in Makefile to compile all .cpp files as needed, and link them to create executable file lab2.exe.

When you run the lab2.exe, it will test all functions one by one and report the results. 
```
./lab2.exe    
```

To test an individual function, pass the testcase and subcase in the command line as follows (where we test the quicksort function):
```
./lab2.exe -tc="lab2" -sc="quicksort"
```

## Submit:
Submit your util.cpp by going to the following autograder page by March 8th, midnight (11:59pm). 

[Lab2 submission site](https://storm.cis.fordham.edu:8443/web/project/1499)

You have a total of 20 submissions opportunities, and 3 submissions on a particular day.
There are two components for the grades:

- Automatic test cases (50 pts):  All test cases are already included in main.cpp:  10 pts for passing the testing of each function. 
- Handgrading (30 pts): style, comment, and logic… 
