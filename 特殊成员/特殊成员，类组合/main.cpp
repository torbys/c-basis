#include <iostream>
#include <string>

using namespace std;

class p {

public:

	//普通函数没有参数列表，只有构造函数才有
	p(string name, int id):id(id)
	{
		this->name = name;
	}

	void test() {
		cout << "normal here" << endl;
	}

	void test()const		//这是常成员函数
	{
		cout << "const here" << endl;
		cout << this->name <<"  " << this->id << endl;
		//可以对数据进行访问，但不可进行修改

	}

	void printdata() const 
	{
		cout << this->name << this->id << endl;
	}



protected:
	const int id;
	string name;
};

const p& returnp() {
	return p("拷贝", 456);
}

/*————————————————————————————以下是静态*/

class ui {

public:
	static void print() {

		//这是静态函数
		//它不能访问非静态成员，可以直接访问静态数据成员，且它没有this指针
		cout << count << endl;
	}

	ui(string name) {
		this->name = name;
	}

protected:
	string name;
	static int count;	//静态成员，它不能在类内初始化

	//静态数据成员属于类，不属于对象，每个对象都是用的同一个静态成员

};

int ui::count = 0;	//只能在外初始化，需要限定

void print()
{

	static ui op("hh");
}


int main() {

	/*//普通对象
	p object1("normal",123);
	object1.test();	//普通对象优先调用普通函数


	//常对象
	const p object2("const", 1001);		//用const修饰的对象
	object2.test();	//常对象只能调用常成员函数

	returnp().printdata();*/
/*—————————————————————————————————————————— 以下是静态*/






	return 0;
}