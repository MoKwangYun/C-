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

	//Miro_List.txt 파일을 읽어와서 미로 목록을 만든다
	FILE* pFile = NULL;

	fopen_s(&pFile, "Miro_List.txt", "rt");

	char** pMazeList = NULL;

	if (pFile) {

		char cCount;

		fread(&cCount, 1, 1, pFile); //Miro_List.txt 의 처음 문자인 4을 cCount에 저장 (int 4가 아닌 char 4!!)

		int iMazeCount = atoi(&cCount); //char 타입 4인cCount 를 int타입 4로 변경하여 iMazeCount에 저장

		fread(&cCount, 1, 1, pFile); 
		//4 다음에 '\n'을 읽어준다. 그렇지 않으면 밑에 while 문에서 맨 처음에 '\n'을 읽어 break 되고 for 문의 i++로 넘어감

		//char* 배열을 미로 개수만큼 할당
		pMazeList = new char* [iMazeCount];

		for (int i = 0; i < iMazeCount; i++) {
			int iNameCount = 0;

			//현재 미로의 파일 이름을 저장할 배열을 256개 할당 --> pMazeList 이차원 배열로 사용
			pMazeList[i] = new char[256];

			while (true) {
				fread(&cCount, 1, 1, pFile);//문자 하나씩 읽어온다

				if (cCount != '\n') {
					pMazeList[i][iNameCount] = cCount;
					++iNameCount;
				}
				else {
					break;
				}

			}
			//파일 이름을 모두 읽었다면 문자열 마지막에 0을 넣어 문자열의 끝을 알려준다
			pMazeList[i][iNameCount] = 0;

			cout << pMazeList[i] << endl;
		}

		system("pause");
		fclose(pFile);

		//읽을 파일 목록을 만들었으므로 각 파일 중 하나를 선택해서 미로를 읽어온다.
		for (int i = 0; i < iMazeCount; i++) {
			cout << i + 1 << ". " << pMazeList[i] << endl;
		}

		cout << "미로를 선택하세요: ";
		int iSelect;
		cin >> iSelect;

		//선택한 미로 파일을 읽는다
		fopen_s(&pFile, pMazeList[iSelect - 1], "rt");

		if (pFile) {

			//미로의 세로 줄 수만큼 반복하면 각 줄 별로 읽어올 수 있다.
			for (int i = 0; i < 20; i++) {
				fread(Maze[i], 1, 20, pFile); //함수 인자로 Maze[21][21]을 받아옴 3번째 인자는 몇개의 문자 읽을 것인지를  의미
				//Maze[i] 행에 20개의 문자 읽음(가로 한 줄 읽음)

				//현재 줄의 미로를 검사하여 시작점, 혹은 도착점이 있는지 검사
				for (int j = 0; j < 20; j++) {
					if (Maze[i][j] == '2') { //시작점일 경우 2 == 시작점을 의미
						pStartPos->x = j;
						pStartPos->y = i;

						*pPlayerPos = *pStartPos; //플레이어 시작위치 설정

					}
					else if (Maze[i][j] == '3') {//도착점일 경우
						pEndPos->x = j;
						pEndPos->y = i;
					}
				}
				
				//개행문자 '\n'를 읽어온다.
				fread(&cCount, 1, 1, pFile);
			}
			
			fclose(pFile);
		}
	}
	


	//pStartPos->x = 0;
	//pStartPos->y = 0;

	//pEndPos->x = 19;
	//pEndPos->y = 19;


	//strcpy_s(Maze[0], "21100000000000000000"); //문자열 마지막에는 NULL문자가 있어야 하기 때문에
	//strcpy_s(Maze[1], "00111111111100000000"); // 문자열 크기 == 배열 크기 -1
	//strcpy_s(Maze[2], "00100010000111111100");
	//strcpy_s(Maze[3], "01100010000000000100");
	//strcpy_s(Maze[4], "01000011110000000100");
	//strcpy_s(Maze[5], "01000000000001111100");
	//strcpy_s(Maze[6], "01000000001111000000");
	//strcpy_s(Maze[7], "01100000001000000000");
	//strcpy_s(Maze[8], "00100000001111111000");
	//strcpy_s(Maze[9], "00000000000000001000");
	//strcpy_s(Maze[10], "00000000111111111000");
	//strcpy_s(Maze[11], "00111100100000010000");
	//strcpy_s(Maze[12], "00100111100000010000");
	//strcpy_s(Maze[13], "00100000000000010000");
	//strcpy_s(Maze[14], "00111111100000000000");
	//strcpy_s(Maze[15], "00100000100000000000");
	//strcpy_s(Maze[16], "00100000100000111100");
	//strcpy_s(Maze[17], "00000000111111100100");
	//strcpy_s(Maze[18], "00000000100000000100");
	//strcpy_s(Maze[19], "00000000111000000113");
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
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4') {
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
void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount) {

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

void Fire(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount) {
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

			if (pPlayer->x == pBombArr[i].x + 1 && pPlayer->y == pBombArr[i].y) {
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

			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else if (cinput == 'u' || cinput == 'U') {
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else
			MovePlayer(strMaze, &tPlayerPos, cinput);

	}

	return 0;
}