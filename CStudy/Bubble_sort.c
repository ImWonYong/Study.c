/* 백준 1838 문제 */
#include <stdio.h>

int main(void) {
	int n;
	int* input;
	input = (int*)malloc(sizeof(int) * 500000);
	
	int temp = 0;
	_Bool flag;
	
	scanf_s("%d", &n);

	for (int k = 0; k < n; k++) {
		scanf_s("%d", &input[k]);
	}
	for (int i = 0; i < n; i++) {
		flag = 0;
		for(int j = 0; j < n - 1; j++){
			if (input[j] > input[j + 1]) {
				flag = 1;
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
		if (flag == 0) {
			printf("%d", i);
			break;
		}
	}
}