// n의 정수를 정렬하라. 단 모든 정수는 0에서 k사이의 정수이다.
//stable sort 입력에 동일한 값이 있을때 입력에 먼저 나오는 값이 출력도 동일한 순서로 출력된다.

#include <stdio.h>

void counting_sort(int data[], int n) {
	int counter[100001] = { 0, };
	int b[1000];
	for (int i = 0; i < n; i++) {
		counter[data[i]]++;
	}
	for (int i = 0; i < n ; i++) {
		counter[i + 1] = counter[i + 1] + counter[i]; 
	}
	
	for (int i = n - 1; i >= 0; i--) {
		b[counter[data[i]] - 1] = data[i];
		counter[data[i]]--;
	}

	for (int i = 0; i < n; i++) {
		data[i] = b[i];
	}
}

int main() {
	int n;
	int a[1000];
	
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)  {
		scanf_s("%d", &a[i]);
	}

	counting_sort(a, n); 

	for(int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}