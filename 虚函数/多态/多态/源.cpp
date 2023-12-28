#include <iostream>
#include <string>

using namespace std;

/*
	多态：一种行为可以有不同的结果
	（由初始化对象的不同而导致的行为不同）
	原则：
	1.必须为公有继承
	2.必须存在virtual类型
	3.必须是不正常的指针引用
*/

class girl {

public:
	virtual void print() {
		cout << "girl的虚函数" << endl;
	}
};

class Boy : public girl
{

public:
	//满足了同命还是虚函数 在Boy类中不需要virtual限定就是虚函数
	void print() 
	{
		cout << "boy的虚函数" << endl;
	}
protected:
};




int main() {

	//正常的创建和访问都是就近原则

	//不正常的
	//1.父类指针用子类对象初始化
	Boy object;
	girl* pg = new Boy;
	pg->print();	//这种有virtual的情况就是看对象的类型了 无则看指针

	pg = new girl;
	pg->print();	//由于我们使用的初始化对象不同则 使用的方法不同 这既是多态

	//子类指针用父类初始化，不安全少用
	Boy* pboy = dynamic_cast<Boy*>(new girl);	//从父到子下行转换
	//如果这种转换不成功则会返回nullptr




	return 0;
}	