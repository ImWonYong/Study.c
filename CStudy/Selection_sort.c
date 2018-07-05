#include <stdio.h>

int theLargest(int array[], int last) {
	int largest = 0;
	for (int i = 1; i < last; i++) {
		if (array[i] > array[largest]) {
			largest = i;
		}
	}
	
	return largest;
}

void selection_sort(int array[], int n) {
	int k, last;
	int temp = 0;
	for (last = n; last > 0; last--) {
		k = theLargest(array, last);
		temp = array[last - 1];
		array[last - 1] = array[k];
		array[k] = temp;

	}

}

int main() {
	int n;
	int arr[1000];

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	selection_sort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}