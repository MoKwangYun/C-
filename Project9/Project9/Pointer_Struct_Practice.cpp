#include<iostream>

using namespace std;

struct POINT {
	int x;
	int y;
};

typedef POINT point;
typedef POINT* ppoint;

void add(ppoint a){
	a->x = 1;
	a->y = 2;
}

void sum(point ar[] , int n) {  //point ar[] == point * ar도 동일하게 사용 가능
	for (int i = 0; i < n; i++) {
		ar[i].x = i;
		ar[i].y = i * 10 + 1;
	}
}


int main() {
	point a = { 0, 0 };
	add(&a);
	cout << a.x << endl;
	
	point ar[] = { {0,0}, {0,0} };
	sum(ar, 2);

	cout << ar[0].x << endl << ar[0].y << endl << endl;
	cout << ar[1].x << endl << ar[1].y << endl << endl;



	return 0;
}