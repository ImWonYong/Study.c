#include <stdio.h>

int data[100001];

void counting_sort(int data[], int n, int digit);
void radix_sort(int arr[], int n);
int getMax(int arr[], int n);

int main() {
	int n;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}

	radix_sort(data, n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", data[i]);
	}
}
void counting_sort(int arr[], int n, int digit) {
	int b[100001];
	int counter[10] = { 0, };
	for (int i = 0; i < n; i++) {
		counter[(arr[i] / digit) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		counter[i] = counter[i] + counter[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		b[counter[(arr[i] / digit) % 10] - 1] = arr[i];
		counter[(arr[i] / digit) % 10]--;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = b[i];
	}
}

int getMax(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > mx) {
			mx = arr[i];
		}
	}

	return mx;
}
void radix_sort(int arr[], int n) {
	
	int m = getMax(arr, n);
	for (int digit = 1; m / digit > 0; digit *= 10) {
		counting_sort(data, n, digit);
	}
}