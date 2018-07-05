#include <stdio.h>

void merge_sort(int array[], int p, int r);
void merge(int array[], int p, int mid, int r);

int main() {
	int n;
	int arr[10000];

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}

void merge_sort(int array[], int p, int r) {
	int mid;
	if (p < r) {
		mid = (p + r) / 2;
		merge_sort(array, p, mid);
		merge_sort(array, mid + 1, r);
		merge(array, p, mid, r);
	}
}

void merge(int array[], int p, int mid, int r) {
	int i, j, k;
	i = p;
	j = mid + 1;
	k = p;
	int temp[10000];
	while (i <= mid && j <= r) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			i++;
			k++;
		}
		else {
			temp[k] = array[j];
			j++;
			k++;
		}
	}
	while (j <= r) {
		temp[k] = array[j];
		j++;
		k++;
	}
	while (i <= mid) {
		temp[k] = array[i];
		i++;
		k++;
	}

	for (int i = p; i <= r; i++) {
		array[i] = temp[i];
	}
}

