#include<stdio.h>

//재귀함수 & 배열
//Recursion: 재귀

int Factorial_Re(int num) {

	if (num == 1) {
		return 1;
	}
	else {
		return num * Factorial_Re(num - 1);
	}
}
 
//피보나치 수열 재귀 함수 1 1 2 3 5 8 13 21 34 55 ....(피보나치 수열의 n번째 숫자), 첫번째와 두번째는 1, 1 고정
int Fibonacci(int count) {
	//in 반복문
	//if (count == 1 || count == 2) {
	//	return 1;
	//}

	//int a1 = 1;
	//int a2 = 1;
	//int val = 0;
	//
	//for (int i = 0; i < count - 2; i++) {//n번째 숫자 구하기 위한 연산 횟수 = n-2 ==> n-2번 반복(1, 2번째 1은 확정적)
	//	
	//	val = a1 + a2;
	//	a1 = a2;
	//	a2 = val;
	//	
	//	return val;
	//}

	//in 재귀함수
	if (count == 1 || count == 2) {
		return 1;
	}
	else {
		return Fibonacci(count - 1) + Fibonacci(count - 2);
	}
}

int main() {
	int value = Factorial_Re(10);

	printf("10 Factorial = %d\n\n", value);

	int val = Fibonacci(8);
	printf("8 Fibonacci = %d\n\n", val);

	//배열
	int arry[10] = {}; //배열 10개 원소를 모두 0으로 초기화

}