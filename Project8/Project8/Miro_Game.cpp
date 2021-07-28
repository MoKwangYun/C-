#include<iostream>
#include<conio.h>
using namespace std;

/*
	0: ��
	1: ��
	2: ������
	3: ������
	4: ��ź
	5: ��ź ����Ʈ
*/


struct _tagPoint {
	int x;
	int y;
};

// typedef : Ÿ���� �������ϴ� ���
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;
	
	strcpy_s(Maze[0], "21100000000000000000"); //���ڿ� ���������� NULL���ڰ� �־�� �ϱ� ������
	strcpy_s(Maze[1], "00111111111100000000"); // ���ڿ� ũ�� == �迭 ũ�� -1
	strcpy_s(Maze[2], "00100010000111111100");
	strcpy_s(Maze[3], "01100010000000000100");
	strcpy_s(Maze[4], "01000011110000000100");
	strcpy_s(Maze[5], "01000000000001111100");
	strcpy_s(Maze[6], "01000000001111000000");
	strcpy_s(Maze[7], "01100000001000000000");
	strcpy_s(Maze[8], "00100000001111111000");
	strcpy_s(Maze[9], "00000000000000001000");
	strcpy_s(Maze[10], "00000000111111111000");
	strcpy_s(Maze[11], "00111100100000010000");
	strcpy_s(Maze[12], "00100111100000010000");
	strcpy_s(Maze[13], "00100000000000010000");
	strcpy_s(Maze[14], "00111111100000000000");
	strcpy_s(Maze[15], "00100000100000000000");
	strcpy_s(Maze[16], "00100000100000111100");
	strcpy_s(Maze[17], "00000000111111100100");
	strcpy_s(Maze[18], "00000000100000000100");
	strcpy_s(Maze[19], "00000000111000000113");
}

void Output(char Maze[2][21], PPOINT pPlayerPos) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {

			if (Maze[i][j] == '4') {
				cout << "B ";
			}
			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "P ";

			else if (Maze[i][j] == '0') {
				cout << "��";
			}
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "* ";
			else if (Maze[i][j] == '3')
				cout << "��";
			
		}
		cout << endl;
	}

}
void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {

	if (pPlayerPos->y - 1 >= 0) { // ���� �÷��̾� ��ġ�� �� ������ �ƴ� ��� 
		
		
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' && 
			Maze[pPlayerPos->y -1][pPlayerPos->x] != '4') {
			//���� ĭ�� ���� �ƴҰ��  && �� ĭ�� ��ź�� �ƴ� ���
			--pPlayerPos->y;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos) {

	if (pPlayerPos->y + 1 < 20) {


		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4') {
			++pPlayerPos->y;
		}
	}
}


void MoveRight(char Maze[21][21], PPOINT pPlayerPos) {

	if (pPlayerPos->x + 1 < 20) {


		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4') {
			++pPlayerPos->x;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos) {

	if (pPlayerPos->x - 1 > 0) {


		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4') {
			--pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cinput) {
	
	switch (cinput) {
		case'w':
		case'W': {
			MoveUp(Maze, pPlayerPos);
			break;
		}
		case's':
		case'S': {
			MoveDown(Maze, pPlayerPos);
			break;
		}
		case'a':
		case'A': {
			MoveLeft(Maze, pPlayerPos);
			break;
		}
		case'd':
		case'D': {
			MoveRight(Maze, pPlayerPos);
			break;
		}

		
	}
}

//������ ������ const�� �����ϸ� ����Ű�� ��� �� ���� �Ұ�
void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount ) {

	if (*pBombCount == 5) {
		return; //��ź ��ġ �ִ� ���� 5 ä������ �׳� end
	}

	for (int i = 0; i < *pBombCount; i++) { 
		//�ݺ����� ���鼭 ���� �÷��̾� ��ġ��
		//�̹� ��ź�� �÷��� �ִٸ� �׳� �������� �Լ� ����(�ߺ� ��ġ ��ġ X)
		if (pPlayer->x == pBombArr[i].x &&
			pPlayer->y == pBombArr[i].y)
			return;
	}
	pBombArr[*pBombCount] = *pPlayer;

	++(*pBombCount);
	Maze[pPlayer->y][pPlayer->x] = '4'; //���� �÷��̾� ��ġ�� ��ź ��ġ
}

void Fire(char Maze[21][21],PPOINT pPlayer, PPOINT pBombArr, int *pBombCount) {
	for (int i = 0; i < *pBombCount; i++) {


		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y) {
			pPlayer->x = 0;
			pPlayer->y = 0;
		}//��ź�� �¾��� ��� ���� ��ġ�� �÷��̾� ����

		if (pBombArr[i].y - 1 >= 0) {//�� ��ĭ���� Ȯ��
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0') //�� ��ĭ �ƴ� ��� ��ĭ�� ���� ���
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
			
			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//��ź�� �¾��� ��� ���� ��ġ�� �÷��̾� ����

		}

		if (pBombArr[i].y + 1 < 20) {//�� �Ʒ�ĭ���� Ȯ��
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0') //�� �Ʒ�ĭ �ƴ� ��� �Ʒ�ĭ�� ���� ���
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//��ź�� �¾��� ��� ���� ��ġ�� �÷��̾� ����
		}

		if (pBombArr[i].x + 1 < 20) {//�� ������ĭ���� Ȯ��
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0') 
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';

			if (pPlayer->x == pBombArr[i].x +1 && pPlayer->y == pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//��ź�� �¾��� ��� ���� ��ġ�� �÷��̾� ����
		}

		if (pBombArr[i].x - 1 >= 0) {//�� ����ĭ���� Ȯ��
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';

			if (pPlayer->x == pBombArr[i].x - 1 && pPlayer->y == pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//��ź�� �¾��� ��� ���� ��ġ�� �÷��̾� ����
		}

		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

	}

	*pBombCount = 0; //��ź�� �����ϱ� ��ġ�� ��ź ī��Ʈ�� 0���� �ʱ�ȭ
}

int main()
{
	
	//�̷� ã�� ���� 

	//20 x 20 �̷� ������ش�.

	char  strMaze[21][21] = {};


	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 0;
	POINT tBombPos[5];

	//�̷� ����
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true) {
		system("cls");
		//�̷� ���
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) { //�������� pPlayerPos�� �����ߴ��� Ȯ��
			cout << "�̷� Ż��!!" << endl;
			system("pause");
			break;
		}

		cout << "t: ��ź ��ġ  u: ��ź ��Ʈ����" << endl; //t�� ������ ��ź ��ġ
		//u�� ������ �����¿� �� ĭ�� ����

		cout << "w: ��   s : �Ʒ�   a : ��   d : ��   q : ����";

		char cinput = _getch(); // ���ڸ� �Է��ϸ� enter Ű �Է� �ʿ� ���� �ٷ� �����ϵ��� (conio.h ��� �ʿ�)

		if (cinput == 'q' || cinput == 'Q')
			break;

		else if (cinput == 't' || cinput == 'T') {
			
			CreateBomb(strMaze, &tPlayerPos,tBombPos, &iBombCount);
		}

		else if (cinput == 'u' || cinput == 'U') {
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}
		
		else
			MovePlayer(strMaze, &tPlayerPos, cinput);

	}

	return 0;
}