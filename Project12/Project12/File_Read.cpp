#include<iostream>

using namespace std;

int main() {

	FILE* pFile = NULL;

	fopen_s(&pFile, "hot.txt", "rt"); //�ؽ�Ʈ ���� �б� ��� = rb

	if (pFile) {

		char strText[5] = {};

		//1��° ���� --> ���� �о�� �����͸� ������ ������
		//2��° ���� -->  �о�� ������ Ÿ���� �޸� ũ��
		//3	��° ���� --> �о�� �������� �޸� ũ��
		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);

		cout << "���� �б� �Ϸ�" << endl;
	}

	return 0;
}