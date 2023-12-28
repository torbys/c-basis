#include <iostream>
#include <string>

using namespace std;

class object {

public:

	//object() {}//为了构造对象方便，我们一般会放一个默认的构造函数，或者缺省的构造方式

	object() = default;		//使用默认的无参构造函数;

	/*object(int age = 45, int money = 46)	//缺省的构造函数可以构造不带参数的对象，也可以传参 
	{
		this->age = age;
		this->money = money;
	}*/

	//如果没有写构造函数，在类中默认存在一个构造函数 object(){}
	object(int age, int money) //这就是构造函数，它无返回值
	{
		cout << "带参构造函数" << endl;
		this->age = age;
		this->money = money;

	}

	void printdata() {
		cout << age << "\t" << money << endl;
	}

protected:

	int age;
	int money;

};

class ufo {

public:

	//先放一个构造函数
	ufo(string name = "iloveyou", int age = 20) {
		cout << "构造函数" << endl;
		this->name = name;
		this->age = age;
	}

	ufo(int a) {
		this->age = a;
		cout <<"构造成：" << age << endl;
	}

	//拷贝构造函数	只有一个参数即对对象的引用 目的在于实现一个对象对另一个对象的赋值 即用一个对象创建新对象
	ufo(ufo& op) {
		cout << "拷贝构造函数" << endl;
		name = op.name;
		age = op.age;

	}

	~ufo() {		//析构函数是在一个对象消亡时候会自动调用
		cout << "析构函数：";
		cout << age << endl;
	}

protected:
	string name;

	int age;

};

ufo s1(1);
void function() {

	cout << "构造的顺序" << endl;

	ufo s2(2);		//
	ufo* s3 = new ufo(3);		//堆区内存在函数当中不会消亡 得删除才调用解析
	delete s3;
	ufo s4(4);		//2，4都是临时变量，所以在函数过后会消亡，到时会自动调用解析函数

}

void print1(ufo ot) {}

void test(ufo& oi){}

void print(object&& data) {
	 data.printdata();
}

int main() {

	int a = 0, b = 0, c = 0;
	//a = a + 7 = b + c;

	

	//function();

	/*//构造对象的过程，就是调用函数的过程
	object(45, 56);		//无名or匿名对象 
	print(object(78, 65));

	//当你自己写了构造函数之后，你的对象就得是构造函数的样子
	//object ui;	//因为构造函数有两个参数所以像这样构造一个无参对象是错的
	object oi(88, 44);
	oi.printdata();
	
	//new一个对象
	//1.创建一个匿名对象
	//2.把匿名对象的首地址赋值给指针
	
	object array[3] = {};
	*/
//————————————————————————————————--// 以下是拷贝函数

	//非拷贝函数的调用
	ufo m1 = { "hhh",36 };
	//ufo m2 = ufo{ "ooo",56 };

	ufo m3;
	m3 = m1;	

	//拷贝构造函数的使用
	cout << "以下是拷贝函数"<<endl;
	ufo t1;

	ufo t3(t1);		//构造函数的使用，用t1初始化t3，这是形式1；

	ufo t4 = m3;

	print1(t4);
	cout << "test" << endl;
	test(t4);

	/*
		1.匿名构造，一定不会拷贝构造

		2，通过一个对象创建另一个对象，一定会拷贝构造

		3.在函数中传参数，引用类的没有创建新对象，所以不会调用拷贝构造
	
	*/

	return 0;
}