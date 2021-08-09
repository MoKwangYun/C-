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
		cout << "1. �л� �߰�" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� Ž��" << endl;
		cout << "4. �л� ���" << endl;
		cout << "5. ����" << endl;
		cout << "6. ����" <<endl;
		cout << "��ȣ �Է�: ";

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
				cout << "�߸��� �Է��Դϴ�." << endl;
				system("pause");
				break;
			}
		}

	}
}