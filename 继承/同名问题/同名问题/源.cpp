#include <iostream>

using namespace std;

class A {

public:
	//形参名和数据成员名相同
	//1.初始化参数列表
	//2.this指针
	A(int a):a(a){}
	int a;
	void print(){
		cout << "A" << endl;
	}
};

class B :public A
{
public:
	int a;
	//如果B中还有一个与A类中相同的名
	//原则：就近原则
	B(int a, int b) :A(a)
	{
		this->a = b;	//这里的a都是B的，在B里面优先使用B的a。
	}

	void print() {
		//要用类名限定就可以访问父类的
		cout << "B" << endl;
		cout << a << endl;
		cout << A::a << endl;

		//如果A类中还有同名函数
		A::print(); //还是需要限定
	}


};


int main() {

	A object(4);
	B object1(2, 3);

	object.print();
	object1.print();		//是谁的象调用谁的

	object1.A::print();		//子类若要调用父类的同命则需要限定

	/*————————*/

	A* pa = new A(5);
	B* pb = new B(8,9);
	//这是正常指针赋值，同时也就是正常的访问

	/*从子—>父 上行转换*/
	A* pA = new B(5, 6);	//这是不正常赋值，父用子类初始化
	pA->print();			//没有virtual时指针是哪个类的就调用哪个
	pA = &object1;			//这种也是会调用父类的

	/*从父->子  下行转换  一般不被允许*/
	//B* pB = new A(12);	error  当然把一个对象强行转换成B类也可


	return 0;
}