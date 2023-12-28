#include <iostream>

using namespace std;	//里面的的头文件都是用std的命名空间命名 加这个就不要std进行访问

/*namespace student {		//c++的命名空间

	int data;
	char name[20];

	namespace time {	//嵌套命名空间内容

		int year;
		int mouth;
		int day;

	}
}

using namespace student;
using namespace student::time;	//当前位置以下都可以用*/

void myswap(int& a, int& b)	
//引用数据类型 &标识符1=标识符2：
{
	int temp = a;
	a = b;
	b = temp;

}

void print(const char* str) {
	cout << str << endl;
}

int& test(int num = 6) {
	return  num;
}

int main() {

	/*
	
	左值准确来说是：一个表示数据的表达式(如变量名或解引用的指针）
	且可以获取他的地址（取地址）
	可以对它进行赋值；它可以在赋值符号的左边或者右边。

	右值准确来说是：一个表示数据的表达式（如字面常量、函数的返回值、表达式的返回值）
	且不可以获取他的地址（取地址）
	它只能在赋值符号的右边。
	
	数据类型 &标识符1 = 标识符2	这个叫左引用	给左边的值起别称，即2和1是同一个东西，对2的改变会给1一样的作用 2就像1的另一个别称 用来替换c语言的指针
	1.常数的直接引用是不允许的
	  需要在&符号之前加const	这种和宏定义是差不多的：给一个常量起一个名称

	2.右值引用
	  数据类型 &&标识符1 = 标识符2	这样也可以标识常量，即给右边的值起别名	

	3.引用的用法
	  （1）当作函数的参数 可以像指针一样改变传入的参数的值 取指针的引用也可以 也可改变指针的指向

	  （2）充当函数返回值 但不能返回局部变量或者临时变量的值 因为会被销毁，那么引用就无意义

	4.作用域分辨符::

	::变量,代表它会从全局变量去找
	不加就是就近去找同名变量

	5.自动推断类型

	auto ：当你在定义一个变量时加上auto会根据你定义这个变量的形式推断这个变量是什么类型

	decltype: 可推断函数指针,decltype (myswap)*p = myswap;


	*/
	
	
	/*
	
	函数的使用
	1.c++对参数的传递更严格
	  不加const只能传变量
	  加了const既可以传变量也可以传常量
	  只加&& 右引用 就只能传常量	用move可以把左值换成右值。
	
	2.内联函数
	inline int ***(int *,int*)
	就是inline加在前面，只是把函数以二进制去存储，只适合短小的函数去使用，提高效率

	3.重载函数
	c++允许同名不同参的函数出现，根据传入参数的数量和形式去选择调用哪一个函数
	可以被类为重再函数的为
	参数个数不同；参数类型不同；参数顺序不同（建立在类型不同的前提下）

	如果参数里加const不构成重载，这属于定义重复会出现错误；

	4.缺省思想
	给函数的形参初始化

	注：顺序必须是从右往左不能跳；不传参数就是默认参数

	5.lambda表达式

	可以不用在外定义一个函数，可以直接用这个表达式代替函数的功能

	形式：[捕获方式](函数参数)【(能否修改)(是否存在异常)->函数返回值类型】{函数体;}

	捕获方式：（1）[] （2）[&] （3）[=] （4）[&x] (5)[this]
	函数参数：自己写的函数参数
	能否修改：mutable
	是否存在异常：throw（）是空就是不存在异常
	
	【】起来的可以省略，其他是必备的

	例：求最大值函数
	
	完整形式：int (*pmax)(int,int)=[](int a,int b)mutable throw()->int{return a>b?a:b;};

	省略版本  auto p = [](int a, int b) {return a > b ? a : b; };

	auto p = [](int a, int b) {return a > b ? a : b; };

	cout << p(8, 9) << endl;	//auto保存了再用
	cout << ([](int a, int b) {return a > b ? a : b; })(8, 9) << endl;	//直接用

	捕获方式了解

	[=]:值的方式捕获，代表可以使用外部的值，一旦捕获了一次值那就不会改变传入的值；

	[&]:用引用的方式捕获,可以根据值的改变而改变传入的值

	*/

	return 0;
}