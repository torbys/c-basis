/*
	��virtual���εĺ������麯��
*/
#include <iostream>

using namespace std;
class A {

public:

	virtual void print();	//�����麯��������һ���麯��ָ�����洢�ģ������ٶ���麯��Ҳ����ı�

protected:

};

class B {
public:
	int a;
	double i;
	double o;
};

void A::print() {
	cout << "�麯��" << endl;
}

class C {
	/*
		���麯����û�к�������麯��
		�����ࣺ���ٺ���һ�����麯��
		���ԣ����ܹ�����󣬵����Դ������ָ�룻�ڶ�̬��������
	*/
public:
	virtual void print() = 0;
};




int main() {
	//�յĽṹ��or��ռ��һ���ڴ�
	cout << "A:" << sizeof(A) << endl;
	//�����ݵ���or�ṹ��ռ���ֽ�������һ������ֽڵ�������,�������˼�ǰ�û�дﵽ����ֽڵ����ݲ����ֽ�
	cout << "B:" << sizeof(B) << endl;
	
	A object;
	auto p = &A::print;

	typedef void(A::*f)();

	/*��������������������������������*/

	C* p = nullptr;		//���Թ���ָ�����

	//C object;		����ģ����ܹ�������	


	return 0;
}