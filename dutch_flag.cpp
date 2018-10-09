#include <bits/stdc++.h>

#define N 20

#define RED 0
#define WHITE 1
#define BLUE 2
typedef int col;

using namespace std;

col flag[N];

col color(int i) {
	return flag[i];
}	

void swap(int i, int j) {
	col temp = flag[i];
	flag[i] = flag[j];
	flag[j] = temp;
}

void initialize_unordered_flag() {
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		flag[i] = rand() % 3;
}

void print_flag(string msg) {
	cout << msg << endl;
	for (int i = 0; i < N; i++)
		switch(flag[i]) {
			case RED:
				cout << "R";
				break;
			case WHITE:
				cout << "W";
				break;
			case BLUE:
				cout << "B";
				break;
		}
	cout << endl << endl;
}

void order() {
	int u1 = 0;
	int w1 = N;
	int b1 = N;

	while(u1 < w1) {
		switch(color(w1-1)) {
			case WHITE:
				w1--;
				break;
			case RED:
				swap(u1, w1-1);
				u1++;
				break;
			case BLUE:
				swap(w1-1, b1-1);
				b1--;
				w1--;
				break;
		}
	}	
}

int main() {
	initialize_unordered_flag();
	print_flag("Before:");
	order();
	print_flag("After:");
	return 0;
}
