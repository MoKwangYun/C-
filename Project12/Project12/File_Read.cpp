#include<iostream>

using namespace std;

int main() {

	FILE* pFile = NULL;

	fopen_s(&pFile, "hot.txt", "rt"); //텍스트 파일 읽기 모드 = rb

	if (pFile) {

		char strText[5] = {};

		//1번째 인자 --> 파일 읽어온 데이터를 저장할 포인터
		//2번째 인자 -->  읽어올 데이터 타입의 메모리 크기
		//3	번째 인자 --> 읽어올 테이터의 메모리 크기
		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);

		cout << "파일 읽기 완료" << endl;
	}

	return 0;
}