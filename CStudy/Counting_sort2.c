// n의 정수를 정렬하라. 단 모든 정수는 0에서 k사이의 정수이다.
//stable sort 입력에 동일한 값이 있을때 입력에 먼저 나오는 값이 출력도 동일한 순서로 출력된다.

#include <stdio.h>

int counter[1000001] = { 0, };
int end = 0;

void counting_sort(int data[], int n) {
	int j;

	for (int i = 0; i <= end; i++) {
		data[i + 1] = data[i + 1] + data[i];
	}
	for (int i = 0; i < data[0]; i++) {
		printf("0 ");
	}
	for (int i = 1; i <= end; i++) {
		j = data[i] - data[i - 1];
	
		while (j != 0) {
			printf("%d ", i);
			j--;
		}
	}
}

int main() {
	int n;
	int k;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &k);
		counter[k]++;
		if (k > end) {
			end = k;
		}
	}

	counting_sort(counter, n);


	return 0;
}