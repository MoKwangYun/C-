#include<iostream>

using namespace std;

#define NAME_SIZE 32

enum MAIN_MENU { //열거체
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
	int iEng;
	int iMath;
	int iTotal;
	float avg;

}STUDENT, *PSTUDENT;

/*
링크드리스트 : 자료구조의 한 종류 (자료구자란 데이터를 관리하는 방법을 말한다)
링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
링크드리스트는 데이터를 저장하기 위한 노드 존재, 각 노드의 특징은 다음 노드를 알 수 있게 된다는 것!(= 다음 노드의 메모리 주소를 저장한다는 의미)

리스트는 선형구조로 되어있다 --> 배열과 같이 특정 요소에 바로 접근 불가(무조건 앞에서부터 차례대로 타고 들어가야 접근 가능)
노드를 새로 추가할 때는 노드  생성 & 마지막 노드에 연결만 해주면 됨 --> 개수의 제한 없다
*/

//리스트 노드  만든다
typedef struct _tagNode {

	STUDENT tStudent;
	_tagNode* pNext;

}NODE, *PNODE;

//리스트 구조체를 만든다 / 처음 & 마지막 노드 주소 + 노드 개수
typedef struct _tagList {

	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, *PLIST;

int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) { //입력실패한 경우 (ex. 정수 입력해야 하는데 문자 입력하는 등
		cin.clear(); //잘못 입력된 버퍼를 지운다
		cin.ignore(1024, '\n');
		return INT_MAX;
	}


	return iInput;

}
void InitList(PLIST pList) {//리스트 구조체의 주소를 파라미터로 받아온다

	pList->pBegin = NULL; // 포인터 초기화는 NULL로 !!
	pList->pEnd = NULL;
	pList-> iSize = 0;

}

int OutputMenu() {
	system("cls");
	cout << "1. 학생추가 " << endl;
	cout << "2. 학생삭제 " << endl;
	cout << "3. 학생탐색 " << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료 " << endl;
	cout << " 메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput>MM_EXIT)
		return MM_NONE;

	return iInput;
}

void InputString(char* pString, int size) {

	cin.clear();
	cin.ignore(1024, '\n'); //이전에 입력을 위한 enter 나 space 키를 버퍼에서 지운다.

	cin.getline(pString, size - 1); // 마지막 문자열에는 NULL 값이 들어가야 하기 때문에 -1 까지만  입력 받음
}

void Insert(PLIST pList) { //노드 추가 함수

	system("cls");
	cout << "==============학생추가============" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번 : ";
	tStudent.iNumber = InputInt();

	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;

	tStudent.avg = tStudent.iTotal / 3.f;

	//추가할 노드 생성

	PNODE pNode = new NODE; // 노드 하나 동적할당 & 그 메모리 주소를 pNode가 가지고 있다.
	pNode->pNext = NULL; //추가하는 노드가 마지막 노드가 되기 때문에 추가할 노드의 링크 부분이 가리킬 주소는 현재 없다
	pNode->tStudent = tStudent; // 위에서 입력 받은 학생 정보를 추가할 노드의 데이터부에 저aa장

	if (pList->pBegin == NULL) // 현재 노드가 없음(방금 생성한 노드가 처음 생성)
		pList->pBegin = pNode;

	else {//링크드리스트에 노드 이미 존재
		pList->pEnd->pNext = pNode;//생성한 노드 추가하기 이전에 End 노드의 링크에 추가할 노드의 주소 저장

	}

	pList->pEnd = pNode; //추가한 노드가 마지막 노드가 되기 때문에 List의 End 노드에 새로 생성한 노드를 저장

	++pList->iSize;
}

void ClearList(PLIST pList) {
	PNODE pNode = pList->pBegin;
	//PNODE는 포인터 타입이기 때문에 pBegin이 가리키는 노드의 주소를 pNode에 저장

	while (pNode != NULL) {
		PNODE  pNext = pNode->pNext; //pNext 노드에 pNode의 Next가 가리키는 노드 주소를 저장
		delete pNode; //pNode가 가리키는 노드 삭제
		pNode = pNext; //위에서 저장한 Next에 저장된 노드 주소를 pNode에 다시 저장 
					   // 다음 노드가 없을 경우 Next는 NULL이고 pNode에 NULL이 저장된다
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

//const 포인터이기 때문에 가리키는 대상의 값 변경 불가
void OutputStudent(const PSTUDENT pStudent) {

	cout << "이름 : " << pStudent->strName << "\t학번: " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어: " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << "\t총점: " << pStudent->iTotal << endl;
	cout << "평균: " << pStudent->avg << endl;
}

void Output(PLIST pList) {
	system("cls");
	cout << "=======================학생 출력=================" << endl;

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext; //다음 노드의 주소를 저장
	}

	cout << "학생수: " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << " =============학생 탐색============" << endl;
	cout << "탐색할 이름을 입력하세요: ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		//일치하지 않을 경우
		pNode = pNode->pNext;
	}
	//while문 안에서 return 되지 않고 빠져나오는 경우 == 일치하는 학생 이름 없음

	cout << "일치하는 이름이 없습니다. " << endl;

	system("pause");

}

void Delete(PLIST pList) {
	system("cls");
	cout << " ==========학생 삭제==============" << endl;
	cout << "삭제할 학생 이름 입력: ";
	char strName[NAME_SIZE];
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			PNODE NEXT = pNode->pNext;

			//첫번째 노드를 지울 경우(= pPrev가 NULL)
			if (pPrev == NULL) {
				delete pNode;
				pList->pBegin = NEXT;

				if (NEXT == NULL)//다음 노드가 없는 경우
					pList->pEnd = NULL;
			}

			//이전 노드가 있는 경우
			else {
				delete pNode;
				pPrev->pNext = NEXT;

				if (NEXT == NULL) //Next가 NULL ==> 삭제한 노드가 마지막 노드인 경우
					pList->pEnd = pPrev;
			}
			
			cout << strName << " 학생 삭제 완료" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		
		//현재 pNode가 입력 이름과 일치하지 않았기 때문에 다음 노드 비교를 위해
		//현재 노드는 이전 노드가 되고 다음 노드 주소를 pNode에 저장
		pPrev = pNode;
		pNode = pNode->pNext;

	}
	cout << "일치하는 이름이 없습니다." << endl;
	system("pause");

}
int main() {

	LIST tList;

	InitList(&tList);

	while (true) {
		
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
			case MM_INSERT: { //노드 추가
				Insert(&tList);

				break;
			}
			case MM_DELETE: {
				Delete(&tList);

				break;
			}
			case MM_SEARCH: {
				Search(&tList);

				break;
			}
			case MM_OUTPUT: {
				Output(&tList);

				break;
			}
		}
		
	}

	ClearList(&tList);

	return 0;
}