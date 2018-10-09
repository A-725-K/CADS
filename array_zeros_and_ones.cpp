#include <bits/stdc++.h>

#define N 10

using namespace std;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;	
}

void print_array(int a[], string msg) {
	cout << msg << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

int main (int argc, char **argv) {
	int array[N];
	int times, last_0, first_1, howManyZeros, howManyOnes;
	
	srand(time(NULL));

	if (argc != 2 || (times = atoi(argv[1])) < 0) {
		cerr << "Usage: ./zerosones <times>\ntimes must be a positive integer" << endl;
		return -1;
	}

	for (int t = 0; t < times; t++) {
		last_0 = howManyZeros = howManyOnes = 0;
		first_1 = N-1;

		for (int i = 0; i < N; i++) {
			array[i] = rand() % 2;
			if (array[i] == 0)
				howManyZeros++;
			else
				howManyOnes++;
		}
		cout << "Attempt:\t" << t + 1 << endl;
		cout << "Zeros:\t" << howManyZeros << "\tOnes:\t" << howManyOnes << endl << endl;
		print_array(array, "Before:");

		while(last_0 < first_1) {
			if (array[last_0] == 0)
				last_0++;
			else if (array[first_1] == 1)
				first_1--;
			else {
				swap(array, last_0, first_1);
				last_0++;
				first_1--;
			}
		}

		print_array(array, "After:");

		cout << "_____________________________________" << endl << endl;
	}

	return 0;
}
