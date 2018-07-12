// n�� ������ �����϶�. �� ��� ������ 0���� k������ �����̴�.
//stable sort �Է¿� ������ ���� ������ �Է¿� ���� ������ ���� ��µ� ������ ������ ��µȴ�.

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