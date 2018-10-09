#include <bits/stdc++.h>

#define N 100
#define MAX_ATTEMPTS 3

using namespace std;

//Binary search: it works in O(n*log_2(n))
bool binary_search(int a[], int n, int el) {
	int inf = 0, sup = N - 1, mid;
	while(inf <= sup) {
		mid = (inf + sup) / 2;
		if (el < a[mid])
			sup = mid - 1;
		else if (el > a[mid])
			inf = mid + 1;
		else
			return true;
	}

	return false;
}

//Simple game that uses the binary search
int main () {
	srand(time(NULL));

	cout << "In this program there is a vector of 100 random positive integer...\n"
		 << "Your goal is to find a number that there isn't in the vector:\n"
		 << "BE CAREFUL: you have only " << MAX_ATTEMPTS << " attempts !\n"
		 << "Good Luck!" << endl << endl;

	int array[N], el, attempts = 1;
	
	for(int i = 0; i < N; i++)
		array[i] = rand() % 100;

	sort(array, array + N);

	//User interaction
	cout << "Insert a number:\t";
	cin >> el;
	while(binary_search(array, N, el) && attempts < MAX_ATTEMPTS) {
		cout << "Found it, try again." << endl;
		attempts++;
		cout << "Insert a number:\t";
		cin >> el;
	}

	if (attempts == MAX_ATTEMPTS)
		cout << "Sorry, you've lost !" << endl;
	else
		cout << "Congratulations !!!! You have won and " << el 
			 << " is your lucky number !" << endl;

	return 0;	
}
