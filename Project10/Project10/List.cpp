#include "List.h"

//****!!!!List.h ������Ͽ��� ������ �Լ��� ����!!!***

void InitList(PLIST pList) {//��� �ʱ�ȭ �Լ�
	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE; //ó���� �������� �ǹ��ϴ� ��带 �����Ҵ� ���ش�.
	//���� �����͸� �����ϴ� �뵵�� �ƴ� Begin�� End���� �ǹ�


	pList->pEnd->pNext = NULL;

	pList->pBegin->pPrev = NULL; //Begin����� ���� ���� ���� ������ NULL

	pList->pBegin->pNext = pList->pEnd;//�ʱ⿡�� Begin�� End��常�� �����ϱ� ������ 
	//Begin����� ���� ��带 End���� �������ش�

	pList->pEnd->pPrev = pList->pBegin;



}

void DestroyList(PLIST pList)//��� ��带 �����
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

	pNode->tStudent = tStudent; //������ tStudent�� Push_Back�Լ����� ������ STUDENT ����ü �����̴�.
	//������ tStudent�� NODE ����ü�� ���

	//���� �߰��Ǵ� ���� End����� prev ��尡 �ȴ�
	
	PNODE PREV = pList->pEnd->pPrev;//�߰��Ǳ� ������ End ����� prev ��带 ���س��´�

	pNode->pPrev = PREV; //End ����� ���� ���� ��尡 �߰��ϴ� ����� ������尡 ��
	PREV->pNext = pNode;
	//�߰��� ���� ���� ���(PREV)����

	pList->pEnd->pPrev = pNode;
	pNode->pNext = pList->pEnd;
	//�߰��� ���� pEnd ��� ����

	++pList->iSize;
}

void Push_Front(PLIST pList)
{

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
}

void OutputStudent(const PSTUDENT pStudent) {

	cout << "�̸� : " << pStudent->strName << "\t�й�: " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t����: " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << "\t����: " << pStudent->iTotal << endl;
	cout << "���: " << pStudent->avg << endl << endl;
}

void Output(PLIST pList) {//��� ������ ���� �� �ֵ���!

	int iMenu;
	while (true) {
		system("cls");
		cout << "=================�л� ���=====================" << endl;
		cout << "1. ������ ���" << endl;
		cout << "2. ������ ���" << endl;
		cout << "3. �޴��� �����ϼ���: ";

		iMenu = InputInt();
		
		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu) {
		case OT_OUTPUT: {
			pNode = pList->pBegin->pNext;//Begin ����� ���� ������ End ����� ������� ���� ������� ���

			while (pNode != pList->pEnd) {//pEnd�� �������� break == pEnd ����� ���� ������ �ݺ�
				OutputStudent(&pNode->tStudent);
				pNode = pNode ->pNext;
			}
			break;
		}
		case OT_INVERSE: {

			pNode = pList->pEnd->pPrev; 
			//�̱۸�ũ�帮��Ʈ�� ���� ��带 ����ų �� ���� ������ �̱۸�ũ�帮��Ʈ�� �Ұ����� ���. only Begin -> End
			//����ũ�帮��Ʈ�� ��������� ������ �����ϴ�. End -> Begin�� ����

			while (pNode != pList->pBegin) {
				OutputStudent(&(pNode->tStudent));
				pNode = pNode->pPrev;
			}
			break;
		}
	}
	cout << "�л��� : " << pList->iSize;
	system("pause");
}

void Search(PLIST pList) {
	system("cls");
	cout << "=================�л� Ž��==================" << endl;
	cout << "�˻��� �л� �̸� �Է�: ";
	char Name[NAME_SIZE] = {};
	InputString(Name, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(Name, pNode->tStudent.strName) == 0) {
			OutputStudent(&(pNode->tStudent));

			cout << endl << "��� �Ϸ�" << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << Name << " �л��� �������� �ʽ��ϴ�." << endl;

	system("pause");
}

void Delete(PLIST pList) {
	system("cls");
	cout << "=================�л� ����==================" << endl;
	cout << "������ �л� �̸� �Է�: ";
	char Name[NAME_SIZE] = {};
	InputString(Name, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(Name, pNode->tStudent.strName) == 0) {

			cout << Name << " �л� ����" << endl;

			pNode->pPrev->pNext = pNode->pNext;//pNode  �� �����ϱ� ������ pNode�� ���� ����� next ���� pNode�� next ��尡 �ȴ�
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			system("pause");

			return;
		}

		pNode = pNode->pNext;
	}

	cout << Name << " �л��� �������� �ʽ��ϴ�." << endl;

	system("pause");

}
