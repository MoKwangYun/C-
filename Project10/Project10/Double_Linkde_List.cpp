#include<iostream>

using namespace std;

#define NAME_SIZE 32
typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float avg;
}STUDENT, *PSTUDENT;

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

void InitList(PLIST pList) {//��� �ʱ�ȭ �Լ�
	pList->iSize = 0;

	pList->pBegin 

}
int main() {

	LIST tList;

	InitList(&tList);
}