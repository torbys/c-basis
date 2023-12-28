#include <string>	//这个头文件和c语言中的string.h完全不同
#include <iostream>
#include <cstdio>

using namespace std;

struct test {

	int data;
	char* name;
	void setdata(const char* newName, int Newdata) {

		//name=newName; 错误
		name = const_cast<char*>(newName);	//直接传是不行的，要去掉常属性
		data = Newdata;

	}


};

int mymax(int a, int b) {
	return a > b ? a : b;
}


void testString() {

	//1.如何去定义

	//1.1常见定义

	string str1;	//在c++中string是类，所以可以像创建变量一样创建
	str1 = "i love you";	//创立后初始化
	string str2("deep");	//也可在创立时初始化
	string str3(str2);		//也可在创立时用其他字符串初始化

	//1.2不常见定义

	string str4(5, 'p');	//表示用5个字符‘p’初始化
	string str5("you  are my love", 0, 8);	//表示用字符串中的0~8个字符初始化


	//2.基本操作

	//2.1可用string类里的函数检查它的一些属性
	cout << str1.size() << endl;		//获取元素个数
	cout << str1.length() << endl;		//获取长度
	cout << str1.capacity() << endl;	//获取当前容量 会自动增长 初始为15

	//2.2string类的比较 直接用运算符即可

	//str1 > str2;	
	//str1 == str2;
	//str1 != str2;
	//str1 = str2;
	//上述运算符都可以直接作用到string类上
	string ret;
	ret = str1 + str2;	//+则是将str1,str2链接

	//这上面本质都是运算符重载，和函数一样的，对于两边的类型自动检测而调用对应的运算符


	//3.string和char*  的转化
	//不能用%s的方式打印string
	string info("c++的字符");
	printf("%s\n", info.c_str());	
	printf("%s\n", info.data());	//data(),c_str()，是可以获取string里面的字符串的

	char name[20] = "";
	string strname("世界");
	//上面俩不能直接赋值，要用strcpy函数，和c_str访问

	//3.1下标访问

	string pstr = "iuop";
	//通过pstr.at(i)的方式访问单个下标

	cout << pstr.at(2) << endl;


}

void testcast(){

	//类型转换
	/*
	这些转换都是在指针上

	static_cast:		类似c的强制类型转换
	const_cast			去常属性
	reinterpret_cast	可以使整数和指针互转
	dynamic_cast		
	
	而基本类型转换则是：类型（变量）即可

	*/

	//这是基本类型转换
	int ctran = (int)1.1;	//c的强制转换在cpp也可以用
	int cpptran = int(1.1);	//这是cpp的强制转换

	//static_cast<转换的类型>（转换的变量）
	double dnum = 1.1;
	int num = static_cast<int>(dnum);	//c++提供的更为安全的类型转换
	//用static_cast赋值const属性；
	int x = 0;
	const int num2 = static_cast<const int>(x);	//这是将x设置成常属性然后赋值给num2

	//当然static_cast去除不了常属性
	//即你想让一个指针指向这个去除常属性的地址是不行的

	//const_cast可以去除常属性
	int* p = const_cast<int*>(&x);	


}

void testReinterpret() {

	decltype (mymax)* pmax = mymax;

	cout << hex << pmax << endl;
	int num = reinterpret_cast<int>(pmax);
	cout << num << endl;

}

int main() {

	test uio;
	char a[10] = { "uiop" };
	uio.setdata(a, 46);

	testReinterpret();


	return 0;
}