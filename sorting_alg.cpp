#include "sorting_alg.h"

// --- INSERTION SORT ---
void insertion_sort() {
	int i = 1, temp;
	while(i < N) {
		temp = myArray[i];
		insert_in_order(temp, i);
		i++;
	}	
}

// --- SELECTION SORT ---
void selection_sort() {
	int i = 0, k;
	while (i < N) {
		k = index_of_min(i);
		swap(i, k);
		i++;
	}
}

// --- MERGE SORT ---
void merge(int inf, int mid, int sup, int aux[]) {
	int i = inf, j = mid + 1, k = inf;
	while (i < mid + 1 && j < sup) {
		if (myArray[i] <= myArray[j]) {
			aux[k] = myArray[i];
			i++;
		} else {
			aux[k] = myArray[j];
			j++;	
		}
		k++;
	}

	while (i < mid + 1) {
		aux[k] = myArray[i];
		i++;
		k++;
	}
	while (j < sup + 1) {
		aux[k] = myArray[j];
		j++;
		k++;
	}

	copy_array(aux, inf, sup + 1);
}

void merge_sort_ric(int inf, int sup, int aux[]){
	if (inf >= sup)
		return;

	int mid = (inf + sup) / 2;
	merge_sort_ric(inf, mid, aux);
	merge_sort_ric(mid + 1, sup, aux);
	merge(inf, mid, sup + 1, aux);
	
}

void merge_sort() {
	int aux[N];
	merge_sort_ric(0, N - 1, aux);
}

// --- QUICK SORT ---
void quick_sort_ric(int inf, int sup) {
	if (inf >= sup)
		return;
	rand_pivot(inf, sup);
	int pivot = myArray[inf], j = inf + 1, i = inf;
	while (j < sup + 1) {
		if (myArray[j] < pivot) {
			swap(j, i + 1);
			i++;
		}
		j++;
	}
	swap(inf, i);
	quick_sort_ric(inf, i - 1);
	quick_sort_ric(i + 1, sup);
}

void quick_sort() {
	quick_sort_ric(0, N - 1);
}

// --- HEAP SORT ---
void move_down(int k, int i) {
	int elem = myArray[k], j;
	while ((j = left(k)) <= i) {
		if (j + 1 <= i && myArray[j] < myArray[j + 1])
			j++;
		if (elem >= myArray[j])
			break;
		myArray[k] = myArray[j];
		k = j;
	}
	myArray[k] = elem;
}

void get_max(int i) {
	swap(0, i);
	move_down(0, i - 1);
}

void add_to_heap(int i) {
	int elem = myArray[i];
	while (i > 0 && elem > myArray[father(i)]) {
		myArray[i] = myArray[father(i)];
		i = father(i);
	}
	myArray[i] = elem;
}

void heap_sort() {
	for (int i = 0; i < N; i++)
		add_to_heap(i);
	for (int i = N - 1; i > 0; i--)
		get_max(i);
}

// --- STOOGES SORT ---
void stooge_sort_aux(int start, int end) {
	if (myArray[start] > myArray[end])
		swap(start, end);
	int t = end - start + 1;
	if (t >= 3) {
		t /= 3;
		stooge_sort_aux(start, end - t);
		stooge_sort_aux(start + t, end);
		stooge_sort_aux(start, end - t);
	}
}

void stooge_sort() {
	stooge_sort_aux(0, N-1);
}

// --- BUBBLE SORT ---
void bubble_sort() {
	for (int i = 0; i < N-1; i++)
		for (int j = N-1; j > i; j--)
			if (myArray[j] < myArray[j-1])
				swap(j, j-1);
}
