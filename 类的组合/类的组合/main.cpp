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
	//����������Ĺ��캯��

public:

	family(){}	//Ҫ�������޲ι���ֻ����������Ҳ��һ���޲ι��캯����
	family(int a):father("����",1),mother("����",2) {}

protected:
	m mother;
	f father;
};

int main() {

	family why;


	return 0;
}