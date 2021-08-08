#include<iostream>

#include"List.h" 
//사용자가 만든 헤더파일을 포함시킬 때는 ""안에 헤더파일 이름 작성
// --> 정의한 헤더파일 안에 작성된 함수, 구조체 등 사용 가능

using namespace std;



int main() {

	LIST tList;

	InitList(&tList);
	while (true) {

		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
			case MM_INSERT: { //노드 추가
				Push_Back(&tList);

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

	DestroyList(&tList);
	return 0;
}