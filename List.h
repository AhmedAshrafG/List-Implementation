#pragma once

class Node{
public:
	int data;
	Node* next;
	Node();
	Node(int x){data = x;}
	Node(int x,Node* n){
		data = x;
		next = n;
	}
};

class List{
	Node* root;
	unsigned int size;
	void Print(Node* x); //recursivly print all elements
	void PrintRev(Node* x); //recursivly print all elements (reversed)
	void Destroy(Node* n); //recursivly destroy all elements of the list 
	Node* Reverse(Node* n,Node* prev); //recursivly reverse all elements of the list 
public:
	//constructor
	List(){root = NULL; size = 0;}
	//destructor
	~List();
	//check whether the list is empty or not
	bool isEmpty(){return root == NULL;}
	//get the current size of the list
	unsigned int Size(){return size;}
	//insert at the end of the list and return a pointer to it
	Node* Insert(int x); 
	//insert at a specific index and return a pointer to it
	Node* Insert(int x,int id); 
	//find first occurence of data equals to x and return it's index
	int Find(int x); 
	//get element at specific index
	Node* getKth(int id); 
	//delete first occurence of an element containing data equals to x 
	int Delete(int x); 
	//delete element at a specific index
	void DeleteKth(int id); 
	//print the whole list
	void Reverse();
	//reverses the list
	void Print(); 
	//print the whole list (reversed)
	void PrintRev(); 
	//swaps the element with the "id" with it's successor
	void Swap(int id);
};
