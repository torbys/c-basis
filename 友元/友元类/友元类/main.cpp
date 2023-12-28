#include <iostream>
#include <string>

#include <graphics.h>

using namespace std;

/*����������Ϊ��Ԫ��������*/

class A {

	friend class B;		//��Ԫ��Ĵ��� B��A����Ԫ��

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

		//��B�ഴ��������A��Ա��������Ȩ�޹���
		A object;
		object.print();
		object.print2();
		object.print3();
		//���ʷ�ʽ���䣬ֻ��Ȩ������
		//˭�Ķ���ֻ�ܷ���˭�ķ���
		A::prints();	//��̬���ǿ���ֱ�ӷ���
	}
	
protected:

};

/*����������Ϊ��Ԫ��������*/

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


/*�����������á�������*/
void print1(int&& a) {	//ֻ�ܴ�����

}

void print2(int& a) {	//ֻ�ܴ�����

}

void print3(const int& a) {	//���Դ������ͱ���,ֻ�Ǵ������Ĳ������ܽ��и���


}



int main() {

	B object;

	object.printB();

	//object.print();	��Ȼ�����ⴴ���Ķ�����ֻ�ܷ�������

	/*����������ֵ���á�������*/

	int&& a = 1;			//������ֵ����
	const int& b = a;		//��const����ֵ����

	const int num = 9;		//���г����Եı���
	//int&& num1 = num;		�����ǲ��е���Ϊnum���ʻ��Ǳ�����ֻ�Ǽ����˳����Բ��ܸ�����ֵ����

	int movenum = 10;

	int&& data = move(movenum);		//move��������ֵ�����ֵ

	print1(456);		//ֻ�ܴ�����
	print2(movenum);	//ֻ�ܴ�����

	print3(movenum);	//both of
	print3(456);



	return 0;
}