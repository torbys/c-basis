#include <iostream>
#include <string>

using namespace std;
//继承需要两个类
//无新的属性和行为叫继承；有新的属性和行为叫派生；这两个笼统来叫都叫继承

//特性：在父类中的的属性，子类都有一份，这一份属性是由继承方式决定。

class boss {

public:
	boss(){
		cout << "make father" << endl;
	}

	boss(string name,int id):name(name),id(id){
		cout << "Im father" << endl;
	}	//父类的构造函数

	int a=10;
	void print() {
		cout << "boss" << endl;
	}

protected:

	int id=16;
	string name;

private:

	int c;

};

class son : public boss		//这个就是继承形式	class 子类名 : 继承方式 父类名
{
public:
	//子类的构造函数必须调用父类的构造函数来初始父类的属性

	son()//:boss() 本质上是省略了这个的	是子类的无参构造函数
	{
		cout << "make son" << endl;
	}

	son(string name, int id):boss(name,id)
	{
		cout << "Im son" << endl;
	}


	void print() {
		cout << a << endl;	//所以继承下来的可以访问	
		cout << id << endl;	
		cout << name << endl;
		//但不论是什么继承方式 私有属性能被继承，但无法访问。
	}
protected:
	//注明：用public继承下来的权限就是原属性
	//		用protected继承下来的属性除私有外，全变成保护属性
	//		用private继承下来的属性都是私有属性	当然你在类中仍不能访问父类的私有
	//所以继承属性只能加强
private:



};

/*——————多继承————————*/
//多继承即是有两个父类
//上面都单继承

class A {

public:
	A(int a):a_num(a) {
		cout << "make A" << endl;
	};
protected:
	int a_num;
private:

};

class B {

public:
	B(int b):b_num(b) {
		cout << "make B" << endl;
	}
protected:
	int b_num;
private:

};

//构造顺序只和继承顺序有关
class C	:public A,protected B	//多继承
{

public:
	C(int a, int b, int c) :B(b), A(a), c_num(c) {
		cout << "make C" << endl;
	}
	void print() {
		cout << a_num << b_num << c_num << endl;
	}
protected:
	int c_num;
private:

};

int main() {

	/*son object;
	object.print();

	son object1("hh",100);
	object1.print();*/

	{
		C object(1, 2, 3);
		object.print();
	}

	return 0;
}