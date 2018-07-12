#include <stdio.h>

void swap(int* array, int a, int b);
void buildHeap(int array[], int n);
void max_heapify(int array[], int i, int n);
void heap_sort(int array[], int n);

void swap(int *array, int a, int b) {
	int temp;
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void buildHeap(int array[], int n) {
	for (int i = n / 2; i >= 1; i--) {
		max_heapify(array, i, n);
	}
}
void max_heapify(int array[], int root, int n) {
	int left;
	int	right;
	int max;
	int temp;
	left = 2 * root;
	right = 2 * root + 1;
	max = root;
	if (left > n && right > n) {
		return;
	}
	if (left <= n && right > n) {
		max = left;
	}
	else if (left <= n && right <= n) {
		if (array[left] > array[right]) {
			max = left;
		}
		else {
			max = right;
		}
	}
	if (array[root] < array[max]) {
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		max_heapify(array, max, n);
	}
}

void heap_sort(int array[], int n) {
	int temp;
	buildHeap(array, n);
	for (int i = n; i >= 2; i--) {
		temp = array[i];
		array[i] = array[1];
		array[1] = temp;
		buildHeap(array, i - 1);
	}
}

int main() {
	int n;
	int arr[1000];

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}
	
	heap_sort(arr, n);

	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}