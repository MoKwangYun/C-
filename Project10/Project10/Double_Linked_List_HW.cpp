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
	cout << "===============�л� �߰�===============" << endl;

	STUDENT tStudent;
	cout << "�л� �̸�: ";
	
	INPUTSTRING(tStudent.strName, NAME_SIZE);
	//INPUTSTRING �Լ��� �����ͷ� �ּҸ� �޾ư��� ������  strName ������ ����
	//INPUTSTRING �Լ��� ���� �����

	cout << "�й�: ";
	cin >> tStudent.iNumber;

	cout << "����: ";
	cin >> tStudent.iKor;

	cout << "����: ";
	cin >> tStudent.iMath;

	cout << "����: ";
	cin >> tStudent.iEng;

	tStudent.iTotal = tStudent.iKor + tStudent.iMath + tStudent.iEng;
	tStudent.avg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE; //�� ������
	pNode->pNext = NULL;
	pNode->pPrev = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL) {//��� ó�� ����
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

	cout << "�̸� : " << pStudent->strName << "\t�й�: " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t����: " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << "\t����: " << pStudent->iTotal << endl;
	cout << "���: " << pStudent->avg << endl;
}

void OUTPUT(PLIST pList) {
	system("cls");
	cout << "==============�л� ��� ==============" << endl;

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		OutputStudent(&(pNode->tStudent));
		pNode = pNode->pNext;
	}

	cout << "�л� ��: " << pList->iSize << endl;
	system("pause");
}

int main() {

	LIST tList;

	tList.pBegin = NULL;
	tList.pEnd = NULL;
	tList.iSize = 0;

	while (true) {
		system("cls");
		cout << "1. �л� ���" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� �˻�" << endl;
		cout << "4. �л� ���" << endl;
		cout << "5. ����" << endl;

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

				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}

		}
	}

	return 0;
}