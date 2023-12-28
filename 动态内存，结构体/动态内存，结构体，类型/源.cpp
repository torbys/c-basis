#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
//#include <bits/stdc++.h>	

using namespace std;

struct ui {
	//c++的结构体访问类的和c一样
	//但在c++中允许有函数


	//数据成员
	char name[20];
	int age;

	//函数成员
	void test() {
		cout << "坏蛋" << " ";
		cout << name << " " << age << endl;	//结构体里的函数可以直接使用里面的变量
	}
	void testop();	//如果要在结构体外声明结构体函数则必须在结构体里声明函数类型

	void dataset(const char* newName,int newAge); //也可以在结构体里定义一个函数 只需调用一个函数就可以设置数据
	//即对数据的操作都可以封装到自己的结构体里面去

};

void ui::testop() {	//结构体外声明
	cout << age << endl;
}

void dataset(const char* newName, int newAge) {
	
}

void testnew() {

	int* cpp = new int[3];

	cpp[0] = 520;
	cout << cpp[0] << endl;

	delete[] cpp;

	//申请内存并且初始化
	//c++中单个数据用（），多个数据用{}

	//单个
	int* op = new int(100);	//将这个空间的值设置为100

	//多个
	int* ip = new int[3] { 1, 2, 3 };


}

void testcourt() {

	//先申请100个字节大小的内存
	char* sum = new char[100];
	//可以自由控制这个100个字节
	int* pint = new(sum + 0)int [4] {5, 6, 3, 5};	//用了前面16个字节放4个整数
	
	char* pchar = new(pint+4)char[20] {"i love you"};	//用16个字节后的二十个字节放字符串

	//通过上面可知道：new后加()代表从哪个地方开始再分配内存，注()内要有对应的指针作为操作点
	// 
	//如sum+0代表从sum的第0个数据长度开始管理，pint+4代表从pint类型的第4个数据长度开始管理

	cout << *(pint+1) << endl;
	cout << pchar << endl;

	delete[] sum;

}


void teststruct() {

	ui* ps = new ui{ "你好",555 };	//不用typedef，可以直接用结构体名称

	cout << ps->name << " " << ps->age << " " <<  endl;

	ps->test();

	//c++结构体申请内存
	//这在没有构造函数的情况下是对的

	ui* p = new ui{};	//申请一个内存,可用大括号初始化
	//也可一一对应初始化
	delete p;
	p = nullptr;

	ui* array = new ui[3];	//这样申请就是结构体数组了



}

int main() {

	//testcourt();

	ui op;

	op.testop();

	
	





	//teststruct();
	return 0;
}