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
	
	//Begin과 End는 처음과 끝을 의미하도록 만든다(실제 데이터를 저장하는 노드는 아니고 
	//데이터를 저장하는 노드는 Begin과 End사이에 존재하도록 만든다
	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, * PLIST;

void InitList(PLIST pList) {//노드 초기화 함수
	pList->iSize = 0;

	pList->pBegin 

}
int main() {

	LIST tList;

	InitList(&tList);
}