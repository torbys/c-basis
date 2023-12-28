#include <iostream>
#include <string>

using namespace std;

#define N 10;

class object {

	//在如今的c++（11）都支持在类中初始化

	//以下三个属性叫做权限限定词，且在结构体中也可以使用
	//不写关键字默认是私有private属性，在结构体中默认是公有public属性

	int age;	//这种无限定词为私有属性

public:			//public是类中的公共接口，是类外通过public访问类中的数据的手段
	int num;
	void print() {	//这类函数默认为内联函数
		auto pt = [this]() { cout << this->age << endl; };	//this指针可以用lambd表达式
		cout << name << " " ;
	}

	object self() {
		return *this;	//this指针会指向这个类的地址，*this即这个类本身
	}

	void setdata(string newName,int newMoney,int newNum)	//可以通过传参的方式初始化数据,并且通过这个接口访问数据
	{
		name = newName;
		money = newMoney;
		num = newNum;
	}

	string& getname() {	//通过引用访问，获取数据
		return name;
	}

	void setdata2(string name, int money, int num)	//如果形参和数据成员名称一样
	{

		cout <<"this:" << this << endl;
		object::name = name;	//可以用类名限定
		this->money = money;	//用this指针限定
		this->num = num;		//this指针会根据所创立的对象而指向这个对象的地址，它不能离开对象单独纯在。

	}

protected:
	string name{"iloveyou"};	//保护属性，一般使用在项目程序中

private:			//降低与外部的联系写为私有属性
	int money = 114514;

	//这些限定词都是限定内外对类中的访问，类外访问一般都需要对象
	//只有静态数据成员也受权限，可以不需要对象调用

	//类外只能访问public成员
	//protected和private都不可以被访问，它们的区别在于继承里面

	//当然在类中都可以去访问没有限定

};
//类外

int** testarray() {

	int** array = new int* [10];

	for (int i = 0; i < 10; i++) {
		array[i] = new int[5];
	}

	return array;
}

void deletearray(int** &array,int row) {

	for (int i = 0; i < row; i++) {
		delete[]array[i];
	}
	delete[]array;
	array = nullptr;
}

void testobject() {

	object girl;	//创建对象

	girl.num = 520;
	girl.setdata("小家伙", 520, 1314);
	girl.print();

}

int main() {

	//testobject();

	object array[3];	//对象数组，类可以像基本数据结构一样使用

	object* p = array;

	//对象本身就是一个数据，它可以和其他数据一样使用

	object mm;
	cout << &mm << endl;
	mm.setdata2("你好",16, 89);
	mm.print();

	object pp;
	cout << &pp << endl;
	pp.setdata2("世界", 44, 33);
	pp.print();

	object why;

	//1,这是auto推断类的函数指针
	auto func = &object::print;	//得到的类成员函数的指针，必须要有取地址符
	(why.*func)();	//那*func本质就是print嘛




	return 0;
}