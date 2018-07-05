#include <stdio.h>

void insertion_sort(int array[], int n) {
	int i, j, k;
	int temp = 0;
	for (i = 1; i < n; i++) {

		k = array[i];

		for (j = i - 1; j >= 0 && k < array[j]; j--) {
				array[j + 1] = array[j];
		}
		array[j + 1] =  k;
	}
}

int main() {
	int n;
	int arr[1000];

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	insertion_sort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}