#pragma once
#include <iostream>
struct node{
	int data;
	node *next;
};



// Creating linked list array

void creat(int A[], size_t sizeOfArray);


// printing the list
void display(node *head);

// Displaying recursivllly
void DisplayRec(node *head);


// Counting the numbers of nodes in linked list 
size_t size(node *head):

// Sum of the nodes data in linked list

size_t add(node *head);

// Sum of the linked list nodes using recursion
size_t addRecursive(node *head):

// finding the maximum element in linked list

int findMax(node *head);

// Finding maximum element using recursive 
int RFindMax(node *head);

// Anotother way to find recursivlly maximum data is using tenerry operation ? : for easier to read
int RFindMax_T(node *head);


// Now we find the minumum in a linked list
int findMinimum(node *head);

// Finding minimum element using recursive 
int RFindMin(node *head);

// Anotother way to find recursivlly min data is using tenerry operation ? : for easier to read
int RFindMin_T(node *head);