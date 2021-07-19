#include<stdio.h>
#include<iostream>


#define NAME_SIZE 32

using namespace std;
struct student {
	int kor;
	int eng;
	int math;
	int avr;
	int total;
	int num;
	char name[NAME_SIZE];
};

int main() {

	student tstudent = {}; //tstudent(student타입)의 멤버들을 0으로 초기화
	student tstudent2 = {};
	student studentarray[100] = {}; //student 타입의 배열

	//구조체 멤버에 접근
	tstudent.kor = 100;

	//문자열을 배열에 넣어줄 때는 단순 대입 불가 --> strcpy_s 함수 이용하여 문자열을 복사
	strcpy_s(tstudent.name, "Ken");
	
	//문자열의 끝은 항상 0(NULL)로 끝나야 한다. 
	//그런데 쓰레기값이 들어가 있는 상태에서 tstudent.name[0] = '김';과 같이 각 배열 인덱스에 값을 넣어주게 되면
	//그 값이 출력되고 별도 넣어주지 않은 나머지 부분은 쓰레기 갑으로 출력
	//Because 문자열의 끝을 인식할 수 없기 때문이다.
	tstudent2.name[0] = 'K';
	tstudent2.name[1] = 'e';
	tstudent2.name[2] = 'n';
	tstudent2.name[3] = 0;//0을 넣고자하는 문자열 다음 인덱스에 넣어주어야 [2] 인덱스에서 출력이 종료 될 수 있다(0을 끝으로 인식하기 때문)

	printf("%s \n %s\n", tstudent.name, tstudent2.name);

	strcat_s(tstudent2.name, " Hi");
	printf("%s \n tstudent2.name length = %d", tstudent2.name, strlen(tstudent2.name));

	char name[NAME_SIZE] = {};
	printf("\n이름 입력");
	cin >> name;

	if (strcmp(tstudent.name, name) == 0) {
		printf("tstudent.name과 동일한 이름");
	}
	

	return 0;
}