#include<stdio.h>

int Factorial(int num) {//팩토리얼을 함수로 작성
	
	int value = 1;
	for (int j = 0; j < num - 1; j++) {
		value *= (j + 2);
	}

	return value;
}


int main() {
	int i = 0;
	for (int i = 0; i < 10; i++) {
		

		if (i % 3 == 0)
			continue;
		
		printf("i = %d\n", i);
	}
	printf("\n\n");
	while (i < 10) {
		i++;
		if (i % 3 != 0)
			continue;
		printf("i = %d\n", i);
		
	}

	//팩토리얼
	int k = 10;
	int value = 1;
	for (int j = 0; j < k - 1; j++) {
		value *= (j + 2);
	} // 이런 식으로 구문으로 작성할 수 있지만 모듈화 되지 않아 동일한 기능(팩토리얼)을 사용할 때
	// 복붙해야 함 --> 함수로 작성할 시 매번 코드를 작성하는 것이 아니라 함수 호출로 기능 사용 가능
	
	printf("\n\n10 Factorial = %d, %d", value, Factorial(10));
	

	return 0;
}