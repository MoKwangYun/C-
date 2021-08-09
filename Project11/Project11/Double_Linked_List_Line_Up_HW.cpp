#include<iostream>
#include"List.h"

enum MENU {
	M_NONE,
	M_INSERT,
	M_DELETE,
	M_SEARCH,
	M_OUTPUT,
	M_LINE_UP,
	M_EXIT
};

int main() {
	LIST tList;

	newList(&tList);

	while (true) {
		system("cls");
		cout << "1. 학생 추가" << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 탐색" << endl;
		cout << "4. 학생 출력" << endl;
		cout << "5. 정렬" << endl;
		cout << "6. 종료" <<endl;
		cout << "번호 입력: ";

		int iMenu;

		cin >> iMenu;

		if (iMenu == M_EXIT)
			break;

		switch (iMenu) {
			case M_INSERT: {
				INSERT(&tList);
				break;
			}
			case M_DELETE: {
				DELETE(&tList);
				break;
			}
			case M_SEARCH: {
				SEARCH(&tList);
				break;
			}
			case M_OUTPUT: {
				OUTPUT(&tList);
				break;
			}
			case M_LINE_UP: {
				Lineup(&tList);
				break;
			}
			
			default: {
				cout << "잘못된 입력입니다." << endl;
				system("pause");
				break;
			}
		}

	}
}