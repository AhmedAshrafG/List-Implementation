/*
Created 13 October 2015
Author : Ahmed Ashraf Gamal

Notes : 
-This version of list (generic) supports any abstract data type.
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

template <class T>
class Node{
public:
	T data;
	Node<T>* next;
	Node();
	Node(T x){data = x;}
	Node(T x,Node<T>* n){
		data = x;
		next = n;
	}
};

template <class T>
class List{
	Node<T>* root;
	unsigned int size;
	void Print(Node<T>* x); //recursivly print all the elements.
	void Destroy(Node<T>* n); //recursivly destroy all the elements.
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
	Node<T>* Insert(T x); 
	//insert at a specific index and return a pointer to it
	Node<T>* Insert(T x,int id); 
	//find first occurence of data equals to x and return it's index
	int Find(T x); 
	//get element at specific index
	Node<T>* getKth(int id); 
	//delete first occurence of an element containing data equals to x 
	int Delete(T x); 
	//delete element at a specific index
	void DeleteKth(int id); 
	//print the whole list
	void Print(); 
};

template <class T>
Node<T>* List<T>::Insert(T x){
	return Insert(x,size);
}

template <class T>
Node<T>* List<T>::Insert(T x,int id){
	if (id < 0) return NULL;
	int i = 1;
	Node<T>* currNode = root;
	while(currNode && i < id){
		currNode = currNode->next;
		i++;
	}
	if (id > 0 && currNode == NULL) return NULL;
	Node<T>* newNode;
	if (id){
		newNode = new Node<T>(x,currNode->next);
		currNode->next = newNode;
	}else{
		newNode = new Node<T>(x,root);
		root = newNode;
	}
	size++;
	return newNode;
}

template <class T>
int List<T>::Find(T x){
	int i = 0;
	Node<T>* currNode = root;
	while(currNode  && currNode->data != x){
		currNode = currNode->next;
		i++;
	}
	if (currNode) return i;
	return -1; //indicator
}

template <class T>
Node<T>* List<T>::getKth(int id){
	if (id < 0 || id >= size) return NULL; //indicator, can't use a specific indicator because the type isn't known.
	Node<T>* currNode = root;
	int i = 0;
	while(currNode && i != id){
		currNode = currNode->next;
		i++;
	}
	return currNode;
}

template <class T>
int List<T>::Delete(T x){
	Node<T>* prevNode = NULL;
	Node<T>* currNode = root;
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

template <class T>
void List<T>::DeleteKth(int id){
	if (id < 0 || id >= size) return;
	Node<T>* currNode = root;
	Node<T>* prevNode = NULL;
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

template <class T>
void List<T>::Print(Node<T>* x){
	if (x == NULL)
		return;
	cout << "," << x->data;
	Print(x->next);
}

template <class T>
void List<T>::Print(){
	if (size == 0)
		cout << "List is Empty\n";
	else{
		cout << "{" << root->data;
		Print(root->next);
		cout << "}\n";
	}
}

template <class T>
void List<T>::Destroy(Node<T>* n){
	if (n == NULL)
		return;
	Destroy(n->next); //can't delete 1st then call the next function.
	delete n;
}

template <class T>
List<T>::~List(){
	Destroy(root);
}

void TestDouble(){
	List<double> l;
	l.Insert(2.12);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(3.24,0);
	cout << l.Size() << "\n";
	l.Print();
	l.Delete(3.11);
	cout << l.Size() << "\n";
	l.Print();
	l.Delete(3.24);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(5.842);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(8.15);
	cout << l.Size() << "\n";
	l.Print();
	l.DeleteKth(1);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert(13);
	l.Insert(12.6);
	cout << l.Size() << "\n";
	l.Print();
	Node<double>* node = l.getKth(1);
	if (node)
		cout << node->data << "\n";
	else
		cout << "Invalid Index\n";
}

void TestString(){
	List<string> l;
	l.Insert("ahmed");
	cout << l.Size() << "\n";
	l.Print();
	l.Insert("mohammed");
	cout << l.Size() << "\n";
	l.Print();
	l.Delete("ahmed");
	cout << l.Size() << "\n";
	l.Print();
	l.Delete("Ahmed");
	cout << l.Size() << "\n";
	l.Print();
	l.Insert("Mohammed");
	cout << l.Size() << "\n";
	l.Print();
	l.Insert("Mostafa");
	cout << l.Size() << "\n";
	l.Print();
	l.DeleteKth(1);
	cout << l.Size() << "\n";
	l.Print();
	l.Insert("Ay7aga");
	l.Insert("AyShee2");
	cout << l.Size() << "\n";
	l.Print();
	Node<string>* node = l.getKth(1);
	if (node)
		cout << node->data << "\n";
	else
		cout << "Invalid Index\n";
}

int main(){
	//read("in.txt");
	TestDouble();
	TestString();
}
