#pragma once
// #pragma once : 이 헤더파일은 딱 1번만포함시키겠다는 의미
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

	//Begin과 End는 처음과 끝을 의미하도록 만든다(실제 데이터를 저장하는 노드는 아니고 
	//데이터를 저장하는 노드는 Begin과 End사이에 존재하도록 만든다
	PNODE pBegin;
	PNODE pEnd;
	int iSize;

}LIST, * PLIST;

static int InputInt() {//헤더에 선언만 하는 것이 아니라 선언과 정의를 둘 다 하는 경우 앞에 static을 붙여준다
	int iInput;
	cin >> iInput;

	if (cin.fail()) { //입력실패한 경우 (ex. 정수 입력해야 하는데 문자 입력하는 등
		cin.clear(); //잘못 입력된 버퍼를 지운다
		cin.ignore(1024, '\n');
		return INT_MAX;
	}


	return iInput;

}

static void InputString(char* pString, int size) {

	cin.clear();
	cin.ignore(1024, '\n'); //이전에 입력을 위한 enter 나 space 키를 버퍼에서 지운다.

	cin.getline(pString, size - 1); // 마지막 문자열에는 NULL 값이 들어가야 하기 때문에 -1 까지만  입력 받음
}

static int OutputMenu() {
	system("cls");
	cout << "1. 학생추가 " << endl;
	cout << "2. 학생삭제 " << endl;
	cout << "3. 학생탐색 " << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료 " << endl;
	cout << " 메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

//****!!!헤더파일에는 보통 함수 선언부분을 만들어준다!!!*******

void InitList(PLIST pList);
void DestroyList(PLIST pList); 
void Push_Back(PLIST pList); //마지막 노드 뒤에 노드를 추가하는 함수(pEnd 노드 전 위치에 새노드 추가)
void Push_Front(PLIST pList); //맨 처음 노드 뒤에 노드 추가하는 함수(pBegin 노드 다음 위치에 새노드 추가)
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);


//함수 선택 후 ctrl + . 누른 뒤 함수 선언/정의 누르면 함수 정의 소스 파일(List.cpp)에 정의를 위한 틀 자동 생성됨
//****!!!헤더파일에는 보통 함수 선언부분을 만들어준다!!!*******
