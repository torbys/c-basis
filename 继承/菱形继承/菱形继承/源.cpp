#include <iostream>
#include <string>

using namespace std;

/*B->A
  C->A
  D->B,C
  �γ�����
*/
class A {


public:
	A(int a):a(a) {
		cout << "make A" << endl;
	}

protected:
	int a;

};

class B :virtual public A	//���ֶԽӹ�ϵҪ��virtual ������̳�������aֻ����һ�ݣ���ֻ����a�����г�ʼ��
{

public:
	B(int a, int b) :A(a), b(b) {
		cout << "make B" << endl;
	}

protected:
	int b;

};

class C :virtual public A
{

public:
	C(int a, int c) :A(a), c(c) {
		cout << "make C" << endl;
	}
protected:
	int c;

};

class D :public B,public C
{

public:
	D() :B(1, 2), C(3, 4), A(5),d(6) {
		cout << "make D" << endl;
	}
	void print() {
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
		cout << d << endl;
	}
protected:
	int d;

};

int main() {

	D object;
	object.print();

	return 0;
}