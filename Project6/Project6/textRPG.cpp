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

struct _INVENTORY { //열거체 MENU의 INVENTORY와 겹치면 에러 발생
	int gold;
};

struct PLAYER {
	char name[NAME_SIZE];
	char jobname[NAME_SIZE];
	JOB playerjob;
	int attackMin; //공격력 최대 최소
	int attackMax;
	int armorMin; // 방어력 최대 최소
	int armorMax;
	int hp;
	int hpMax; //현재 체력, 최대 체력
	int mp;
	int mpMax; // 현재 마나, 최대 마나
	int exp;
	int level;
	_INVENTORY inventory;

};

struct MONSTER {
	char name[NAME_SIZE];
	int attackMin; //공격력 최대 최소
	int attackMax;
	int armorMin; // 방어력 최대 최소
	int armorMax;
	int hp;
	int hpMax; //현재 체력, 최대 체력
	int mp;
	int mpMax; // 현재 마나, 최대 마나
	int exp; //처치시 획득할 경험치
	int level;
	int goldMax;//처치시 드랍 골드 최대 최소
	int goldMin;

};



int main() {

	srand((unsigned int)time(NULL));

	//게임 시작할 때 플레이어 정보 입력 받는다

	PLAYER player = {};
	cout << "이름: ";
	cin.getline(player.name, NAME_SIZE - 1); // 입력 받을 수 있는 최대 용량 =  NAME_SIZE - 1
	// -1 의 이유=  문자열(배열)의 마지막에는 NULL 값이 들어가야 하기 때문

	int job = JB_none;
	while (job == JB_none) {
		system("cls");
		cout << "1. 기사 " << endl;
		cout << "2. 궁수 " << endl;
		cout << "3. 마법사 " << endl;
		cout << "직업을 선택하세요: " ;
		cin >> job;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (job <= JB_none || job >= JB_end) {
			job == JB_none; // 1~3이외의 다른 값을 입력한 경우 job 변수에 JB_none을 넣어주어
			//while문(직업 선택)을 다시 선택할 수 있게 한다
		}

	}

	player.playerjob = (JOB)job; // PLAYER 변수 player의 멤버 playerjob에 입력 받은 값을 열거체 JOB 타입으로 대입 
	player.inventory.gold = 10000;
	player.level = 1;
	player.exp = 0; // 초기 레벨 =1 , 경험치 = 0
	//나머지 공격력, 마나 등은 직업에 따라 초기수치가 다르다


	switch (player.playerjob) {
		case knight: {
			strcpy_s(player.jobname, "기사");
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
			strcpy_s(player.jobname, "궁수");
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
			strcpy_s(player.jobname, "마법사");
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

	//몬스터 정보 입력(map 개수에 따라 3가지)

	MONSTER monster[MONSTER_NUM] = {};

	//고블린 생성

	strcpy_s(monster[0].name, "고블린");
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

	//트롤 생성

	strcpy_s(monster[1].name, "트롤");
	monster[1].attackMin = 80; //[]안에 숫자 한꺼번에 바꾸기 ==>alt + 클릭 & 드래그로 선택된 세로 범위 수정 가능
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

	//드래곤 생성

	strcpy_s(monster[2].name, "드래곤");
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
		cout << "====================== 로비 =========================" << endl;
		cout << "1. MAP" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요: ";
		int imenu;
		cin >> imenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (imenu == EXIT) {
			printf("\n 종료합니다\n");
			break;
		}

		switch (imenu) {
		case MAP: {
			while (true) {
				system("cls");
				cout << "====================== 맵 =========================" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요: ";
				int imap;
				cin >> imap;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (imap == BACK) {
					break; //맵 선택 while문을 빠져나간다 --> while 바깥의 break와 만나 첫번 째 while(메뉴 선택으로 돌아감)
				}

				MONSTER mop = monster[imap - 1];
				//imap에 선택된 숫자에서 -1을 해주면 MONSTER 타입의 배열 monster의 인덱스가 된다
				//ex. 1.쉬움 선택 --> -1 --> monster[0]에는 고블린이 들어있음

				while (true) {
					
					switch (imap) {
					system("cls");
					case EASY: {
						cout << "====================== 쉬움 =========================" << endl << endl;

						break;
					}

					case NORMAL: {
						cout << "====================== 보통 =========================" << endl << endl;

						break;
					}

					case HARD: {
						cout << "====================== 어려움 =========================" << endl << endl;

						break;
					}
					}

					//플레이어 정보를 출력한다
					cout << "====================== 플레이어 정보 =====================" << endl << endl;
					cout << "이름: " << player.name << "\t직업: " << player.jobname << endl;
					cout << "레벨: " << player.level << "\t경험치: " << player.exp << endl;
					cout << "공격력: " << player.attackMin << " ~ " << player.attackMax
						<< "\t방어력: " << player.armorMin << " ~ " << player.armorMax << endl;
					cout << "체력: " << player.hp << " / " << player.hpMax<<"\t마나: " << player.mp << " / " << player.mpMax << endl;
					cout << "골드: " << player.inventory.gold << endl << endl << endl;

					//몬스터 정보 출력
					cout << "====================== 몬스터 정보 =====================" << endl << endl;
					cout << "이름: " << mop.name << endl;
					cout << "레벨: " << mop.level << endl;
					cout << "공격력: " << mop.attackMin << " ~ " << mop.attackMax
						<< "\t방어력: " << mop.armorMin << " ~ " << mop.armorMax << endl;
					cout << "체력: " << mop.hp << " / " << mop.hpMax << "\t마나: " << mop.mp << " / " << mop.mpMax << endl;
					cout << "획득 경험치: " << mop.exp << "\t획득 골드: " << mop.goldMin << " - " << mop.goldMax << endl << endl;

					cout << " 1. 공격" << endl;
					cout << " 2. 도망가기" << endl;
					cout << " 행동을 선택하세요: ";
					int act;
					cin >> act;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (act == run) {
						cout << "도망쳤습니다" << endl;
						break;
					}
					switch (act) {
					case attack: {

						int iattack = rand() % (player.attackMax - player.attackMin + 1)
							+ (player.attackMin); //attackMax == 15, attakMin == 5의 경우
						// 5 ~ (15 - 1 - 5 + 1) + 5  = 5 ~15 중 하나 난수
						// rand()%15의 경우 0~ 14 중 난수가 생성 (즉, 0~ 15-1 까지 15개 범위)

						int iarmor = rand() % (mop.armorMax - mop.armorMin + 1)
							+ (mop.armorMin);

						int idamage = iattack - iarmor;
						//삼항연산자=> 조건식 ? true 일때 값 : false 일때 값;

						idamage = idamage < 1 ? 1 : idamage;  // iattack이 iarmor보다 작을 경우 idamage가  -가 되지 않고 -1이 되도록
						//밑의 if문과 동일
						/*if (idamage < 1) {
							idamage = 1;
						}*/

						mop.hp -= idamage;

						cout <<endl << player.name << "가 " << mop.name << "에게" << idamage << "의 피해를 입혔습니다. " << endl;

						//몬스터가 죽었을 경우
						if (mop.hp <= 0) {
							cout << mop.name << "사망" << endl;
							player.exp += mop.exp;
							int igold = rand() % (mop.goldMax - mop.goldMin + 1)
								+ mop.goldMin;
							player.inventory.gold += igold;

							cout << endl << mop.exp << "경험치 획득" << endl;
							cout << igold << "골드 획득" << endl;

							mop.hp = mop.hpMax;
							mop.mp = mop.mpMax; // 죽었을 경우 다음에 다시 싸울 때는 풀피로 싸워야하기 때문에
							system("pause");
							break;
						}

						//몬스터 사망X ==> 몬스터가 플레이어 공격
						iattack = rand() % (mop.attackMax - mop.attackMin + 1)
							+ (mop.attackMin);
						iarmor = rand() % (player.armorMax - player.armorMin + 1)
							+ (player.armorMin);
						idamage = iattack - iarmor;
						idamage = idamage < 1 ? 1 : idamage;
						player.hp -= idamage;
						cout << endl << mop.name << "가 " << player.name << "에게" << idamage << "의 피해를 입혔습니다. " << endl;

						//플레이어 죽었을 경우
						if (player.hp <= 0) {
							cout << player.name << " DIED..." << endl;

							//사망 페널티로 골드 & 경험치 감소
							int iexp = player.exp * 0.1f;
							int igold = player.inventory.gold * 0.1f;

							player.exp -= iexp;
							player.inventory.gold -= igold;

							cout << endl << iexp << " 경험치 lost" << endl;
							cout << igold << " 골드 lost" << endl;

							//플레이어 부활
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
			cout << "잘못된 선택입니다." << endl;
			break;
		}
		}
	}

	return 0;
}