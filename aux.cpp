#include "sorting_alg.h"

//Print array
void print_array() {
	for (int i = 0; i < N; i++)
		cout << myArray[i] << " ";
	cout << endl;
}

//Print an array
void initialize_array() {
	for (int i = 0; i < N; i++)
		myArray[i] = rand() % N;
}

//Swap two values in an array
void swap(int i, int j) {
	int temp = myArray[i];
	myArray[i] = myArray[j];
	myArray[j] = temp;
}

//Returns the index of the minum element in an array
int index_of_min(int k) {
	int min = numeric_limits<int>::max(), minIndex = N;
	for (int i = k; i < N; i++) 
		if (myArray[i] < min) {
			min = myArray[i];
			minIndex = i;
		}
	return minIndex;	
}

//Insert in order in an array
void insert_in_order(int x, int i) {
	int p = i;
	while (p > 0 && myArray[p-1] > x) {
		myArray[p] = myArray[p - 1];
		p--;
	}
	myArray[p] = x;
}

//Copy an array into another
void copy_array(int aux[], int inf, int sup) {
	for (int i = inf; i < sup; i++)
		myArray[i] = aux[i];
}

//Generate a random pivot and swap it in the first position of the subarray
void rand_pivot(int inf, int sup) {
	int indexP = rand() % (sup - inf + 1) + inf;
	swap(inf, indexP);
}

//Returns the left child of a node
int left(int i) {
	return 2*i + 1;
}

//Returns the right child of a node
int right(int i) {
	return 2*i + 2;
}

//Returns the father of a node
int father(int i) {
	return (i - 1) / 2;
}
