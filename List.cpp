#include <bits/stdc++.h>
#include "List.h"
using namespace std;

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
		cout << "List --> {" << root->data;
		Print(root->next);
		cout << "}\n";
	}
}
void List::PrintRev(Node* x){
	if (x == NULL)
		return;
	PrintRev(x->next);
	cout << x->data << ",";
}
void List::PrintRev(){
	if (size == 0)
		cout << "List is Empty\n";
	else{
		cout << "Reversed List --> {";
		PrintRev(root->next);
		cout << root->data << "}\n";
	}
}
Node* List::Reverse(Node* x,Node* prev){
    if(x->next == NULL) {
        x->next = prev;
        return x;
    }
	Node* tmp;
    tmp = Reverse(x->next, x);
    x->next = prev;
    return tmp;

}
void List::Reverse(){
	root = Reverse(root,NULL);
}
void List::Swap(int id){
	if (id >= size-1){
		cout << "Index error!\n";
	}else if (id == 0){
		Node* A,*B,*C;
		A = root;
		B = A->next;
		C = B->next;
		A->next = C;
		B->next = A;
		root = B;
	}else{
		Node* A,*B,*C,*D;
		A = getKth(id-1);
		B = A->next;
		C = B->next;
		D = C->next;
		A->next = C;
		B->next = D;
		C->next = B;
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
