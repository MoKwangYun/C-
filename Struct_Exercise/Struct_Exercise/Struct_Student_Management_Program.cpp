#include<stdio.h>
#include<iostream>

using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14 //�迭 ������ �� ���� ���� 14�ڸ� 000-0000-0000 NULL
#define STUDENT_MAX 10

enum MENU {
	none,
	M_insert,
	M_delet,
	M_search,
	M_print,
	M_exit
	//5���� �޴�
};

struct student {
	char name[NAME_SIZE];
	char add[ADDRESS_SIZE];
	char phone[PHONE_SIZE];
	int number;
	int kor;
	int eng;
	int math;
	int total;
	int avg;
};

int main() {
	student arr[STUDENT_MAX] = {};
	int count = 0; // arr�� ����� �л� ��� ���� ī��Ʈ�ϴ� ����, �Է��̳� ���� �� ���� ������ ���� �ε����ε� Ȱ��
	int stnum = 1;
	char searchname[NAME_SIZE] = {};
	char deletname[NAME_SIZE] = {};



	while (true) {
		system("cls");

		//�޴��� ���
		printf("1. �л� ���  2. �л� ����  3. �л� �˻�  4. �л� ���  5. ����\n");
		printf("�޴��� �����ϼ���: ");
		int m;
		cin >> m;

		if (cin.fail()) {
			//�������� ����ش�
			cin.clear();

			//�Է¹���(\n�� ��������)�� �˻��Ͽ� \n�� �����ش�
			cin.ignore(1024, '\n'); // ù�� ° �Ķ���� --> �˻��ϰ��� �ϴ�  ���� ũ�� / �ι�° �Ķ���� --> ã���� �ϴ� ����  ==> �Է¹��� ó������ \n�� �ִ� ������ ã�Ƽ� ��� ����
		
		}//cin.fail() --> �Է� ���� �߻����� �� true ��ȯ
		
		 //cin�� ���� �����ʿ� int ������ ���� ������ �Է��ؾ� �Ѵ�. ���� Ÿ�Կ� ���� �ʴ� �� �Է½� ���� �߻�!! 
		//==> ���� ó���� ���� �߻��ߴ��� üũ�� �ʿ� ����  ==> ���� �߻������� cin ���� �������� ����ְ� �Է¹��ۿ��� \n�� ���������Ƿ� ���۸� ��ȸ�ϸ� \n�� �����ش�
		//���� =�ӽ� �������

		if (m == M_exit) {
			break;
		}
		switch (m) {
			case M_insert:{//�л� ���� �߰�/ �̸�, �ּ�, ��ȣ, ����, ����, ���� �Է� 
				//�й�, ����, ����� ������  ���� ���
				 
				system("cls");
				printf("=================�л� �߰�===============\n");

				//�л� ����ü �迭�� ���� ���
				if (stnum == STUDENT_MAX) {
					printf("�迭�� �� �� �����Դϴ�.");
					break;
				}

				//�̸� �Է� �޴´�
				cout << "�̸� : ";
				cin >> arr[count].name;

				cout << "�ּ�: ";
				//cin >> arr[count].add; //���� �ϸ� ó�� ���� ���� �ν� X ==> ������ ���ڿ��� ������ �ν�
				
				cin.ignore(1024, '\n');//cin.getline�� \n�� ������ �ν��ϱ� ������ ������ ���� ���� �ִ� \n�� �����ش�

				cin.getline(arr[count].add, ADDRESS_SIZE);//�����̽��ٴ� ���ڿ��� �ν� & enter�� ������ ������ �ν� (�ι�° �Ķ����: �Է� ���� �ִ� ũ��)

				cout << "��ȣ: ";
				cin >> arr[count].phone;

				cout << "����: ";
				cin >> arr[count].kor;

				cout << "����: ";
				cin >> arr[count].math;

				cout << "����: ";
				cin >> arr[count].eng;

				arr[count].total = arr[count].kor + arr[count].eng + arr[count].math;

				arr[count].avg = arr[count].total / 3.f;

				arr[count].number = stnum;

				stnum++;
				count++;


				break;
			}
			case M_delet: {

				system("cls");

				cout << "==================�л� ���� ����==============" << endl;

			   //cin.ignore(1024, '\n');(�Է��� cin.getline���� ���� ���)
				cout << "������ �л� �̸� �Է�: ";
				cin >> deletname;

				for (int i = 0; i < count; i++) {
					if (strcmp(arr[i].name, deletname) == 0) {

						for (int j = i; j < count - 1; j++) {//ã�Ҵٸ� i+1 �ε������� �迭 �ϳ��� �մ��
							
							arr[j] = arr[j + 1];

						}

						count--;

						cout <<"�л� ���� ����" <<endl;

						break;
					}
				}


				break;
			}

			case M_search: {

				system("cls");

				cout << "==================�л� ���� �˻�==============" << endl;

				//cin.ignore(1024, '\n');
				cout << "�˻��� �л� �̸� �Է�: ";
				cin >> searchname;

				//��ϵǾ��ִ� �л� ����ŭ �ݺ��ϸ� �л� ã�´�
				for (int i = 0; i < count; i++) {
					if (strcmp(arr[i].name, searchname) == 0) {
						cout << "��ȣ: " << arr[i].number << endl;
						cout << "�̸�: " << arr[i].name << endl;
						cout << "�ּ�: " << arr[i].add << endl;
						cout << "��ȣ: " << arr[i].phone << endl;
						cout << "����: " << arr[i].kor << endl;
						cout << "����: " << arr[i].eng << endl;
						cout << "����: " << arr[i].math << endl;
						cout << "����: " << arr[i].total << endl;
						cout << "���: " << arr[i].avg << endl << endl;
						break;
					}
				}

				break;
			}

			case M_print: {
				system("cls");
				cout << "====================�л� ���===============" << endl;
				if (count == 0) {
					printf("��ϵ� ������ �����ϴ�.\n");
					break;
				}
				//��ϵ� �л� ����ŭ �ݺ��ϸ� ���� ���
				for (int i = 0; i < count; i++) {
					cout << "��ȣ: " << arr[i].number << endl;
					cout << "�̸�: " << arr[i].name << endl;
					cout << "�ּ�: " << arr[i].add << endl;
					cout << "��ȣ: " << arr[i].phone << endl;
					cout << "����: " << arr[i].kor << endl;
					cout << "����: " << arr[i].eng << endl;
					cout << "����: " << arr[i].math << endl;
					cout << "����: " << arr[i].total << endl;
					cout << "���: " << arr[i].avg << endl << endl;
				}
				break;
			}

			default: {
				printf("\n�߸��� �Է�]\n");
				break;
			}

			

		}

		system("pause");





	}






}