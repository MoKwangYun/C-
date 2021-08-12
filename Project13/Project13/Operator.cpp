#include<iostream>

using namespace std;

/*
오퍼레이터(Operator) : 클래스나 구조체에서 원하는 연산을 할 수 있도록 연산자를 재정의하는 기능
*/

typedef  struct _tagPoint {

	int x;
	int y;

	_tagPoint(): //구조체 생성자  , 구조체 타입 변수 생성시 x = 0, y = 0 실행
		x(0),
		y(0) 
	{

	}

	_tagPoint(int _x, int _y) : //구조체 타입 변수 생성시 int 타입 인자 두개를 제공할 경우 호출되는 생성자
		x(_x),
		y(_y)
	{

	}

	_tagPoint(const _tagPoint& pt) {
		*this = pt;
		// 얕은 복사
		// -->this는 자기자신의 포인터이고 *를 붙여서 자기자신을 역참조하여 모든 데이터를 복사하게 한다.
	}

	_tagPoint operator + (const _tagPoint & pt) { //_tagPoint구조체 안에서 + 연산자를 opertor로 인자하나를  받아 재정의한다는 의미
		
		_tagPoint result;
		result.x = x + pt.x; // (기본 x, y는 pt1의 x,y) & pt는 인자로 받는 pt2이기 때문에 pt.x = pt2.x가 된다
		result.y = y + pt.y;

		return result;
	}

	_tagPoint operator + (int a) { //위에서와 마찬가지로 +를 재정의 : Operator도 오버로딩이 가능하다!!
		_tagPoint pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	
		//_tagPoint 객체를 새로 선언하는 이유는 x와 y는 + 앞에 위치한  _tagPoint 객체의 멤버가 맞지만
		//_tagPoint 타입으로 리턴을 해줘야 하기 때문에 리턴 용도 _tagPoint 객체를 생성해 주는 것이다.
	}

	void operator += (int a) {//반환하지  않기 때문에 void

		x += a;
		y += a;
	} //바로 위의 Operator + 과는 다르게 리턴을 할 필요가 없기 때문에 객체 선언 필요 X
	// += 앞에 위치한 객체의 멤버를 바꿔주는 것으로 끝

	void operator << (const _tagPoint & pt) { // '<<'를 재정의 
		x = pt.x; 
		y = pt.y;
		// << 앞에 위치한 구조체 객체 멤버(x, y)에 << 뒤에 위치한 구조체 객체 멤버(= 인자 = pt.x,pt.y)를 대입 
	}

	void operator ++ () {
		++x;
		++y;
	}
	
	/*void operator +- () {   // +- 연산자는 구조체 연산이 아니더라도 존재하지 않기 때문에 재정의 불가
		++x;
		--y;
	}*/
}POINT, * PPOINT;
int main() {

	POINT pt1(10,20), pt2(30,40), pt3;

	//pt3 = pt2 + pt1 이러한 연산 기본적으로는 불가 But, Operator로 정의하면 가능!! (함수와 같은 기능을 한다)

	//_tagPoint 구조체 안에서는 + 연산자가 operator로 재정의 되어있다.
	//그래서 pt3 = pt2 + pt1과 같은 연산이 가능해지며 
	// 재정의된 + 앞에 위치하는 pt1의 연산자 함수를  호출해주는 개념이다! --> + 뒤에 pt2는 인자로 넘겨준다.
	
	pt3 = pt1 + pt2; //연산자에F12를 눌러 어떤 Operator이 사용되었는지 확인 가능

	
	cout << "x: " << pt3.x << "\ty: " << pt3.y << endl;

	pt3 << pt1;

	cout << "x: " << pt3.x << "\ty: " << pt3.y << endl;

	pt3 = pt1 + 1000;

	cout << "x: " << pt3.x << "\ty: " << pt3.y << endl;

	pt3 += 9;

	cout << "x: " << pt3.x << "\ty: " << pt3.y << endl;

	++pt3;

	cout << "x: " << pt3.x << "\ty: " << pt3.y << endl;

	return 0;
}