#include<iostream>

using namespace std;

/*
���۷�����(Operator) : Ŭ������ ����ü���� ���ϴ� ������ �� �� �ֵ��� �����ڸ� �������ϴ� ���
*/

typedef  struct _tagPoint {

	int x;
	int y;

	_tagPoint(): //����ü ������  , ����ü Ÿ�� ���� ������ x = 0, y = 0 ����
		x(0),
		y(0) 
	{

	}

	_tagPoint(int _x, int _y) : //����ü Ÿ�� ���� ������ int Ÿ�� ���� �ΰ��� ������ ��� ȣ��Ǵ� ������
		x(_x),
		y(_y)
	{

	}

	_tagPoint(const _tagPoint& pt) {
		*this = pt;
		// ���� ����
		// -->this�� �ڱ��ڽ��� �������̰� *�� �ٿ��� �ڱ��ڽ��� �������Ͽ� ��� �����͸� �����ϰ� �Ѵ�.
	}

	_tagPoint operator + (const _tagPoint & pt) { //_tagPoint����ü �ȿ��� + �����ڸ� opertor�� �����ϳ���  �޾� �������Ѵٴ� �ǹ�
		
		_tagPoint result;
		result.x = x + pt.x; // (�⺻ x, y�� pt1�� x,y) & pt�� ���ڷ� �޴� pt2�̱� ������ pt.x = pt2.x�� �ȴ�
		result.y = y + pt.y;

		return result;
	}

	_tagPoint operator + (int a) { //�������� ���������� +�� ������ : Operator�� �����ε��� �����ϴ�!!
		_tagPoint pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	
		//_tagPoint ��ü�� ���� �����ϴ� ������ x�� y�� + �տ� ��ġ��  _tagPoint ��ü�� ����� ������
		//_tagPoint Ÿ������ ������ ����� �ϱ� ������ ���� �뵵 _tagPoint ��ü�� ������ �ִ� ���̴�.
	}

	void operator += (int a) {//��ȯ����  �ʱ� ������ void

		x += a;
		y += a;
	} //�ٷ� ���� Operator + ���� �ٸ��� ������ �� �ʿ䰡 ���� ������ ��ü ���� �ʿ� X
	// += �տ� ��ġ�� ��ü�� ����� �ٲ��ִ� ������ ��

	void operator << (const _tagPoint & pt) { // '<<'�� ������ 
		x = pt.x; 
		y = pt.y;
		// << �տ� ��ġ�� ����ü ��ü ���(x, y)�� << �ڿ� ��ġ�� ����ü ��ü ���(= ���� = pt.x,pt.y)�� ���� 
	}

	void operator ++ () {
		++x;
		++y;
	}
	
	/*void operator +- () {   // +- �����ڴ� ����ü ������ �ƴϴ��� �������� �ʱ� ������ ������ �Ұ�
		++x;
		--y;
	}*/
}POINT, * PPOINT;
int main() {

	POINT pt1(10,20), pt2(30,40), pt3;

	//pt3 = pt2 + pt1 �̷��� ���� �⺻�����δ� �Ұ� But, Operator�� �����ϸ� ����!! (�Լ��� ���� ����� �Ѵ�)

	//_tagPoint ����ü �ȿ����� + �����ڰ� operator�� ������ �Ǿ��ִ�.
	//�׷��� pt3 = pt2 + pt1�� ���� ������ ���������� 
	// �����ǵ� + �տ� ��ġ�ϴ� pt1�� ������ �Լ���  ȣ�����ִ� �����̴�! --> + �ڿ� pt2�� ���ڷ� �Ѱ��ش�.
	
	pt3 = pt1 + pt2; //�����ڿ�F12�� ���� � Operator�� ���Ǿ����� Ȯ�� ����

	
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