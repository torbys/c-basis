#include <iostream>
#include <string>

using namespace std;

class ui {

public:

	//��ͨ����
	void print() {
		cout << name << "\t" << id << endl;
	}
	
	//��Ԫ��������friend����������
	friend void visited();

	friend void test(ui& object);

	friend void pattern() {

		ui object;
		object.name;

	}

protected:
	string name = "wow";
	int id = 8;

};


//��Ԫ�����������࣬����������ʵ��ʹ����Ҫ��Ĺؼ��֣���friend�ؼ���
void visited() {

	//���ã��ṩһ���������������д���Ȩ�޵Ĺ���

	ui object;	//����Ԫ�����д���Ķ�����Դ���Ȩ�޷���

	cout << object.name << "\t" << object.id << endl;

}

void test(ui& object) {

	cout << object.name << "\t" << object.id << endl;

}



/*�����ǲ�������д������A���ж���B����Ԫ����*/

class B {

public:
	void printB();

protected:
	string name = "po";
	int id = 10;
};

class A {

public:

	friend void B::printB();

protected:

	string name = "op";
	int count = 1;

};

void B::printB() {

	A object;
	B object1;

	cout << object.name << "\t" << object.count << endl;
	cout << object1.name << "\t" << object1.id << endl;

}

struct op {

	int n;
	int a;

};


void get(op* object) {

	cin >> object->a >> object->n;
	while (object->a <= 10 || object->n < 1 || object->n>9) {
		cout << "ui";
		cin >> object->a >> object->n;
	}
}

int main() {

	/*ui object1;

	visited();
	
	test(object1);
	B b;

	b.printB();*/
	op x;

	get(&x);


	return 0;
}
