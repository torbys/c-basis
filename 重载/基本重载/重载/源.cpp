#include <iostream>
#include <string>

using namespace std;
//运算符重载必须要有一个自定义类

class Data {

public:

	Data(int f,int s):first(f),second(s){}
	void print() {
		cout << first << " " << second << endl;
	}
	//用operator运算符来定义
	//返回Data类型
	//参数友元的方式：参数个数等于操作数
	friend Data operator+(Data first, Data second);		//这个本质是一个函数

	/*——以下是类成员函数重载——*/
	//本质就是类中元素占一个，引用的对象占一个
	Data operator-(const Data& object) {
		return Data(this->first - object.first, this->second - object.second);
	}

protected:

	int first;
	int second;

};

//实现过程便是最后的运算符效果
Data operator+(Data one, Data two) {

	//为什么要用友元呢，主要是友元可以突破访问限制
	//通过构造匿名对象返回
	return 	Data(one.first + two.first, one.second + two.second);

}

int main() {

	Data data1(1, 2);
	Data data2(3, 4);

	Data data3 = data1 + data2;		//这种其实是隐式调用

	data3.print();					

	Data result = operator+(data1, data2);	//这种则是显示调用 隐式调用会被解析成这样	

	//注意：一个运算符在一个类中只能被重载一次			

	result.print();					

	Data data4 = data1 - data2;		//减法的隐式调用

	Data result2 = data1.operator-(data2);		//减法的显示调用 类成员型

	result2.print();

	data4.print();

	/*——这种函数重载都是用隐式方式调用——*/

	//= -> [] 只能用成员函数的方式进行重载
	//单目运算符用类成员重载；双目运算符用友元函数的方式重载




	
	return 0;
}
