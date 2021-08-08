#include "List.h"

//****!!!!List.h 헤더파일에서 선언한 함수를 정의!!!***

void InitList(PLIST pList) {//노드 초기화 함수
	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE; //처음과 마지막을 의미하는 노드를 동적할당 해준다.
	//실제 데이터를 저장하는 용도가 아닌 Begin과 End만을 의미


	pList->pEnd->pNext = NULL;

	pList->pBegin->pPrev = NULL; //Begin노드의 이전 노드는 없기 때문에 NULL

	pList->pBegin->pNext = pList->pEnd;//초기에는 Begin과 End노드만이 존재하기 때문에 
	//Begin노드의 다음 노드를 End노드로 지정해준다

	pList->pEnd->pPrev = pList->pBegin;



}

void DestroyList(PLIST pList)//모든 노드를 지운다
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList)
{
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

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent; //우항의 tStudent는 Push_Back함수에서 선언한 STUDENT 구조체 변수이다.
	//좌항의 tStudent는 NODE 구조체의 멤버

	//새로 추가되는 노드는 End노드의 prev 노드가 된다
	
	PNODE PREV = pList->pEnd->pPrev;//추가되기 이전의 End 노드의 prev 노드를 구해놓는다

	pNode->pPrev = PREV; //End 노드의 원래 이전 노드가 추가하는 노드의 이전노드가 됨
	PREV->pNext = pNode;
	//추가할 노드와 이전 노드(PREV)연결

	pList->pEnd->pPrev = pNode;
	pNode->pNext = pList->pEnd;
	//추가할 노드와 pEnd 노드 연결

	++pList->iSize;
}

void Push_Front(PLIST pList)
{

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
}

void OutputStudent(const PSTUDENT pStudent) {

	cout << "이름 : " << pStudent->strName << "\t학번: " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어: " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << "\t총점: " << pStudent->iTotal << endl;
	cout << "평균: " << pStudent->avg << endl << endl;
}

void Output(PLIST pList) {//출력 방향을 정할 수 있도록!

	int iMenu;
	while (true) {
		system("cls");
		cout << "=================학생 출력=====================" << endl;
		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "3. 메뉴를 선택하세요: ";

		iMenu = InputInt();
		
		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu) {
		case OT_OUTPUT: {
			pNode = pList->pBegin->pNext;//Begin 노드의 다음 노드부터 End 노드의 이전노드 까지 순서대로 출력

			while (pNode != pList->pEnd) {//pEnd와 같아지면 break == pEnd 노드의 이전 노드까지 반복
				OutputStudent(&pNode->tStudent);
				pNode = pNode ->pNext;
			}
			break;
		}
		case OT_INVERSE: {

			pNode = pList->pEnd->pPrev; 
			//싱글링크드리스트는 이전 노드를 가리킬 수 없기 때문에 싱글링크드리스트는 불가능한 방법. only Begin -> End
			//더블링크드리스트는 양방향으로 접근이 가능하다. End -> Begin도 가능

			while (pNode != pList->pBegin) {
				OutputStudent(&(pNode->tStudent));
				pNode = pNode->pPrev;
			}
			break;
		}
	}
	cout << "학생수 : " << pList->iSize;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << "=================학생 탐색==================" << endl;
	cout << "검색할 학생 이름 입력: ";
	char Name[NAME_SIZE] = {};
	InputString(Name, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(Name, pNode->tStudent.strName) == 0) {
			OutputStudent(&(pNode->tStudent));

			cout << endl << "출력 완료" << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << Name << " 학생이 존재하지 않습니다." << endl;

	system("pause");
}

void Delete(PLIST pList) {
	system("cls");
	cout << "=================학생 삭제==================" << endl;
	cout << "삭제할 학생 이름 입력: ";
	char Name[NAME_SIZE] = {};
	InputString(Name, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(Name, pNode->tStudent.strName) == 0) {

			cout << Name << " 학생 삭제" << endl;

			pNode->pPrev->pNext = pNode->pNext;//pNode  를 삭제하기 때문에 pNode의 이전 노드의 next 노드는 pNode의 next 노드가 된다
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			system("pause");

			return;
		}

		pNode = pNode->pNext;
	}

	cout << Name << " 학생이 존재하지 않습니다." << endl;

	system("pause");

}
