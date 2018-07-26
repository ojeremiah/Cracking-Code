// ReversingA_LinkedList.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node //Node structure
{
	int data;
	Node* next;

	public:
		Node();
		Node(int);
};

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int n)
{
	data = n;
	next = NULL;
}
//Global Variables
Node* top = NULL;

//Prototypes
void ReverseLinkedList();
void InsertNode(int);
void PrintList();

//MAIN
int main()
{
	InsertNode(7); InsertNode(4); InsertNode(6); InsertNode(2);
	PrintList();

	ReverseLinkedList();
	PrintList();

    return 0;
}

void ReverseLinkedList()
{
	//Node pointers
	Node* prev = NULL;
	Node* curr = NULL;
	Node* next = NULL;
	
	prev = NULL;
	curr = top;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	top = prev;
}

void InsertNode(int num)
{
	Node* nodePtr = NULL;
	Node* curr = NULL;

	if (top == NULL) //if linked list is empty
	{
		nodePtr = new Node(num); // node pointer points to a new node
		nodePtr->next = NULL;
		top = nodePtr;
	}
	else
	{
		nodePtr = new Node(num); //node pointer points to a new node
		nodePtr->next = NULL;

		curr = top; //start at the top of linked list
		while (curr->next != NULL)//iterate through every node to get the last node
		{
			curr = curr->next; //go to next node
		}
		curr->next = nodePtr; //when at the end of list, last node now points to the new node ending the list
	}
}

void PrintList()
{
	Node* curr = NULL;
	curr = top;

	while (curr->next != NULL) //iterate through list
	{
		cout << curr->data << " "; //display current node data
		curr = curr->next; //go to next node
	}
	cout << curr->data;

	cout << endl;
}