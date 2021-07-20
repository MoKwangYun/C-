#include<stdio.h>
#include<iostream>

using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14 //배열 마지막 널 문자 포함 14자리 000-0000-0000 NULL
#define STUDENT_MAX 10

enum MENU {
	none,
	M_insert,
	M_delet,
	M_search,
	M_print,
	M_exit
	//5개의 메뉴
};

struct student {
	char name[NAME_SIZE];
	char add[ADDRESS_SIZE];
	char phone[PHONE_SIZE];
	int number;
	int kor;
	int eng;
	int math;
	int total;
	int avg;
};

int main() {
	student arr[STUDENT_MAX] = {};
	int count = 0; // arr에 저장된 학생 목록 개수 카운트하는 변수, 입력이나 삭제 등 동작 수행을 위한 인덱스로도 활용
	int stnum = 1;
	char searchname[NAME_SIZE] = {};
	char deletname[NAME_SIZE] = {};



	while (true) {
		system("cls");

		//메뉴를 출력
		printf("1. 학생 등록  2. 학생 삭제  3. 학생 검색  4. 학생 출력  5. 종료\n");
		printf("메뉴를 선택하세요: ");
		int m;
		cin >> m;

		if (cin.fail()) {
			//에러버퍼 비워준다
			cin.clear();

			//입력버퍼(\n이 남아있음)를 검색하여 \n을 지워준다
			cin.ignore(1024, '\n'); // 첫번 째 파라미터 --> 검색하고자 하는  버퍼 크기 / 두번째 파라미터 --> 찾고자 하는 문자  ==> 입력버퍼 처음부터 \n이 있는 곳까지 찾아서 모두 지움
		
		}//cin.fail() --> 입력 에러 발생했을 때 true 반환
		
		 //cin은 만약 오른쪽에 int 변수가 오면 정수를 입력해야 한다. 변수 타입에 맞지 않는 값 입력시 에러 발생!! 
		//==> 예외 처리로 에러 발생했는지 체크할 필요 있음  ==> 에러 발생했을시 cin 내부 에러버퍼 비워주고 입력버퍼에는 \n이 남아있으므로 버퍼를 순회하며 \n을 지워준다
		//버퍼 =임시 저장공간

		if (m == M_exit) {
			break;
		}
		switch (m) {
			case M_insert:{//학생 정보 추가/ 이름, 주소, 번호, 국어, 영어, 수학 입력 
				//학번, 총점, 평균은 연산을  통해 계산
				 
				system("cls");
				printf("=================학생 추가===============\n");

				//학생 구조체 배열이 꽉찬 경우
				if (stnum == STUDENT_MAX) {
					printf("배열이 꽉 찬 상태입니다.");
					break;
				}

				//이름 입력 받는다
				cout << "이름 : ";
				cin >> arr[count].name;

				cout << "주소: ";
				//cin >> arr[count].add; //띄어쓰기 하면 처음 공백 이후 인식 X ==> 공백을 문자열의 끝으로 인식
				
				cin.ignore(1024, '\n');//cin.getline은 \n을 끝으로 인식하기 때문에 이전에 있을 수도 있는 \n을 지워준다

				cin.getline(arr[count].add, ADDRESS_SIZE);//스페이스바는 문자열로 인식 & enter만 문자의 끝으로 인식 (두번째 파라미터: 입력 받을 최대 크기)

				cout << "번호: ";
				cin >> arr[count].phone;

				cout << "국어: ";
				cin >> arr[count].kor;

				cout << "수학: ";
				cin >> arr[count].math;

				cout << "영어: ";
				cin >> arr[count].eng;

				arr[count].total = arr[count].kor + arr[count].eng + arr[count].math;

				arr[count].avg = arr[count].total / 3.f;

				arr[count].number = stnum;

				stnum++;
				count++;


				break;
			}
			case M_delet: {

				system("cls");

				cout << "==================학생 정보 삭제==============" << endl;

			   //cin.ignore(1024, '\n');(입력을 cin.getline으로 받을 경우)
				cout << "삭제할 학생 이름 입력: ";
				cin >> deletname;

				for (int i = 0; i < count; i++) {
					if (strcmp(arr[i].name, deletname) == 0) {

						for (int j = i; j < count - 1; j++) {//찾았다면 i+1 인덱스부터 배열 하나씩 앞당김
							
							arr[j] = arr[j + 1];

						}

						count--;

						cout <<"학생 정보 삭제" <<endl;

						break;
					}
				}


				break;
			}

			case M_search: {

				system("cls");

				cout << "==================학생 정보 검색==============" << endl;

				//cin.ignore(1024, '\n');
				cout << "검색할 학생 이름 입력: ";
				cin >> searchname;

				//등록되어있는 학생 수만큼 반복하며 학생 찾는다
				for (int i = 0; i < count; i++) {
					if (strcmp(arr[i].name, searchname) == 0) {
						cout << "번호: " << arr[i].number << endl;
						cout << "이름: " << arr[i].name << endl;
						cout << "주소: " << arr[i].add << endl;
						cout << "번호: " << arr[i].phone << endl;
						cout << "국어: " << arr[i].kor << endl;
						cout << "영어: " << arr[i].eng << endl;
						cout << "수학: " << arr[i].math << endl;
						cout << "총점: " << arr[i].total << endl;
						cout << "평균: " << arr[i].avg << endl << endl;
						break;
					}
				}

				break;
			}

			case M_print: {
				system("cls");
				cout << "====================학생 출력===============" << endl;
				if (count == 0) {
					printf("등록된 정보가 없습니다.\n");
					break;
				}
				//등록된 학생 수만큼 반복하며 정보 출력
				for (int i = 0; i < count; i++) {
					cout << "번호: " << arr[i].number << endl;
					cout << "이름: " << arr[i].name << endl;
					cout << "주소: " << arr[i].add << endl;
					cout << "번호: " << arr[i].phone << endl;
					cout << "국어: " << arr[i].kor << endl;
					cout << "영어: " << arr[i].eng << endl;
					cout << "수학: " << arr[i].math << endl;
					cout << "총점: " << arr[i].total << endl;
					cout << "평균: " << arr[i].avg << endl << endl;
				}
				break;
			}

			default: {
				printf("\n잘못된 입력]\n");
				break;
			}

			

		}

		system("pause");





	}






}