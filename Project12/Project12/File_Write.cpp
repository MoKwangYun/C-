#include<iostream>

using namespace std;

//pp는 main 함수 안에 있는 int * 타입의 p 변수의 주소를 갖게 된다.
void Test(int** pp) {
	*pp = new int;
}
int main() {

	int* p = NULL;
	Test(&p); // == (p = new int;) 

	FILE* pFile = NULL;

	//fopen_s의 첫번째 인자는 파일의 이중포인터이다.
	//두번째 인자는 파일 이름 & 저장 경로 / 만약  실행파일(exe)로 실행했을경우에는 해당 exe파일이 있는 경로를 기준으로 생성
	//세번째 인자는 모드 선택 --> 읽기 / 쓰기 / 접근  &  파일 형태(텍스트파일, 바이버리파일 2가지 모드)
	//r: 읽기 w: 쓰기 a :접근             t: 텍스트파일 b 바이너리파일
	// r, w, a 중 하나 & t, b 중 하나 선택하여 모드 결정
	fopen_s(&pFile, "hot.txt", "wt");

	if (pFile != NULL) {//파일 생성 성공
		
		//fwrite / fread 2개의 함수 기본적으로 제공
		//fputs / pgets
		//파일에 쓸 때 / 파일에서 읽어올 때

		char pText[5] = "abcd";

		//1번인자는 저장하고자 하는 값의 메모리 주소를 넣어준다
		//2번인자는 저장하고자 하는 값의 변수 타입의 메모리 크기 넣어준다 (char 타입 = 1 바이트)
		//3번인자는 저장하고자 하는 값의 개수를 넣어준다
		//4번인자는 저장할 파일의 스트림을 넣어준다
		fwrite(pText, 1, 4, pFile);
		fclose(pFile);

		cout << "파일 만들기성공" << endl; //해당 파일의 디버그 파일 안에 exe 파일(ex. Project12.exe)를 더블클릭해도 hot.txt가 생성됨
	
	}

	return 0;
	
}