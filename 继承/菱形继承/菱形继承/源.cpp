#include <iostream>
#include <string>

using namespace std;

/*B->A
  C->A
  D->B,C
  形成棱形
*/
class A {


public:
	A(int a):a(a) {
		cout << "make A" << endl;
	}

protected:
	int a;

};

class B :virtual public A	//这种对接关系要用virtual 用这个继承下来的a只会有一份，且只能由a来进行初始化
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