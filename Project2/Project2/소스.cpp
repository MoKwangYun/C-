#include<stdio.h>

int Factorial(int num) {//���丮���� �Լ��� �ۼ�
	
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

	//���丮��
	int k = 10;
	int value = 1;
	for (int j = 0; j < k - 1; j++) {
		value *= (j + 2);
	} // �̷� ������ �������� �ۼ��� �� ������ ���ȭ ���� �ʾ� ������ ���(���丮��)�� ����� ��
	// �����ؾ� �� --> �Լ��� �ۼ��� �� �Ź� �ڵ带 �ۼ��ϴ� ���� �ƴ϶� �Լ� ȣ��� ��� ��� ����
	
	printf("\n\n10 Factorial = %d, %d", value, Factorial(10));
	

	return 0;
}