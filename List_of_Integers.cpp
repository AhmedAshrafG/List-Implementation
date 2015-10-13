/*
Created 13 October 2015
Author : Ahmed Ashraf Gamal

Notes : 
-This version of list only supports prespecified abstract data type.
-This is a prototype for a college assignment.
-Functions like void Print(Node* x), void Destroy(Node* n)
were meant to be private in order to be used by member functions only (can't be used by the user directly).
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (int)(n); i++)
#define RFOR(i,x,n) for (int i = (x); i <= (int)(n); i++)
#define take(n) scanf("%d",&n)
#define take2(n,m) scanf("%d%d",&n,&m)
#define take3(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define takell(n) scanf("%lld",&n)
#define takes(n) scanf("%s",n)
#define takef(n) scanf("%lf",&n)
#define ii pair <int,int>
#define is pair <int,string>
#define pdd pair <double,double>
#define ll long long
#define LSB(x) (x & (-x))
#define N 10010
#define vi vector <int>
#define iv pair <int,vi>
#define pss pair <string,string>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define left(x) (2*x)
#define right(x) (2*x+1)

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
	void Destroy(Node* n); //recursivly destroy all elements of the list 
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
	void Print(); 
};

Node* List::Insert(int x){
	return Insert(x,size);
}

Node* List::Insert(int x,int id){
	if (id < 0) return NULL;
	int i = 1;
	Node* currNode = root;
	while(currNode && i < id){
		currNode = currNode->next;
		i++;
	}
	if (id > 0 && currNode == NULL) return NULL;
	Node* newNode;
	if (id){
		newNode = new Node(x,currNode->next);
		currNode->next = newNode;
	}else{
		newNode = new Node(x,root);
		root = newNode;
	}
	size++;
	return newNode;
}

int List::Find(int x){
	int i = 0;
	Node* currNode = root;
	while(currNode  && currNode->data != x){
		currNode = currNode->next;
		i++;
	}
	if (currNode) return i;
	return -1; //indicator
}

Node* List::getKth(int id){ //indicator, can't use a specific indicator because the type isn't known.
	Node<T>* currNode = root;
	if (id < 0 || id >= size) return NULL;
	Node* currNode = root;
	int i = 0;
	while(currNode && i != id){
		currNode = currNode->next;
		i++;
	}
	return currNode;
}

int List::Delete(int x){
	Node* prevNode = NULL;
	Node* currNode = root;
	int i = 0;
	while(currNode && currNode->data != x){
		prevNode = currNode;
		currNode = currNode->next;
		i++;
	}
	if (currNode){
		size--;
		if (prevNode)
			prevNode->next = currNode->next;
		else
			root = currNode->next;

		delete currNode;
		return i;
	}
	return -1; //indicator
}

void List::DeleteKth(int id){
	if (id < 0 || id >= size) return;
	Node* currNode = root;
	Node* prevNode = NULL;
	int i = 0;
	while(currNode && i != id){
		prevNode = currNode;
		currNode = currNode->next;
		i++;
	}
	if (currNode){
		size--;
		if (prevNode)
			prevNode->next = currNode->next;
		else
			root = currNode->next;
		delete currNode;
	}
}

void List::Print(Node* x){
	if (x == NULL)
		return;
	cout << "," << x->data;
	Print(x->next);
}

void List::Print(){
	if (size == 0)
		cout << "List is Empty\n";
	else{
		cout << "{" << root->data;
		Print(root->next);
		cout << "}\n";
	}
}

void List::Destroy(Node* n){
	if (n == NULL)
		return;
	Destroy(n->next);
	delete n;
}

List::~List(){
	Destroy(root);
}

int main(){
	//read("in.txt");
	List l;
	l.Insert(2);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(3,0);
	cout << l.Size() << "\n";
	l.Print();
	l.Delete(3);
	cout << l.Size() << "\n";
	l.Print();
	l.Delete(2);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(5);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(8);
	cout << l.Size() << "\n";
	l.Print();
	l.DeleteKth(1);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(13);
	l.Insert(12);
	cout << l.Size() << "\n";
	l.Print();
	Node* node = l.getKth(1);
	if (node)
		cout << node->data << "\n";
	else
		cout << "Invalid Index\n";
}