#include<iostream>
#include<conio.h>
using namespace std;

/*
	0: 벽
	1: 길
	2: 시작점
	3: 도착점
	4: 폭탄
	5: 폭탄 이펙트
*/


struct _tagPoint {
	int x;
	int y;
};

// typedef : 타입을 재정의하는 기능
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;
	
	strcpy_s(Maze[0], "21100000000000000000"); //문자열 마지막에는 NULL문자가 있어야 하기 때문에
	strcpy_s(Maze[1], "00111111111100000000"); // 문자열 크기 == 배열 크기 -1
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
				cout << "ㅁ";
			}
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "* ";
			else if (Maze[i][j] == '3')
				cout << "ㅇ";
			
		}
		cout << endl;
	}

}
void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {

	if (pPlayerPos->y - 1 >= 0) { // 현재 플레이어 위치가 맨 윗줄이 아닐 경우 
		
		
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' && 
			Maze[pPlayerPos->y -1][pPlayerPos->x] != '4') {
			//위에 칸이 벽이 아닐경우  && 위 칸이 폭탄이 아닐 경우
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

//포인터 변수를 const로 생성하면 가리키는 대상 값 변경 불가
void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount ) {

	if (*pBombCount == 5) {
		return; //폭탄 설치 최대 개수 5 채웠으면 그냥 end
	}

	for (int i = 0; i < *pBombCount; i++) { 
		//반복문을 돌면서 현재 플레이어 위치에
		//이미 폭탄이 올려져 있다면 그냥 리턴으로 함수 종료(중복 위치 설치 X)
		if (pPlayer->x == pBombArr[i].x &&
			pPlayer->y == pBombArr[i].y)
			return;
	}
	pBombArr[*pBombCount] = *pPlayer;

	++(*pBombCount);
	Maze[pPlayer->y][pPlayer->x] = '4'; //현재 플레이어 위치에 폭탄 설치
}

void Fire(char Maze[21][21],PPOINT pPlayer, PPOINT pBombArr, int *pBombCount) {
	for (int i = 0; i < *pBombCount; i++) {


		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y) {
			pPlayer->x = 0;
			pPlayer->y = 0;
		}//폭탄에 맞았을 경우 시작 위치로 플레이어 보냄

		if (pBombArr[i].y - 1 >= 0) {//맨 위칸인지 확인
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0') //맨 위칸 아닐 경우 위칸이 벽일 경우
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
			
			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//폭탄에 맞았을 경우 시작 위치로 플레이어 보냄

		}

		if (pBombArr[i].y + 1 < 20) {//맨 아래칸인지 확인
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0') //맨 아래칸 아닐 경우 아래칸이 벽일 경우
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//폭탄에 맞았을 경우 시작 위치로 플레이어 보냄
		}

		if (pBombArr[i].x + 1 < 20) {//맨 오른쪽칸인지 확인
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0') 
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';

			if (pPlayer->x == pBombArr[i].x +1 && pPlayer->y == pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//폭탄에 맞았을 경우 시작 위치로 플레이어 보냄
		}

		if (pBombArr[i].x - 1 >= 0) {//맨 왼쪽칸인지 확인
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';

			if (pPlayer->x == pBombArr[i].x - 1 && pPlayer->y == pBombArr[i].y) {
				pPlayer->x = 0;
				pPlayer->y = 0;
			}//폭탄에 맞았을 경우 시작 위치로 플레이어 보냄
		}

		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

	}

	*pBombCount = 0; //폭탄이 터지니까 설치된 폭탄 카운트는 0으로 초기화
}

int main()
{
	
	//미로 찾기 게임 

	//20 x 20 미로 만들어준다.

	char  strMaze[21][21] = {};


	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 0;
	POINT tBombPos[5];

	//미로 설정
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true) {
		system("cls");
		//미로 출력
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) { //도착지에 pPlayerPos가 도착했는지 확인
			cout << "미로 탈출!!" << endl;
			system("pause");
			break;
		}

		cout << "t: 폭탄 설치  u: 폭탄 터트리기" << endl; //t를 누르면 폭탄 설치
		//u를 누르면 상하좌우 한 칸씩 폭발

		cout << "w: 위   s : 아래   a : 좌   d : 우   q : 종료";

		char cinput = _getch(); // 문자를 입력하면 enter 키 입력 필요 없이 바로 실행하도록 (conio.h 헤더 필요)

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