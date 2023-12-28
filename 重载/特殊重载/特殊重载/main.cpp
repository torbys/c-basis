#include <iostream>

using namespace std;

class A {

public:

	A(string name=" ",int money=1000):name(name),money(money){}
	void print() {
		cout << name << "\t" << money << endl;
	}

	//++,--这些都是特殊重装载
	A operator++()
	{
		this->money++;
		return *this;
	}

	A operator++(int) //增加一个无用参数充当标记，标识为后缀
	{
		return A(this->name, this->money++);
	}

	operator int() {	//相当于重载了一个等号，只取类中的一个数据进行赋值
		return this->money;
	}

	operator string() {
		return this->name;
	}

protected:

	string name;
	int money;

};

//文本重载：重载后缀
//参数一定为unsigned long long
//一般加下划线和库进行区分 这种重载并不是限定对类的，所以不用在类中友元。

unsigned long long operator ""_h(unsigned long long num) {
	return num * 60 * 60;		//转换成秒数;
}

void print1(int num) {
	cout << num << endl;
}


/*———————————————重载括号—————————————————*/

class B {

public:
	void operator()() {
		cout << "here" << endl;
	}

protected:

	int id;

};



int main() {

	A object("me", 100);
	
	object++.print();
	(++object).print();

	/*——————————————————*/

	long num = 1L;
	unsigned int num2 = 1u;

	print1(1_h);
	print1(4_h);

	int text = object;//能有这样的原因是因为类的隐式转换

	string ui = object;

	cout << ":" << text << "\t" << ui << endl;

	B object1;
	object1.operator()();
	object1();
	B()();


	return 0;
}