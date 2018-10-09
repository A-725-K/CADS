#include <bits/stdc++.h>

#define N 30

using namespace std;

int myArray[N];

//it generates a simple bitonix sequence
void generate_bitonic_seq() {
	for (int i = 0; i < N/2; i++) {
		myArray[i] = i;
	}

	for (int i = N/2; i < N; i++) {
		myArray[i] = N-i;
	}
}

//it generates a simle non-bitonic sequence
void generate_seq() {
	for (int i = 0; i < N; i++)
		myArray[i] = i;
}

//Returns the index where the sequence becomes decreasing
int calculate_index(int inf, int sup) {
	if (sup - inf <= 2)
		return -1;

	int mid = (inf + sup)/2;

#ifdef DEBUG
cout << "inf= " << inf << endl;
cout << "mid= " << mid << endl;
cout << "sup= " << sup << endl;
#endif

	if (myArray[mid] > myArray[mid + 1] && myArray[mid] > myArray[mid - 1])
		return mid;
	else if (myArray[mid] < myArray[mid + 1]) 
		return calculate_index(mid, sup);
	return calculate_index(inf, mid);
}

int main (int argc, char **argv) {
	/* COMMENT ONE OF THE FOLLOWING TWO LINES */
	generate_bitonic_seq();
	//generate_seq();

	cout << "The sequence is:" << endl;
	for (int i = 0; i < N; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl << endl;

	int index = calculate_index(0, N - 1);

	if (index == -1) {
		cout << "The sequence isn't bitonic !" << endl;
	} else {
		cout << "The index of the changing monotony is " << index << "." << endl;
	}

	return 0;
}
