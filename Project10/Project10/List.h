#pragma once
// #pragma once : �� ��������� �� 1�������Խ�Ű�ڴٴ� �ǹ�
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

enum OUTPUT_TYPE {
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float avg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;

}NODE, * PNODE;

typedef struct _taglist {

	//Begin�� End�� ó���� ���� �ǹ��ϵ��� �����(���� �����͸� �����ϴ� ���� �ƴϰ� 
	//�����͸� �����ϴ� ���� Begin�� End���̿� �����ϵ��� �����
	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, * PLIST;

static int InputInt() {//����� ���� �ϴ� ���� �ƴ϶� ����� ���Ǹ� �� �� �ϴ� ��� �տ� static�� �ٿ��ش�
	int iInput;
	cin >> iInput;

	if (cin.fail()) { //�Է½����� ��� (ex. ���� �Է��ؾ� �ϴµ� ���� �Է��ϴ� ��
		cin.clear(); //�߸� �Էµ� ���۸� �����
		cin.ignore(1024, '\n');
		return INT_MAX;
	}


	return iInput;

}

static void InputString(char* pString, int size) {

	cin.clear();
	cin.ignore(1024, '\n'); //������ �Է��� ���� enter �� space Ű�� ���ۿ��� �����.

	cin.getline(pString, size - 1); // ������ ���ڿ����� NULL ���� ���� �ϱ� ������ -1 ������  �Է� ����
}

static int OutputMenu() {
	system("cls");
	cout << "1. �л��߰� " << endl;
	cout << "2. �л����� " << endl;
	cout << "3. �л�Ž�� " << endl;
	cout << "4. �л����" << endl;
	cout << "5. ���� " << endl;
	cout << " �޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

//****!!!������Ͽ��� ���� �Լ� ����κ��� ������ش�!!!*******

void InitList(PLIST pList);
void DestroyList(PLIST pList); 
void Push_Back(PLIST pList); //������ ��� �ڿ� ��带 �߰��ϴ� �Լ�(pEnd ��� �� ��ġ�� ����� �߰�)
void Push_Front(PLIST pList); //�� ó�� ��� �ڿ� ��� �߰��ϴ� �Լ�(pBegin ��� ���� ��ġ�� ����� �߰�)
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);


//�Լ� ���� �� ctrl + . ���� �� �Լ� ����/���� ������ �Լ� ���� �ҽ� ����(List.cpp)�� ���Ǹ� ���� Ʋ �ڵ� ������
//****!!!������Ͽ��� ���� �Լ� ����κ��� ������ش�!!!*******
