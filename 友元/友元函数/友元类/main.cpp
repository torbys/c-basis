#include <iostream>
#include <string>

using namespace std;

class ui {

public:

	//普通函数
	void print() {
		cout << name << "\t" << id << endl;
	}
	
	//友元函数加上friend的声明即可
	friend void visited();

	friend void test(ui& object);

	friend void pattern() {

		ui object;
		object.name;

	}

protected:
	string name = "wow";
	int id = 8;

};


//友元函数不属于类，所以在类外实现使不需要类的关键字，或friend关键字
void visited() {

	//作用：提供一个场所给予对象具有打破权限的功能

	ui object;	//在友元函数中创造的对象可以打破权限访问

	cout << object.name << "\t" << object.id << endl;

}

void test(ui& object) {

	cout << object.name << "\t" << object.id << endl;

}



/*下面是不常见的写法，在A类中定义B的友元函数*/

class B {

public:
	void printB();

protected:
	string name = "po";
	int id = 10;
};

class A {

public:

	friend void B::printB();

protected:

	string name = "op";
	int count = 1;

};

void B::printB() {

	A object;
	B object1;

	cout << object.name << "\t" << object.count << endl;
	cout << object1.name << "\t" << object1.id << endl;

}

struct op {

	int n;
	int a;

};


void get(op* object) {

	cin >> object->a >> object->n;
	while (object->a <= 10 || object->n < 1 || object->n>9) {
		cout << "ui";
		cin >> object->a >> object->n;
	}
}

int main() {

	/*ui object1;

	visited();
	
	test(object1);
	B b;

	b.printB();*/
	op x;

	get(&x);


	return 0;
}
