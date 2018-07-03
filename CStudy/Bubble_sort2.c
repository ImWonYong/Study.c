/* 백준 2571 */
#include <stdio.h>

int arr[10000];// 배열은 어디에 선언해도 상관 없나요? 어떨 때 main 안과 밖을 구분하는가요?

int main() {
	int n;
	int temp = 0;
	_Bool flag;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1; j++) {
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
}
