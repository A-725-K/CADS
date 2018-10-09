#include <bits/stdc++.h>

using namespace std;

vector<int> A; 
vector<int> B;
vector<int> C;

long long moves = 0;

//In order to give a pretty output
void print_status() {
	cout << "A:\t";
	for (auto a : A) 
		cout << a << " ";
	cout << endl;
	cout << "B:\t";
	for (auto b : B) 
		cout << b << " ";
	cout << endl;
	cout << "C:\t";
	for (auto c : C) 
		cout << c << " ";
	cout << endl;

	cout << endl << "*************************" << endl << endl;
}

//This function move a disk from tower "from" to tower "to"
void move(vector<int> &from, vector<int> &to) {
	int el = from.back();
	from.pop_back();
	to.push_back(el);
	print_status();
	moves++;
}

//This recursive function resolve the tower of Hanoi in an exponential time
void hanoi(int n, vector<int> &from, vector<int> &to, vector<int> &aux) {
	if (n == 1) {
		move(from, to);
	} else {
		hanoi(n-1, from, aux, to);
		move(from, to);
		hanoi(n-1, aux, to, from);	
	}
}

int main() {
	int n;	//how many disks
	cout << "Insert the number of disks:\t";
	cin >> n;

	for (int i = n; i > 0; i--)
		A.push_back(i);

	cout << endl << "*************************" << endl << endl;

	print_status();
	hanoi(n, A, C, B);

	cout << "To complete the game with " << n << " disks:" << endl;
	cout << "\t" << moves << " moves." << endl;
	return 0;
}
