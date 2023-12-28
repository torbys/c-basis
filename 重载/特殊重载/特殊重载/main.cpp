#include <iostream>

using namespace std;

class A {

public:

	A(string name=" ",int money=1000):name(name),money(money){}
	void print() {
		cout << name << "\t" << money << endl;
	}

	//++,--��Щ����������װ��
	A operator++()
	{
		this->money++;
		return *this;
	}

	A operator++(int) //����һ�����ò����䵱��ǣ���ʶΪ��׺
	{
		return A(this->name, this->money++);
	}

	operator int() {	//�൱��������һ���Ⱥţ�ֻȡ���е�һ�����ݽ��и�ֵ
		return this->money;
	}

	operator string() {
		return this->name;
	}

protected:

	string name;
	int money;

};

//�ı����أ����غ�׺
//����һ��Ϊunsigned long long
//һ����»��ߺͿ�������� �������ز������޶�����ģ����Բ�����������Ԫ��

unsigned long long operator ""_h(unsigned long long num) {
	return num * 60 * 60;		//ת��������;
}

void print1(int num) {
	cout << num << endl;
}


/*�������������������������������������š���������������������������������*/

class B {

public:
	void operator()() {
		cout << "here" << endl;
	}

protected:

	int id;

};



int main() {

	A object("me", 100);
	
	object++.print();
	(++object).print();

	/*������������������������������������*/

	long num = 1L;
	unsigned int num2 = 1u;

	print1(1_h);
	print1(4_h);

	int text = object;//����������ԭ������Ϊ�����ʽת��

	string ui = object;

	cout << ":" << text << "\t" << ui << endl;

	B object1;
	object1.operator()();
	object1();
	B()();


	return 0;
}