#include <stdio.h>

void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

void quick_sort(int array[], int start, int end) {
	int pivot;
	if (start < end) {
		pivot = partition(array, start, end);
		quick_sort(array, start, pivot - 1);
		quick_sort(array, pivot + 1, end);
	}
}
int partition(int array[], int start, int end) {

	int i, j, pivot, mid;
	int temp = 0;

	mid = (start + end) / 2;
	temp = array[mid];
	array[mid] = array[end];
	array[end] = temp;

	pivot = array[end];
	i = start - 1;
	for (j = start; j < end; j++) {
		if (pivot > array[j]) {
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;

	return i + 1;
}

int main() {
	int n;
	int arr[1000];

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}

	quick_sort(arr, 1, n);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}
}