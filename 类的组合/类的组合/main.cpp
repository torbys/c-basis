#include <iostream>
#include <string>

using namespace std;

class m {

public:
	m() { cout << "m" << endl; }
	m(string name, int id) :name(name), id(id) {}		//
protected:
	string name;
	int id;
};

class f {

public:
	f() { cout << "f" << endl; }
	f(string name,int id):name(name),id(id){}
protected:
	string name;
	int id;
};

class family {
	//这个是组合类的构造函数

public:

	family(){}	//要像这样无参构造只能在子类里也加一个无参构造函数；
	family(int a):father("嘻嘻",1),mother("哈哈",2) {}

protected:
	m mother;
	f father;
};

int main() {

	family why;


	return 0;
}