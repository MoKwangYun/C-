#include<stdio.h>
#include<iostream>
#include<time.h>

using namespace std;

enum BATTLE {
	no,
	attack,
	run
};
enum MENU {
	none,
	MAP,
	STORE,
	INVENTORY,
	EXIT
};

enum MAP_TYPE {
	nope,
	EASY,
	NORMAL,
	HARD,
	BACK
};

enum JOB {
	JB_none,
	knight,
	archer,
	wizard,
	JB_end
};

#define NAME_SIZE 32
#define MONSTER_NUM 3

struct _INVENTORY { //����ü MENU�� INVENTORY�� ��ġ�� ���� �߻�
	int gold;
};

struct PLAYER {
	char name[NAME_SIZE];
	char jobname[NAME_SIZE];
	JOB playerjob;
	int attackMin; //���ݷ� �ִ� �ּ�
	int attackMax;
	int armorMin; // ���� �ִ� �ּ�
	int armorMax;
	int hp;
	int hpMax; //���� ü��, �ִ� ü��
	int mp;
	int mpMax; // ���� ����, �ִ� ����
	int exp;
	int level;
	_INVENTORY inventory;

};

struct MONSTER {
	char name[NAME_SIZE];
	int attackMin; //���ݷ� �ִ� �ּ�
	int attackMax;
	int armorMin; // ���� �ִ� �ּ�
	int armorMax;
	int hp;
	int hpMax; //���� ü��, �ִ� ü��
	int mp;
	int mpMax; // ���� ����, �ִ� ����
	int exp; //óġ�� ȹ���� ����ġ
	int level;
	int goldMax;//óġ�� ��� ��� �ִ� �ּ�
	int goldMin;

};



int main() {

	srand((unsigned int)time(NULL));

	//���� ������ �� �÷��̾� ���� �Է� �޴´�

	PLAYER player = {};
	cout << "�̸�: ";
	cin.getline(player.name, NAME_SIZE - 1); // �Է� ���� �� �ִ� �ִ� �뷮 =  NAME_SIZE - 1
	// -1 �� ����=  ���ڿ�(�迭)�� ���������� NULL ���� ���� �ϱ� ����

	int job = JB_none;
	while (job == JB_none) {
		system("cls");
		cout << "1. ��� " << endl;
		cout << "2. �ü� " << endl;
		cout << "3. ������ " << endl;
		cout << "������ �����ϼ���: " ;
		cin >> job;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (job <= JB_none || job >= JB_end) {
			job == JB_none; // 1~3�̿��� �ٸ� ���� �Է��� ��� job ������ JB_none�� �־��־�
			//while��(���� ����)�� �ٽ� ������ �� �ְ� �Ѵ�
		}

	}

	player.playerjob = (JOB)job; // PLAYER ���� player�� ��� playerjob�� �Է� ���� ���� ����ü JOB Ÿ������ ���� 
	player.inventory.gold = 10000;
	player.level = 1;
	player.exp = 0; // �ʱ� ���� =1 , ����ġ = 0
	//������ ���ݷ�, ���� ���� ������ ���� �ʱ��ġ�� �ٸ���


	switch (player.playerjob) {
		case knight: {
			strcpy_s(player.jobname, "���");
			player.attackMin = 5;
			player.attackMax = 10;
			player.armorMin = 15;
			player.armorMax = 20;
			player.hpMax = 500;
			player.hp = 500;
			player.mpMax = 100;
			player.mp = 100;

			break;
		}
		case archer: {
			strcpy_s(player.jobname, "�ü�");
			player.attackMin = 10;
			player.attackMax = 15;
			player.armorMin = 15;
			player.armorMax = 20;
			player.hpMax = 400;
			player.hp = 400;
			player.mpMax = 200;
			player.mp = 200;
			
			break;
		}
		case wizard: {
			strcpy_s(player.jobname, "������");
			player.attackMin = 15;
			player.attackMax = 20;
			player.armorMin = 5;
			player.armorMax = 10;
			player.hpMax = 300;
			player.hp = 300;
			player.mpMax = 300;
			player.mp = 300;

			break;
		}
	}

	//���� ���� �Է�(map ������ ���� 3����)

	MONSTER monster[MONSTER_NUM] = {};

	//��� ����

	strcpy_s(monster[0].name, "���");
	monster[0].attackMin = 20;
	monster[0].attackMax = 30;
	monster[0].armorMin = 2;
	monster[0].armorMax = 5;
	monster[0].hp = 100;
	monster[0].hpMax = 100;
	monster[0].mp = 10;
	monster[0].mpMax = 10;
	monster[0].level = 1;
	monster[0].exp = 1000;
	monster[0].goldMin = 500;
	monster[0].goldMax = 1500;

	//Ʈ�� ����

	strcpy_s(monster[1].name, "Ʈ��");
	monster[1].attackMin = 80; //[]�ȿ� ���� �Ѳ����� �ٲٱ� ==>alt + Ŭ�� & �巡�׷� ���õ� ���� ���� ���� ����
	monster[1].attackMin = 130;
	monster[1].armorMin = 60;
	monster[1].armorMax = 90;
	monster[1].hp = 2000;
	monster[1].hpMax = 2000;
	monster[1].mp = 100;
	monster[1].mpMax = 100;
	monster[1].level = 5;
	monster[1].exp = 7000;
	monster[1].goldMin = 6000;
	monster[1].goldMax = 8000;

	//�巡�� ����

	strcpy_s(monster[2].name, "�巡��");
	monster[2].attackMin = 250;
	monster[2].attackMin = 500;
	monster[2].armorMin = 200;
	monster[2].armorMax = 400;
	monster[2].hp = 30000;
	monster[2].hpMax = 30000;
	monster[2].mp = 2000;
	monster[2].mpMax = 2000;
	monster[2].level = 10;
	monster[2].exp = 30000;
	monster[2].goldMin = 20000;
	monster[2].goldMax = 50000;


	while (true) {
		system("cls");
		cout << "====================== �κ� =========================" << endl;
		cout << "1. MAP" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ���: ";
		int imenu;
		cin >> imenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (imenu == EXIT) {
			printf("\n �����մϴ�\n");
			break;
		}

		switch (imenu) {
		case MAP: {
			while (true) {
				system("cls");
				cout << "====================== �� =========================" << endl;
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;
				cout << "���� �����ϼ���: ";
				int imap;
				cin >> imap;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (imap == BACK) {
					break; //�� ���� while���� ���������� --> while �ٱ��� break�� ���� ù�� ° while(�޴� �������� ���ư�)
				}

				MONSTER mop = monster[imap - 1];
				//imap�� ���õ� ���ڿ��� -1�� ���ָ� MONSTER Ÿ���� �迭 monster�� �ε����� �ȴ�
				//ex. 1.���� ���� --> -1 --> monster[0]���� ����� �������

				while (true) {
					
					switch (imap) {
					system("cls");
					case EASY: {
						cout << "====================== ���� =========================" << endl << endl;

						break;
					}

					case NORMAL: {
						cout << "====================== ���� =========================" << endl << endl;

						break;
					}

					case HARD: {
						cout << "====================== ����� =========================" << endl << endl;

						break;
					}
					}

					//�÷��̾� ������ ����Ѵ�
					cout << "====================== �÷��̾� ���� =====================" << endl << endl;
					cout << "�̸�: " << player.name << "\t����: " << player.jobname << endl;
					cout << "����: " << player.level << "\t����ġ: " << player.exp << endl;
					cout << "���ݷ�: " << player.attackMin << " ~ " << player.attackMax
						<< "\t����: " << player.armorMin << " ~ " << player.armorMax << endl;
					cout << "ü��: " << player.hp << " / " << player.hpMax<<"\t����: " << player.mp << " / " << player.mpMax << endl;
					cout << "���: " << player.inventory.gold << endl << endl << endl;

					//���� ���� ���
					cout << "====================== ���� ���� =====================" << endl << endl;
					cout << "�̸�: " << mop.name << endl;
					cout << "����: " << mop.level << endl;
					cout << "���ݷ�: " << mop.attackMin << " ~ " << mop.attackMax
						<< "\t����: " << mop.armorMin << " ~ " << mop.armorMax << endl;
					cout << "ü��: " << mop.hp << " / " << mop.hpMax << "\t����: " << mop.mp << " / " << mop.mpMax << endl;
					cout << "ȹ�� ����ġ: " << mop.exp << "\tȹ�� ���: " << mop.goldMin << " - " << mop.goldMax << endl << endl;

					cout << " 1. ����" << endl;
					cout << " 2. ��������" << endl;
					cout << " �ൿ�� �����ϼ���: ";
					int act;
					cin >> act;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (act == run) {
						cout << "�����ƽ��ϴ�" << endl;
						break;
					}
					switch (act) {
					case attack: {

						int iattack = rand() % (player.attackMax - player.attackMin + 1)
							+ (player.attackMin); //attackMax == 15, attakMin == 5�� ���
						// 5 ~ (15 - 1 - 5 + 1) + 5  = 5 ~15 �� �ϳ� ����
						// rand()%15�� ��� 0~ 14 �� ������ ���� (��, 0~ 15-1 ���� 15�� ����)

						int iarmor = rand() % (mop.armorMax - mop.armorMin + 1)
							+ (mop.armorMin);

						int idamage = iattack - iarmor;
						//���׿�����=> ���ǽ� ? true �϶� �� : false �϶� ��;

						idamage = idamage < 1 ? 1 : idamage;  // iattack�� iarmor���� ���� ��� idamage��  -�� ���� �ʰ� -1�� �ǵ���
						//���� if���� ����
						/*if (idamage < 1) {
							idamage = 1;
						}*/

						mop.hp -= idamage;

						cout <<endl << player.name << "�� " << mop.name << "����" << idamage << "�� ���ظ� �������ϴ�. " << endl;

						//���Ͱ� �׾��� ���
						if (mop.hp <= 0) {
							cout << mop.name << "���" << endl;
							player.exp += mop.exp;
							int igold = rand() % (mop.goldMax - mop.goldMin + 1)
								+ mop.goldMin;
							player.inventory.gold += igold;

							cout << endl << mop.exp << "����ġ ȹ��" << endl;
							cout << igold << "��� ȹ��" << endl;

							mop.hp = mop.hpMax;
							mop.mp = mop.mpMax; // �׾��� ��� ������ �ٽ� �ο� ���� Ǯ�Ƿ� �ο����ϱ� ������
							system("pause");
							break;
						}

						//���� ���X ==> ���Ͱ� �÷��̾� ����
						iattack = rand() % (mop.attackMax - mop.attackMin + 1)
							+ (mop.attackMin);
						iarmor = rand() % (player.armorMax - player.armorMin + 1)
							+ (player.armorMin);
						idamage = iattack - iarmor;
						idamage = idamage < 1 ? 1 : idamage;
						player.hp -= idamage;
						cout << endl << mop.name << "�� " << player.name << "����" << idamage << "�� ���ظ� �������ϴ�. " << endl;

						//�÷��̾� �׾��� ���
						if (player.hp <= 0) {
							cout << player.name << " DIED..." << endl;

							//��� ���Ƽ�� ��� & ����ġ ����
							int iexp = player.exp * 0.1f;
							int igold = player.inventory.gold * 0.1f;

							player.exp -= iexp;
							player.inventory.gold -= igold;

							cout << endl << iexp << " ����ġ lost" << endl;
							cout << igold << " ��� lost" << endl;

							//�÷��̾� ��Ȱ
							player.hp = player.hpMax;
							player.mp = player.mpMax;

						}

						break;
					}//case attack:
					}//switch


				}
			}
			break;
		}//case map:

				
		
		

		case STORE: {

			break;
		}

		case INVENTORY: {

			break;
		}
		default: {
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
		}
	}

	return 0;
}