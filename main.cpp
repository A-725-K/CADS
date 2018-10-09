#include "sorting_alg.h"

int myArray[N];

int main (int argc, char **argv) {
	if (argc != 2 || atoi(argv[1]) < 0 || atoi(argv[1]) > 7) {
		cerr << "Usage: ./sort <number>" << endl
			 << "1 -> insertion sort" << endl
			 << "2 -> selection sort" << endl
			 << "3 -> merge sort" << endl
			 << "4 -> quick sort" << endl
			 << "5 -> heap sort" << endl
			 << "6 -> stooge sort" << endl
			 << "7 -> bubble sort" << endl;
		return -1;
	}
	
	srand(time(NULL));
	initialize_array();

	cout << "BEFORE:" << endl << endl;
	print_array();

	switch(atoi(argv[1])) {
		case 1:
			cout << "\n++++++++++++++++++++++++++" << endl
				 <<	"+++++ INSERTION SORT +++++" << endl
				 << "++++++++++++++++++++++++++\n" << endl;
			insertion_sort();
			break;
		case 2:
			cout << "\n++++++++++++++++++++++++++" << endl
				 <<	"+++++ SELECTION SORT +++++" << endl
				 << "++++++++++++++++++++++++++\n" << endl;
			selection_sort();
			break;
		case 3:
			cout << "\n++++++++++++++++++++++++++" << endl
				 <<	"+++++++ MERGE SORT +++++++" << endl
				 << "++++++++++++++++++++++++++\n" << endl;
			merge_sort();
			break;
		case 4:
			cout << "\n++++++++++++++++++++++++++" << endl
				 <<	"+++++++ QUICK SORT +++++++" << endl
				 << "++++++++++++++++++++++++++\n" << endl;
			quick_sort();
			break;
		case 5:
			cout << "\n+++++++++++++++++++++++++++" << endl
				 <<	"++++++++ HEAP SORT ++++++++" << endl
				 << "+++++++++++++++++++++++++++\n" << endl;
			heap_sort();
			break;
		case 6:
			cout << "\n+++++++++++++++++++++++++++" << endl
				 <<	"+++++++ STOOGE SORT +++++++" << endl
				 << "+++++++++++++++++++++++++++\n" << endl;
			stooge_sort();
			break;
		case 7:
			cout << "\n+++++++++++++++++++++++++++" << endl
				 <<	"+++++++ BUBBLE SORT +++++++" << endl
				 << "+++++++++++++++++++++++++++\n" << endl;
			bubble_sort();
		default:
			break;		
	}

	cout << "AFTER:" << endl << endl;
	print_array();
	
	cout << endl;
	return 0;
}
