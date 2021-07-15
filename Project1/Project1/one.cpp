#include<stdio.h>

#define HUNGRY 0x02 // 0x = 16진수
#define COLD 0x10 // == 16
#define FIRE 0x20 // == 32

int ADD(int right, int left) { // 함수의 데이터 타입 == 반환할 데이터 타입, right와 left는 지역변수
	return right + left;
}


int main() {

	
	int test = 10;

	test == 10 ? printf("test == 10") : printf("test != 10");//삼항연산자

	//비트연산자
	//쉬프트 <<,>>
	// <<= --> x = x<<3;(쉬프트하고 대입)

	char byte = 1;
	byte <<= 2;
	printf("\nbyte = %d", byte);

	byte >>= 1;
	printf("\nbyte = %d", byte);
	
	
	unsigned int Status = 0;
	//상태 추가
	Status |= HUNGRY;

	//상태 확인
	if (Status & HUNGRY) {//Status는 0이기 때문에 Status & HUNGRY의 결과는 0000 & 0010 --> 0010 (!=0)이 된다)

	}
	
	//특정 자리 비트 제거
	Status &= ~HUNGRY; //~HUNGRY ==> 1101 , 0000 & 1101 --> 0000 (Status = Status & HUNGRY)
	
	
					   
	//변수
	//1. 지역변수 - main 등 함수, 구문 안에서 선언된 함수
	//2. 전역변수 - main 함수 등 괄호 밖에서 선언된 함수
	//3. 정적변수
	//4. 외부변수


	//함수
	//모듈화 중요!!(특정 기능만 함수로 정의하여 필요한 장소에 호출하여 사용할 수 있도록)
	int data = 0;
	data = 10 + 20;
	data = ADD(20 ,40);
	printf("\ndata = %d", data);

	//scanf(콘솔창으로부터 값을 입력 받는다)
	int input = 0;
	printf("\n\ninput값 입력 = ");
	scanf_s("%d", &input);


	
	return 0;


}