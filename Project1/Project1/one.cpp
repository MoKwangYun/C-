#include<stdio.h>

#define HUNGRY 0x02 // 0x = 16����
#define COLD 0x10 // == 16
#define FIRE 0x20 // == 32

int ADD(int right, int left) { // �Լ��� ������ Ÿ�� == ��ȯ�� ������ Ÿ��, right�� left�� ��������
	return right + left;
}


int main() {

	
	int test = 10;

	test == 10 ? printf("test == 10") : printf("test != 10");//���׿�����

	//��Ʈ������
	//����Ʈ <<,>>
	// <<= --> x = x<<3;(����Ʈ�ϰ� ����)

	char byte = 1;
	byte <<= 2;
	printf("\nbyte = %d", byte);

	byte >>= 1;
	printf("\nbyte = %d", byte);
	
	
	unsigned int Status = 0;
	//���� �߰�
	Status |= HUNGRY;

	//���� Ȯ��
	if (Status & HUNGRY) {//Status�� 0�̱� ������ Status & HUNGRY�� ����� 0000 & 0010 --> 0010 (!=0)�� �ȴ�)

	}
	
	//Ư�� �ڸ� ��Ʈ ����
	Status &= ~HUNGRY; //~HUNGRY ==> 1101 , 0000 & 1101 --> 0000 (Status = Status & HUNGRY)
	
	
					   
	//����
	//1. �������� - main �� �Լ�, ���� �ȿ��� ����� �Լ�
	//2. �������� - main �Լ� �� ��ȣ �ۿ��� ����� �Լ�
	//3. ��������
	//4. �ܺκ���


	//�Լ�
	//���ȭ �߿�!!(Ư�� ��ɸ� �Լ��� �����Ͽ� �ʿ��� ��ҿ� ȣ���Ͽ� ����� �� �ֵ���)
	int data = 0;
	data = 10 + 20;
	data = ADD(20 ,40);
	printf("\ndata = %d", data);

	//scanf(�ܼ�â���κ��� ���� �Է� �޴´�)
	int input = 0;
	printf("\n\ninput�� �Է� = ");
	scanf_s("%d", &input);


	
	return 0;


}