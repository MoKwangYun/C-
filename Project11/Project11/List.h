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
	cin.ignore(1024, '\n'); //������ �Է��� ���� enter �� space Ű�� ���ۿ��� �����.

	cin.getline(pString, size - 1); // ������ ���ڿ����� NULL ���� ���� �ϱ� ������ -1 ������  �Է� ����
}

int InputInt() {
	int i;
	cin >> i;

	return i;
}

 void INSERT(PLIST pList) {
	system("cls");
	cout << "==============�л��߰�============" << endl;

	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�й� : ";
	tStudent.iNumber = InputInt();

	cout << "���� : ";
	tStudent.iKor = InputInt();

	cout << "���� : ";
	tStudent.iEng = InputInt();

	cout << "���� : ";
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

	 cout << "�̸� : " << pStudent->strName << "\t�й�: " << pStudent->iNumber << endl;
	 cout << "���� : " << pStudent->iKor << "\t����: " << pStudent->iEng << endl;
	 cout << "���� : " << pStudent->iMath << "\t����: " << pStudent->iTotal << endl;
	 cout << "���: " << pStudent->avg << endl << endl;
 }

 void SEARCH(PLIST pList) {

	 system("cls");
	 cout << "===============�л� �˻�==============" << endl;
	 cout << "�˻��� �л� �̸� �Է�: ";
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
	 cout<< NAME << " �л� ����" << endl;
	 system("pause");

 }

 void OUTPUT(PLIST pList) {
	 system("cls");
	 cout << "================�л� ���==============="<<endl;
	 PNODE pNode = pList->pBegin->pNext;

	 while (pNode != pList->pEnd) {
		OutputStudent(&(pNode->tStudent));
		
		 pNode = pNode->pNext;
		 
	 }
	 system("pause");
 }

 void DELETE(PLIST pList) {
	 system("cls");
	 cout << "===============�л� ����==============" << endl;
	 cout << "������ �л� �̸� �Է�: ";
	 char NAME[NAME_SIZE] = {};
	 InputString(NAME, NAME_SIZE);

	 PNODE pNode = pList->pBegin->pNext;

	 while (pNode != pList->pEnd) {
		 if (strcmp(NAME, pNode->tStudent.strName) == 0) {
			 

			 pNode->pPrev->pNext = pNode->pNext;
			 pNode->pNext->pPrev = pNode->pPrev;
			 delete pNode;

			 cout << "���� �Ϸ�"<<endl;
			 system("pause");
			 return;
		 }

		 pNode = pNode->pNext;
	 }

	 cout << "���� ����" << endl;
	 system("pause");
 }

 void Lineup(PLIST pList) {
	 system("cls");
	 cout << "=============�л� ����===========" << endl;

	
			system("cls");
			cout << "==============�й� ���� ����=============" << endl;
			
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


