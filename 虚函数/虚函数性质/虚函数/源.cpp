/*
	用virtual修饰的函数叫虚函数
*/
#include <iostream>

using namespace std;
class A {

public:

	virtual void print();	//所有虚函数都是由一个虚函数指针来存储的，所以再多的虚函数也不会改变

protected:

};

class B {
public:
	int a;
	double i;
	double o;
};

void A::print() {
	cout << "虚函数" << endl;
}

class C {
	/*
		纯虚函数：没有函数体的虚函数
		抽象类：至少含有一个纯虚函数
		特性：不能构造对象，但可以创造对象指针；在多态中起作用
	*/
public:
	virtual void print() = 0;
};




int main() {
	//空的结构体or类占用一个内存
	cout << "A:" << sizeof(A) << endl;
	//有数据的类or结构体占的字节是其中一个最大字节的整数倍,补齐的意思是把没有达到最大字节的数据补上字节
	cout << "B:" << sizeof(B) << endl;
	
	A object;
	auto p = &A::print;

	typedef void(A::*f)();

	/*————————————————*/

	C* p = nullptr;		//可以构造指针对象

	//C object;		错误的，不能构建对象	


	return 0;
}