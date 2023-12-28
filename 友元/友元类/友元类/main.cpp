#include <iostream>
#include <string>

#include <graphics.h>

using namespace std;

/*————单为友元————*/

class A {

	friend class B;		//友元类的创建 B是A的友元类

public:
	void print() {
		cout << "public" << endl;
	}
protected:
	void print2() {
		cout << "protected" << endl;
	}
private:
	void print3() {
		cout << "private" << endl;
	}

	static void prints() {
		cout << "static" << endl;
	}

};

class B {

public:

	void printB() {

		//在B类创建的所有A成员都有无视权限功能
		A object;
		object.print();
		object.print2();
		object.print3();
		//访问方式不变，只是权限无视
		//谁的对象只能访问谁的方法
		A::prints();	//静态仍是可以直接访问
	}
	
protected:

};

/*————互为友元————*/

class C {

public:
	friend class D;

protected:

};

class D {

public:
	friend class C;

protected:


};


/*————引用————*/
void print1(int&& a) {	//只能传常量

}

void print2(int& a) {	//只能传变量

}

void print3(const int& a) {	//可以传常量和变量,只是传过来的参数不能进行更改


}



int main() {

	B object;

	object.printB();

	//object.print();	当然在类外创建的对象还是只能访问自身

	/*————右值引用————*/

	int&& a = 1;			//正常右值引用
	const int& b = a;		//带const的左值引用

	const int num = 9;		//具有常属性的变量
	//int&& num1 = num;		这样是不行的因为num本质还是变量，只是加上了常属性不能更改数值而已

	int movenum = 10;

	int&& data = move(movenum);		//move函数把左值变成右值

	print1(456);		//只能传常数
	print2(movenum);	//只能传变量

	print3(movenum);	//both of
	print3(456);



	return 0;
}