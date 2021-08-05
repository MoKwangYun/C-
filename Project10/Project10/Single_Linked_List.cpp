#include<iostream>

using namespace std;

#define NAME_SIZE 32

enum MAIN_MENU { //����ü
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
��ũ�帮��Ʈ : �ڷᱸ���� �� ���� (�ڷᱸ�ڶ� �����͸� �����ϴ� ����� ���Ѵ�)
��ũ�帮��Ʈ�� ������ ����� ������Ѽ� ������ �� �ִ� ������ �����Ѵ�.
��ũ�帮��Ʈ�� �����͸� �����ϱ� ���� ��� ����, �� ����� Ư¡�� ���� ��带 �� �� �ְ� �ȴٴ� ��!(= ���� ����� �޸� �ּҸ� �����Ѵٴ� �ǹ�)

����Ʈ�� ���������� �Ǿ��ִ� --> �迭�� ���� Ư�� ��ҿ� �ٷ� ���� �Ұ�(������ �տ������� ���ʴ�� Ÿ�� ���� ���� ����)
��带 ���� �߰��� ���� ���  ���� & ������ ��忡 ���Ḹ ���ָ� �� --> ������ ���� ����
*/

//����Ʈ ���  �����
typedef struct _tagNode {

	STUDENT tStudent;
	_tagNode* pNext;

}NODE, *PNODE;

//����Ʈ ����ü�� ����� / ó�� & ������ ��� �ּ� + ��� ����
typedef struct _tagList {

	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, *PLIST;

int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) { //�Է½����� ��� (ex. ���� �Է��ؾ� �ϴµ� ���� �Է��ϴ� ��
		cin.clear(); //�߸� �Էµ� ���۸� �����
		cin.ignore(1024, '\n');
		return INT_MAX;
	}


	return iInput;

}
void InitList(PLIST pList) {//����Ʈ ����ü�� �ּҸ� �Ķ���ͷ� �޾ƿ´�

	pList->pBegin = NULL; // ������ �ʱ�ȭ�� NULL�� !!
	pList->pEnd = NULL;
	pList-> iSize = 0;

}

int OutputMenu() {
	system("cls");
	cout << "1. �л��߰� " << endl;
	cout << "2. �л����� " << endl;
	cout << "3. �л�Ž�� " << endl;
	cout << "4. �л����" << endl;
	cout << "5. ���� " << endl;
	cout << " �޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput>MM_EXIT)
		return MM_NONE;

	return iInput;
}

void InputString(char* pString, int size) {

	cin.clear();
	cin.ignore(1024, '\n'); //������ �Է��� ���� enter �� space Ű�� ���ۿ��� �����.

	cin.getline(pString, size - 1); // ������ ���ڿ����� NULL ���� ���� �ϱ� ������ -1 ������  �Է� ����
}

void Insert(PLIST pList) { //��� �߰� �Լ�

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

	//�߰��� ��� ����

	PNODE pNode = new NODE; // ��� �ϳ� �����Ҵ� & �� �޸� �ּҸ� pNode�� ������ �ִ�.
	pNode->pNext = NULL; //�߰��ϴ� ��尡 ������ ��尡 �Ǳ� ������ �߰��� ����� ��ũ �κ��� ����ų �ּҴ� ���� ����
	pNode->tStudent = tStudent; // ������ �Է� ���� �л� ������ �߰��� ����� �����ͺο� ��aa��

	if (pList->pBegin == NULL) // ���� ��尡 ����(��� ������ ��尡 ó�� ����)
		pList->pBegin = pNode;

	else {//��ũ�帮��Ʈ�� ��� �̹� ����
		pList->pEnd->pNext = pNode;//������ ��� �߰��ϱ� ������ End ����� ��ũ�� �߰��� ����� �ּ� ����

	}

	pList->pEnd = pNode; //�߰��� ��尡 ������ ��尡 �Ǳ� ������ List�� End ��忡 ���� ������ ��带 ����

	++pList->iSize;
}

void ClearList(PLIST pList) {
	PNODE pNode = pList->pBegin;
	//PNODE�� ������ Ÿ���̱� ������ pBegin�� ����Ű�� ����� �ּҸ� pNode�� ����

	while (pNode != NULL) {
		PNODE  pNext = pNode->pNext; //pNext ��忡 pNode�� Next�� ����Ű�� ��� �ּҸ� ����
		delete pNode; //pNode�� ����Ű�� ��� ����
		pNode = pNext; //������ ������ Next�� ����� ��� �ּҸ� pNode�� �ٽ� ���� 
					   // ���� ��尡 ���� ��� Next�� NULL�̰� pNode�� NULL�� ����ȴ�
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

//const �������̱� ������ ����Ű�� ����� �� ���� �Ұ�
void OutputStudent(const PSTUDENT pStudent) {

	cout << "�̸� : " << pStudent->strName << "\t�й�: " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t����: " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << "\t����: " << pStudent->iTotal << endl;
	cout << "���: " << pStudent->avg << endl;
}

void Output(PLIST pList) {
	system("cls");
	cout << "=======================�л� ���=================" << endl;

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext; //���� ����� �ּҸ� ����
	}

	cout << "�л���: " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << " =============�л� Ž��============" << endl;
	cout << "Ž���� �̸��� �Է��ϼ���: ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		//��ġ���� ���� ���
		pNode = pNode->pNext;
	}
	//while�� �ȿ��� return ���� �ʰ� ���������� ��� == ��ġ�ϴ� �л� �̸� ����

	cout << "��ġ�ϴ� �̸��� �����ϴ�. " << endl;

	system("pause");

}

void Delete(PLIST pList) {
	system("cls");
	cout << " ==========�л� ����==============" << endl;
	cout << "������ �л� �̸� �Է�: ";
	char strName[NAME_SIZE];
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			PNODE NEXT = pNode->pNext;

			//ù��° ��带 ���� ���(= pPrev�� NULL)
			if (pPrev == NULL) {
				delete pNode;
				pList->pBegin = NEXT;

				if (NEXT == NULL)//���� ��尡 ���� ���
					pList->pEnd = NULL;
			}

			//���� ��尡 �ִ� ���
			else {
				delete pNode;
				pPrev->pNext = NEXT;

				if (NEXT == NULL) //Next�� NULL ==> ������ ��尡 ������ ����� ���
					pList->pEnd = pPrev;
			}
			
			cout << strName << " �л� ���� �Ϸ�" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		
		//���� pNode�� �Է� �̸��� ��ġ���� �ʾұ� ������ ���� ��� �񱳸� ����
		//���� ���� ���� ��尡 �ǰ� ���� ��� �ּҸ� pNode�� ����
		pPrev = pNode;
		pNode = pNode->pNext;

	}
	cout << "��ġ�ϴ� �̸��� �����ϴ�." << endl;
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
			case MM_INSERT: { //��� �߰�
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