#include<stdio.h>

//����Լ� & �迭
//Recursion: ���

int Factorial_Re(int num) {

	if (num == 1) {
		return 1;
	}
	else {
		return num * Factorial_Re(num - 1);
	}
}
 
//�Ǻ���ġ ���� ��� �Լ� 1 1 2 3 5 8 13 21 34 55 ....(�Ǻ���ġ ������ n��° ����), ù��°�� �ι�°�� 1, 1 ����
int Fibonacci(int count) {
	//in �ݺ���
	//if (count == 1 || count == 2) {
	//	return 1;
	//}

	//int a1 = 1;
	//int a2 = 1;
	//int val = 0;
	//
	//for (int i = 0; i < count - 2; i++) {//n��° ���� ���ϱ� ���� ���� Ƚ�� = n-2 ==> n-2�� �ݺ�(1, 2��° 1�� Ȯ����)
	//	
	//	val = a1 + a2;
	//	a1 = a2;
	//	a2 = val;
	//	
	//	return val;
	//}

	//in ����Լ�
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

	//�迭
	int arry[10] = {}; //�迭 10�� ���Ҹ� ��� 0���� �ʱ�ȭ

}