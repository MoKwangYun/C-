#include<iostream>

#include"List.h" 
//����ڰ� ���� ��������� ���Խ�ų ���� ""�ȿ� ������� �̸� �ۼ�
// --> ������ ������� �ȿ� �ۼ��� �Լ�, ����ü �� ��� ����

using namespace std;



int main() {

	LIST tList;

	InitList(&tList);
	while (true) {

		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
			case MM_INSERT: { //��� �߰�
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