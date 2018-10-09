#include <bits/stdc++.h>

#define N 100

using namespace std;

extern int myArray[N];

//Sorting algorithm
void insertion_sort();
void selection_sort();
void merge_sort();
void quick_sort();
void heap_sort();
void stooge_sort();
void bubble_sort();

//Auxiliary functions
void print_array();
void initialize_array();
void swap(int, int);
int index_of_min(int);
void insert_in_order(int, int);
void copy_array(int[], int, int);
void rand_pivot(int, int);
int left(int);
int right(int);
int father(int);
