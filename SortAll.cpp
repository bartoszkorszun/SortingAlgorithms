#include <iostream>
#include <windows.h>

using namespace std;

//CHANGE OF ELEMENTS

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//GENERATING ARRAY

int *new_array(int length){
	int *array = (int*) calloc(length, sizeof(int));
	if(!array){
		cerr << "|error| new_array: could allocate memory!\n";
		exit(1);
	}
	return array;
}

//ARRAY COPYING

int *copy_array(int* array, int length) {
	size_t memory = sizeof(int) * length;
	int *copy;
	copy = (int*) malloc(memory);
	if (!copy) {
		std::cerr << "[error] make_copy: could allocate memory!\n";
		exit(1);
	}
	copy = (int*) memcpy(copy, array, memory);
	if (!copy) {
		std::cerr << "[error] make_copy: could copy array!\n";
		exit(1);
	}
	return copy;
}

//RANDOM ARRAY

int *generate_random_array(int min, int max, int length) {
	cout << "\nGenerating random array... \n";
	int *array = new_array(length);
	int range = max - min + 1;
	for (int i = 0; i < length; i += 1){
		array[i] = rand() % range + min;
	}
	cout << "Array has been generated \n \n";
	return array;
}

//INCREASING ARRAY

int *generate_increasing_array(int length) {
	cout << "\nGenerating increasing array... \n";
	int *array = new_array(length);
	for (int i = 0; i < length; i += 1) 
		array[i] = i; 
	cout << "Array has been generated \n \n";
	return array;
}

//DECREASING ARRAY

int *generate_decreasing_array(int length) {
	cout << "\nGenerating decreasing array... \n";
	int *array = new_array(length);
	for (int i = 0; i < length; i += 1)
		array[i] = length - i - 1;
	cout << "Array has been generated \n \n";
	return array;
}

//CONSTANT ARRAY

int *generate_constant_array(int length) {
	cout << "\nGenerating constatn array... \n";
	int *array = new_array(length);
	for (int i = 0; i < length; i += 1) 
		array[i] = 3;
	cout << "Array has been generated \n \n";
	return array;
}

//V-SHAPE ARRAY

int *generate_v_shape_array(int length) {
	cout << "\nGenerating v-shape array... \n";
	int *array = new_array(length);
	for (int i = 0; i < length / 2; i++) 
		array[i] = 2*(length / 2 - i) + 1;
	for (int i = length / 2; i < length; i++) 
		array[i] = 2*(i - length / 2);
	cout << "Array has been generated \n \n";
	return array;
}

//
//ALGORITHMS IMPLEMENTATION
//

//INSERTION SORT

bool wait;

void insertion_sort(int *a, int length) {
	int tmp = 1;
	cout << "Insertion Sort... \n";
	DWORD startTime, currentTime;
	startTime = GetTickCount();
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0 && a[j-1] > a[j]; j--) {
			swap(&a[j], &a[j-1]);
		}
		if (i == length - 1){
			currentTime = GetTickCount() - startTime;
			cout << "Sorting comleted...\n\nSorting time: " << currentTime << "ms\n";
		}
		if (GetTickCount() - startTime > 3000 && wait){
			cout << "Sorting in progress please wait...\n";
			wait = false;
		}
	}
}

//SELECTION SORT

void selection_sort(int *a, int length) {
	int tmp = 1;
	cout << "Selection Sort... \n";
	DWORD startTime, currentTime;
	startTime = GetTickCount();
	for (int i = length - 1; i >= 2; i--) {
		int max = i;
		for (int j = i - 1; j >= 1 ; j--) {
			if (a[j] > a[max]) {
				max = j;
			}
		}
		swap(&a[i], &a[max]);
		if (i == 2){
			currentTime = GetTickCount() - startTime;
			cout << "Sorting comleted...\n\nSorting time: " << currentTime << "ms\n";
		}
		if (GetTickCount() - startTime > 3000 && wait){
			cout << "Sorting in progress please wait...\n";
			wait = false;
		}
	}
}

//HEAP SORT

void heapify(int *a, int length, int i) {
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < length && a[l] > a[max]) max = l;
	if (r < length && a[r] > a[max]) max = r;
	if (max != i) {
		swap(&a[i], &a[max]);
		heapify(a, length, max);
	}
}

void heap_sort(int *a, int length) {
	int tmp = 1;
	cout << "Heap Sort... \n";
	DWORD startTime, currentTime;
	startTime = GetTickCount();
	
	for (int i = length / 2 - 1; i >= 0; i--) {
		heapify(a, length, i);
		if (GetTickCount() - startTime > 3000 && wait){
			cout << "Sorting in progress please wait...\n";
			wait = false;
		}
	}
	for (int i = length - 1; i >= 0; i--) {
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
		if (i == 0){
			currentTime = GetTickCount() - startTime;
			cout << "Sorting comleted...\n\nSorting time: " << currentTime << "ms\n";
		}
		if (GetTickCount() - startTime > 3000 && wait){
			cout << "Sorting in progress please wait...\n";
			wait = false;
		}
	}
}

//MERGE SORT

// n = lenth of a, p = first index of the second sublist
int mergeTmp = 1;
int mergeLength;
bool mergeDo;
DWORD mergeStartTime, mergeCurrentTime;
void merge(int *a, int length, int p) {
	int *A = copy_array(a, length);
	for (int i = 0, l = 0, r = p; i < length;) {
		if ((A[l] <= A[r] || r >= length) && l < p)
			a[i++] = A[l++];

		if ((A[r] <= A[l] || l >= p) && r < length)
			a[i++] = A[r++];
		else if (i == mergeLength){
			mergeCurrentTime = GetTickCount() - mergeStartTime;
			cout << "Sorting comleted...\n\nSorting time: " << mergeCurrentTime << "ms\n";
		}
		if (GetTickCount() - mergeStartTime > 3000 && wait){
			cout << "Sorting in progress please wait...\n";
			wait = false;
		}
	}
	free(A);
}

void merge_sort(int *a, int length) {
	if(mergeDo){
		cout << "Merge Sort... \n";
		mergeStartTime = GetTickCount();
		mergeDo = false;
	}
	if (length <= 1) { 
		return;
	} else if (length == 2) {
		merge(a, length, 1);
	} else {
		int q = length % 2 == 0 ? 0 : 1;
		int p = length / 2;
		merge_sort(a, p);
		merge_sort(a + p, p + q);
		merge(a, length, p);
	}
}

int length;
int tabLength(){
	
	cout << "Insert length of array: \n";
	cin >> length;
	
	if(length > 2000000000 || length <= 0){
		cout << "Inserted values are not correct. Insert a number in range from 0 to 2 000 000 000...\n";
		tabLength();
	}
	return length;
}

void sorting(string whichTab, string whichAlgorithm){
	
	length = tabLength();
	mergeDo = true;
	mergeLength = length;
	
	int *array;
		
	//TWORZENIE TABLIC
		
	if (whichTab == "R"){
		cout << "\nSorting for random array... \n";
		array = generate_random_array(0, 2000000000, length);
	}
	if (whichTab == "I"){
		cout << "\nSorting for increasing array... \n";
		array = generate_increasing_array(length);
	}
	if (whichTab == "D"){
		cout << "\nSorting for decreasing array... \n";
		array = generate_decreasing_array(length);
	}
	if (whichTab == "C"){
		cout << "\nSorting for constant array... \n";
		array = generate_constant_array(length);
	}
	if (whichTab == "V"){
		cout << "\nSorting for v-shape array... \n";
		array = generate_v_shape_array(length);
	}
	
	//WYBÓR ALGORYTMU
	
	if(whichAlgorithm == "IS")
		insertion_sort(array, length);
	if(whichAlgorithm == "SS")
		selection_sort(array, length);
	if(whichAlgorithm == "HS")
		heap_sort(array, length);
	if(whichAlgorithm == "MS")
		merge_sort(array, length);
}

string whichTab;
string chooseTab(){
	
	cout << "Choose which array you want to use: \nR - Random \nI - Increasing \nD - Decreasing \nC - Constant \nV - V-shape \n";
	cin >> whichTab;
	
	if(whichTab != "R" && whichTab != "I" && whichTab != "D" && whichTab != "C" && whichTab != "V"){
		cout << "Inserted values are incorrect!!! Insert correct value... \n";
		chooseTab();
	}
	return whichTab;	
}

string whichAlgorithm;
string chooseAlgorithm(){
	
	cout << "Choose which algorithm you want to use: \nIS - Insertion Sort \nSS - Selection Sort \nHS - Heap Sort \nMS - Merge Sort \n";
	cin >> whichAlgorithm;
	
	if(whichAlgorithm != "IS" && whichAlgorithm != "SS" && whichAlgorithm != "HS" && whichAlgorithm != "MS"){
		cout << "Inserted values are incorrect!!! Insert correct value... \n";
		chooseAlgorithm();
	}
	return whichAlgorithm;
}

string close = "N";
string doYouReallyWannaExitThisAmazingProgramme(){
	
	cout << "\nDo you really want to exit this amazing programe? \nY - Yes \nN - No \n";
	cin >> close;
	if(close != "Y" && close != "N"){
		cout << "Oh cmon there are only two options... \n";
		doYouReallyWannaExitThisAmazingProgramme();
	}
	return close;
}

//MAIN
int main(int argc, char **argv) {
	
	do{	
		
		wait = true;
		
		string whichTab = chooseTab();
		
		string whitchAlgorithm = chooseAlgorithm();
		
		cout << "\n------------------------------------------------------------------------------- \n";
	
		sorting(whichTab, whitchAlgorithm);
		
		string close = doYouReallyWannaExitThisAmazingProgramme();
		
		cout << "\n------------------------------------------------------------------------------- \n\n";
	}while (close == "N");
		
	return 0;
}

