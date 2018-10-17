#include <iostream>
#include <math.h>
#include <time.h>

void quicksort(int* array, int left, int right);
void printArrayOfTenElements(int* array);

int main(){
	srand(time(NULL));
	
	int array[10];
	for (int i = 0; i < 10; ++i) {
		array[i] = rand() % 100;
	}

	printArrayOfTenElements(array);
	quicksort(array, 0, 9);
	printArrayOfTenElements(array);

	system("pause");
	return 0;
}

void quicksort(int* array, int left, int right) {
	int axis = array[(left + right) / 2];
	int p = left, q = right;

	do {
		while (array[p] < axis) ++p;
		while (array[q] > axis) --q;
		if (p <= q) {
			int temp = array[p];
			array[p] = array[q];
			array[q] = temp;
			++p; --q;
		}
	} while (p <= q);

	if (q > left) quicksort(array, left, q);
	if (p < right) quicksort(array, p, right);
}

void printArrayOfTenElements(int* array) {
	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << '\t';
	}
	std::cout << "\n\n";
}
