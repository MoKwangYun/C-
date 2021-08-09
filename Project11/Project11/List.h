#pragma once

using namespace std;

#define NAME_SIZE 32

typedef struct _tagStudent {
	int iNumber;
	int iKor;
	int iMath;
	int iEng;
	int iTotal;
	float avg;
	char strName[NAME_SIZE];


}STUDENT, * PSTUDENT;

typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode* pPrev;
	_tagNode* pNext;
}NODE, * PNODE;

typedef struct _tagList {
	int iSize;
	PNODE pBegin;
	PNODE pEnd;
}LIST, * PLIST;

 void newList(PLIST pList) {
	
	PNODE Begin = new NODE;
	PNODE End = new NODE;

	pList->pBegin = Begin;
	pList->pEnd = End;

	pList->pBegin->pPrev = NULL;
	pList->pEnd->pNext = NULL;

	pList->pBegin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBegin;
}

 void InputString(char* pString, int size) {

	cin.clear();
	cin.ignore(1024, '\n'); //이전에 입력을 위한 enter 나 space 키를 버퍼에서 지운다.

	cin.getline(pString, size - 1); // 마지막 문자열에는 NULL 값이 들어가야 하기 때문에 -1 까지만  입력 받음
}

int InputInt() {
	int i;
	cin >> i;

	return i;
}

 void INSERT(PLIST pList) {
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
	pNode->tStudent = tStudent;
	
	PNODE PREV = pList->pEnd->pPrev;

	PREV->pNext = pNode;
	pNode->pPrev = PREV;

	pNode->pNext = pList->pEnd;
	pList->pEnd->pPrev = pNode;

	++pList->iSize;

}

 void OutputStudent(const PSTUDENT pStudent) {

	 cout << "이름 : " << pStudent->strName << "\t학번: " << pStudent->iNumber << endl;
	 cout << "국어 : " << pStudent->iKor << "\t영어: " << pStudent->iEng << endl;
	 cout << "수학 : " << pStudent->iMath << "\t총점: " << pStudent->iTotal << endl;
	 cout << "평균: " << pStudent->avg << endl << endl;
 }

 void SEARCH(PLIST pList) {

	 system("cls");
	 cout << "===============학생 검색==============" << endl;
	 cout << "검색할 학생 이름 입력: ";
	 char NAME[NAME_SIZE] = {};
	 InputString(NAME, NAME_SIZE);

	 PNODE pNode = pList->pBegin->pNext;

	 while (pNode != pList->pEnd) {
		 if (strcmp(NAME, pNode->tStudent.strName) == 0) {
			 OutputStudent(&(pNode->tStudent));
			 system("pause");
			 return;
		 }

		 pNode = pNode->pNext;
		 
	 }
	 cout<< NAME << " 학생 없음" << endl;
	 system("pause");

 }

 void OUTPUT(PLIST pList) {
	 system("cls");
	 cout << "================학생 출력==============="<<endl;
	 PNODE pNode = pList->pBegin->pNext;

	 while (pNode != pList->pEnd) {
		OutputStudent(&(pNode->tStudent));
		
		 pNode = pNode->pNext;
		 
	 }
	 system("pause");
 }

 void DELETE(PLIST pList) {
	 system("cls");
	 cout << "===============학생 삭제==============" << endl;
	 cout << "삭제할 학생 이름 입력: ";
	 char NAME[NAME_SIZE] = {};
	 InputString(NAME, NAME_SIZE);

	 PNODE pNode = pList->pBegin->pNext;

	 while (pNode != pList->pEnd) {
		 if (strcmp(NAME, pNode->tStudent.strName) == 0) {
			 

			 pNode->pPrev->pNext = pNode->pNext;
			 pNode->pNext->pPrev = pNode->pPrev;
			 delete pNode;

			 cout << "삭제 완료"<<endl;
			 system("pause");
			 return;
		 }

		 pNode = pNode->pNext;
	 }

	 cout << "삭제 실패" << endl;
	 system("pause");
 }

 void Lineup(PLIST pList) {
	 system("cls");
	 cout << "=============학생 정렬===========" << endl;

	
			system("cls");
			cout << "==============학번 기준 정렬=============" << endl;
			
			PNODE pNode = pList->pBegin->pNext;

			

			while (pNode != pList->pEnd->pPrev) {
				PNODE pLast = pList->pEnd->pPrev;

				while (pLast != pNode) {

				

					if (pLast->tStudent.iNumber < pLast->pPrev->tStudent.iNumber) {

						STUDENT pStudent = pLast->tStudent;
						STUDENT ppStudent = pLast->pPrev->tStudent;

						/*PNODE PREV = pLast->pPrev;
						PREV->pNext = pLast->pNext;
						pLast->pNext->pPrev = PREV;

						delete pLast;

						PNODE pLast = new NODE;
						pLast->tStudent = pStudent;
						pLast->pNext = PREV;
						pLast->pPrev = PREV->pPrev;

						PREV->pPrev->pNext = pLast;
						PREV->pPrev = pLast;*/

						pLast->tStudent = ppStudent;
						pLast->pPrev->tStudent = pStudent;

						

					}

					
						pLast = pLast->pPrev;
					
						cout << pLast->tStudent.iNumber << endl;
						system("pause");
					
				}
				pNode = pNode->pNext;
			}
			
		

	 OUTPUT(pList);
 }


