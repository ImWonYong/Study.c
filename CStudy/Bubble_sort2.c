/* ���� 2571 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int temp = 0;
	_Bool flag;
	int* arr;

	scanf_s("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 1;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag == 0) break;
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}
