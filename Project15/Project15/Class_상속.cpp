#include<iostream>

using namespace std;

/*
��� : Ŭ������ Ŭ���� ���� �θ�� �ڽ� ���踦 ������  �� �ִ�.

�ڽ� Ŭ������ �θ� Ŭ������ �����(��� ����, ��� �Լ�)�� ����� �� �ִ�.

�θ�Ŭ�������� public�̳� protected�� �Ǿ��ִ� ������� �ڽ�Ŭ�������� ��� ����������,
private���� �Ǿ��ִ� ����� �ڽĿ����� ��� �Ұ�

+ protected : �ڽ�Ŭ����  only ��� ����(�ܺ� ���Ұ�)

����� ����: public,private ���

������ : ��Ӱ��迡 �ִ� Ŭ���� ���� ���� ����ȯ�� ������ ������ ���Ѵ�

�����Լ�(= �Լ� �������̵�) : �Լ��� �������ϴ� ����̴�.
--> ����Լ� �տ� virtual Ű���带 ���̸� �ش� �Լ��°����Լ��� �ȴ�.
���� CParnet Ŭ������ virtual void Output() �Լ��� �ִٸ� �ڽ�Ŭ���������� �� �����Լ��� �������� �� �ִ�.
-->�����ǽ� �Լ��̸�& ���ڰ� ������ ���ƾ� ����

�����Լ��� ������ �ִ�Ŭ������ ���������� �����Լ� ���̺��� �����Ѵ�.
�����Լ� ���̺��� �����Լ����� �޸� �ּҸ� �����ϴ� ���̺��̴�.

���� CParent�� Output�� �����Լ��̰� CChild Ŭ������ Output�� �������Ѵٸ�
�� ���� CChild ��ü�� �����ϸ� �����Լ� ���̺��� CChild Ŭ������ Output �ּҰ� �ö󰡰Եȴ�.
or CParent ��ü�� �����Ѵٸ� CParent�� Output �ּҰ� �ö󰣴�.

--> Output �Լ�, �� �����Լ��� ȣ���ϰ� �Ǹ� ���� �����Լ� ���̺��� �����ؼ� �޸��ּҸ� Ȯ���Ѵ�.

ex.  CChild ��ü�� Output ȣ��� �����Լ� ���̺� �ش� Child ��ü��  ���� Output �Լ� �ּ� Ȯ��
�����Լ� ���̺� CChild�� Output�ּҰ� �� �ִٸ� �� �ּ��� �Լ��� ȣ�����ִ�  �����̴�.

*******!!�Ҹ��ڵ� �����Լ��� ���� �� �ִ�. �θ��� �Ҹ��ڴ� �����Լ��� �����!!******


���������Լ� : �Լ� �ڿ� = 0 �� �ٿ��ָ� �ش� �����Լ��� ���������Լ��� �ȴ�.
���������Լ��� ���� �κ��� �������� �ʴ´�!!
-->���������Լ��� ������ �ִ� Ŭ���� =  �߻�Ŭ����
-->�߻�Ŭ������ ��ü(�ν��Ͻ�) ������ �Ұ����ϴ�.
-->���������Լ��� �ش� Ŭ������ ��ӹ޴� ��� �ڽ�Ŭ�������� �ݵ�� �������ؾ� �Ѵ�!!(�ڽ�Ŭ�������� �������Ͽ� ����� �������� ����!!) 
-->�ڽ�Ŭ�������� � �Լ��� ������������ �˷��ִ� �������̽� ����!!

*/

class CParent {
public:
	CParent() {
		cout << "CParent ������" << endl;
	}
	virtual ~CParent() {
		cout << "CParent �Ҹ���" << endl;
	}

public:
	int m_iA;

	virtual void Output() {
		cout << "Parent Output Virtual Function" << endl;
	}

	virtual void OutputPure() = 0;
protected:
	int m_iB;

private:
	int m_iC;

};

class CChild : public CParent { //public���� CChild Ŭ������ ���
public: 
	CChild() {
		m_iB = 300; //m_iB�� protected �̱� ������ main������ ������ �Ұ����ϰ� �ڽ�Ŭ���������� ���� ����

		//m_iC = 500;  m_iC�� private �̱� ������ �ڽ�Ŭ���������� ���� �Ұ���
		cout << "CChild ������" << endl;
	}
	virtual ~CChild() {
		cout << "CChild �Ҹ���" << endl;
	}

	

protected:
	int m_iD;

public:
	void ChildOutput() {
		
		cout << "ChildOutput Function" << endl;
	}

	virtual void Output() {

		CParent::Output(); //�θ�Ŭ������ ����Լ� ȣ��
		cout << "Child Output Virtual Function"<<endl << endl;

	}
	
	virtual void OutputPure() {
		cout << "Child Pure Function" << endl;
	}
};

class CChild1 : private CParent { // private���� CChild1 Ŭ������ ���
public:
	CChild1() {

		m_iA = 222; //private���� ����� �޾����� CChild1Ŭ���� ���ο����� �θ�Ŭ���� ��� ���� ���� , but �ܺο����� ���� �Ұ�
		cout << "CChild1 ������" << endl;
	}

	~CChild1() {
		cout << "CChild1 �Ҹ���" << endl;
	}
	virtual void OutputPure() {
		cout << "Child1 Pure Function" << endl;
	}
private:
	int m_iD;
};

class CChildChild : public CChild { // CParent Ŭ������ �ڽ� Ŭ������ CChild Ŭ������ public���� ��� �޴� CChildChild Ŭ����

public:
	CChildChild() {

		m_iD = 500;
		cout << "CChildChild ������" << endl;
	}
	~CChildChild() {
		cout << "CChildChild �Ҹ���" << endl;
	}
	
	virtual void OutputPure() {
		cout << "ChildChild Pure Function" << endl;
	}

private:
	int m_iE;

};
int main() {

	/*
	��Ӱ��迡���� ������ ȣ�� ���� : �θ� -> �ڽ� �� ȣ��
	��Ӱ��迡���� �Ҹ��� ȣ�� ���� : �ڽ� -> �θ� �� ȣ��


	*/
	// CParent parent; //CParnet() ������ ȣ��  --> ���������Լ��� ���� �ִ� �߻�Ŭ�����̱� ������ ��ü ���� �Ұ�
	CChild child;	 // CParent() ������ ȣ�� -> CChild() ������ ȣ��
	CChild1 child1;	//CParent() ������ ȣ�� -> CChild1() ������ ȣ�� 
	CChildChild childchild;	//CParent() ������ ȣ��-> CChild() ������ ȣ�� -> CChildChild() ������ ȣ��


	child.m_iA = 200; //�θ�Ŭ������ ����� m_iA ���� ����

	//child1.Output(); & child1.m_iA = 222;  --> error 
	// CChild1 Ŭ������ private���� CParent Ŭ������ ��ӹޱ� ������ �θ�Ŭ���� ��� ���� �Ұ�
	// but, private���� ��ӹ޾Ҵ� �ϴ��� Ŭ���� �ȿ����� ���� ����




	cout << endl << endl << "====================��ĳ����, �ٿ�ĳ���� ========================" << endl << endl;

	/*CChild Ŭ������ CParent Ŭ������ ��ӹް� �ִ�.
	new CChild�� �ϰԵǸ� CChild ��ü �ϳ����������ְ� �� �޸� �ּҸ� ��ȯ�Ѵ�.
	�׷��� �Ʒ������� CParent* Ÿ�� ������ ��ȯ�� �ּҸ� �������ְ� �ִ�.
	�θ������� Ÿ�Կ� CChild ��ü�� �޸� �ּҸ� ���� �� �ִ� ������ ��Ӱ��迡 �ֱ� �����̴�.
	�ڽ� �޸� �ּҸ� �θ�������  Ÿ������ ����ȯ �� ���̴�. --> ��ĳ����

	�ڽ� -> �θ� ����ȯ : ��ĳ����
	�θ� -> �ڽ� ����ȯ :  �ٿ�ĳ����
	*/

	CParent* pParent = new CChild;

	/*�Ʒ� �� Ŭ������ ��� CParent Ŭ������ ��ӹް� �ִ�.
	�׷��Ƿ� pParent�� �� Ÿ�� ��� �ٿ�ĳ���� �����ϴ�.
	�׷��� pParent�� CChild�� �Ҵ��� ��ü�̴�.
	�� ��ü(pParent)�� CChild1 Ÿ������ �ٿ�ĳ�����Ͽ� �־��ְ� �Ǹ� pParent�� ����� �� ������ �߻��� �� �ִ�.
	�ֳ��ϸ� ���ʿ� ������ ��ü�� �ƴ� �ٸ� Ÿ������ ��ȯ�Ǿ��� �����̴�.

	==> �����ߴ� Ÿ�����θ� �ٿ�ĳ���� �ؾ� �Ѵ�!!
	*/


	/* 
	pParent->ChildOutput(); 
	pParent�� CParent ������ Ÿ�� ==> �ڽ� ������� ������ �Ұ����ϱ� ������ �����Ϸ��� ����ȯ �ʿ�!!
	*/
	cout << endl << "=================����ȯ�Ͽ� �Լ� ȣ��=================" << endl;
	((CChild*)pParent)->ChildOutput();

	cout << endl << "==================Vitual �Լ� ȣ��=====================" << endl;
	pParent->Output();
	//pParent* Ÿ�������� ������ CChild Ÿ������ �Ͽ��� ������ �����Լ� ���̺��� CChild�� Output �Լ� �ּҸ� ȣ��!!
	//���� CChild Ŭ������ Output()�� ���������� ������ CParent Ŭ���� Output �Լ� �ּ� ȣ��!!

	cout << endl << "==================Vitual �Լ������� �θ� �Լ� ȣ��=====================" << endl;
	pParent->CParent::Output(); //CChild Ŭ������ Output �Լ� �ּҸ� ȣ���ؾ� ������ CParent :: �� �߰������� ��������� CParent�� Output �Լ��� ����
	
	cout << endl;


	CChild* pChild = (CChild*)pParent;
	/*CChild1* pChild1 = (CChild1*)pParent;  
	--> pParent ��ü�� CChild Ÿ������ ������ �޸� �����̰� �̸� CParnet* Ÿ������ ����ȯ �Ѱ��̴�.(��ĳ����)
	�׷��Ƿ� �ٿ�ĳ������ �� ������ ó�� ������ Ÿ���� CChild Ÿ������ �ٿ�ĳ�����ؾ� �Ѵ�.
	*/


	//CParnet* pParent1 = new CChild1;  --> CChild1 Ŭ������ private���� �θ�Ŭ������ ��� �ޱ� ������ error
	 CParent* pParent2 = new CChildChild;  //--> ����
	 pParent2->Output(); //CChildChild Ŭ���������� Output �Լ��� ���������� �ʾұ� ������ CChildChild�� �θ�Ŭ���� CChild Ŭ������ Output�ּ� ȣ��

	CParent* pParentArr[2] = {};

	pParentArr[0] = new CChild;
	pParentArr[1] = new CChildChild;
	//��� ���迡 �ִ� ��� Ŭ�������� (private ��� ����) �θ�Ŭ�������� ���� ����  --> �����ϱ⿡ ���ϰ� ������!

	for (int i = 0; i < 2; i++) {

		delete pParentArr[i]; // pParentArr[]�� CParent* Ÿ���̱� ������ �Ҹ�� CParent �Ҹ��ڸ� ȣ��ȴ�. CChild�� CChildChild �Ҹ��ڴ� ȣ�� X
		//������ �����ÿ��� CChild, CChildChild Ÿ������ ���� �����ϱ� ������ ���� Ŭ���� ������ ȣ�� O
		// cf. �θ��� �Ҹ��ڸ� �����Լ�(virtual)�� �����θ� �ش� ��ü�� ������ Ŭ������ �Ҹ��ڵ� ȣ��ȴ�!!(�ڽ� -> �θ� �� �Ҹ��� ȣ��)
	
	}

	return 0;
}