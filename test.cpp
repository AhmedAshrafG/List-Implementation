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
#include "List.h"
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
#define N 1030
#define INF INT_MAX
#define vi vector <int>
#define vs vector<string>
#define iv pair <int,vi>
#define pss pair <string,string>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define left(x) (2*x)
#define right(x) (2*x+1)
#define gc getchar_unlocked

int prompt(){
	int x;
	cout << "Please, Select one of the following operations : \n\n";
	cout << "1. Insert element\n";
	cout << "2. Delete element\n";
	cout << "3. Print List\n";
	cout << "4. Print Reversed List\n";
	cout << "5. Swap\n";
	cout << "6. Reverse List\n";
	cout << "Any other number to exit\n";
	cin >> x;
	return x;
}

int main(){
	//read("in.txt");
	List l;
	int x,c;
	do{
		c = prompt();
		switch(c){
			case 1:
				cout << "Please, Enter the number to be Inserted : \n";
				cin >> x;
				l.Insert(x);
				break;
			case 2:
				cout << "Please, Enter the number to be Deleted : \n";
				cin >> x;
				x = l.Delete(x);
				if (x == -1)
					cout << "Element not found!\n";
				break;
			case 3:
				l.Print();
				cout << "\n";
				break;
			case 4:
				l.PrintRev();
				cout << "\n";
				break;
			case 5:
				cout << "Please, Enter the index of the element to be swapped with it's successor : \n";
				cin >> x;
				l.Swap(x);
				break;
			case 6:
				l.Reverse();
				break;
			default:
				return 0;
		}
	}while(c < 7);
}
