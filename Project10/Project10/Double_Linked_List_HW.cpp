#include<iostream>

using namespace std;

#define NAME_SIZE  32

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};
typedef struct _tagStudent {

	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iMath;
	int iEng;
	int iTotal;
	float avg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;

}NODE, * PNODE;

typedef struct _tagList {
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

void INPUTSTRING(char * pString, int size) { 

	cin.clear();
	cin.ignore(1024, '\n');

	cin.getline(pString, size - 1);
}

void INSERT(PLIST pList) {
	system("cls");
	cout << "===============학생 추가===============" << endl;

	STUDENT tStudent;
	cout << "학생 이름: ";
	
	INPUTSTRING(tStudent.strName, NAME_SIZE);
	//INPUTSTRING 함수가 포인터로 주소를 받아갔기 때문에  strName 변수의 값이
	//INPUTSTRING 함수를 통해 변경됨

	cout << "학번: ";
	cin >> tStudent.iNumber;

	cout << "국어: ";
	cin >> tStudent.iKor;

	cout << "수학: ";
	cin >> tStudent.iMath;

	cout << "영어: ";
	cin >> tStudent.iEng;

	tStudent.iTotal = tStudent.iKor + tStudent.iMath + tStudent.iEng;
	tStudent.avg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE; //빈 노드생성
	pNode->pNext = NULL;
	pNode->pPrev = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL) {//노드 처음 생성
		pList->pBegin = pNode;
		pList->pEnd = pNode;

	}
	else {
		pList->pEnd->pNext = pNode;
		pNode->pPrev = pList->pEnd;
		pList->pEnd = pNode;
		
	}

	++pList->iSize;

}

void OutputStudent(const PSTUDENT pStudent) {

	cout << "이름 : " << pStudent->strName << "\t학번: " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어: " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << "\t총점: " << pStudent->iTotal << endl;
	cout << "평균: " << pStudent->avg << endl;
}

void OUTPUT(PLIST pList) {
	system("cls");
	cout << "==============학생 출력 ==============" << endl;

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		OutputStudent(&(pNode->tStudent));
		pNode = pNode->pNext;
	}

	cout << "학생 수: " << pList->iSize << endl;
	system("pause");
}

int main() {

	LIST tList;

	tList.pBegin = NULL;
	tList.pEnd = NULL;
	tList.iSize = 0;

	while (true) {
		system("cls");
		cout << "1. 학생 등록" << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 검색" << endl;
		cout << "4. 학생 출력" << endl;
		cout << "5. 종료" << endl;

		int num;
		cin >> num;

		switch (num) {
			case MM_INSERT: {
				INSERT(&tList);

				break;
			}
			case MM_DELETE: {

				break;
			}
			case MM_SEARCH: {

				break;
			}
			case MM_OUTPUT: {
				OUTPUT(&tList);

				break;
			}
			case MM_EXIT: {

				break;
			}
			default: {

				cout << "잘못된 입력입니다." << endl;
				break;
			}

		}
	}

	return 0;
}