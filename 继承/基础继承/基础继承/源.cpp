#include <iostream>
#include <string>

using namespace std;
//�̳���Ҫ������
//���µ����Ժ���Ϊ�м̳У����µ����Ժ���Ϊ����������������ͳ���ж��м̳�

//���ԣ��ڸ����еĵ����ԣ����඼��һ�ݣ���һ���������ɼ̳з�ʽ������

class boss {

public:
	boss(){
		cout << "make father" << endl;
	}

	boss(string name,int id):name(name),id(id){
		cout << "Im father" << endl;
	}	//����Ĺ��캯��

	int a=10;
	void print() {
		cout << "boss" << endl;
	}

protected:

	int id=16;
	string name;

private:

	int c;

};

class son : public boss		//������Ǽ̳���ʽ	class ������ : �̳з�ʽ ������
{
public:
	//����Ĺ��캯��������ø���Ĺ��캯������ʼ���������

	son()//:boss() ��������ʡ���������	��������޲ι��캯��
	{
		cout << "make son" << endl;
	}

	son(string name, int id):boss(name,id)
	{
		cout << "Im son" << endl;
	}


	void print() {
		cout << a << endl;	//���Լ̳������Ŀ��Է���	
		cout << id << endl;	
		cout << name << endl;
		//��������ʲô�̳з�ʽ ˽�������ܱ��̳У����޷����ʡ�
	}
protected:
	//ע������public�̳�������Ȩ�޾���ԭ����
	//		��protected�̳����������Գ�˽���⣬ȫ��ɱ�������
	//		��private�̳����������Զ���˽������	��Ȼ���������Բ��ܷ��ʸ����˽��
	//���Լ̳�����ֻ�ܼ�ǿ
private:



};

/*��������������̳С���������������*/
//��̳м�������������
//���涼���̳�

class A {

public:
	A(int a):a_num(a) {
		cout << "make A" << endl;
	};
protected:
	int a_num;
private:

};

class B {

public:
	B(int b):b_num(b) {
		cout << "make B" << endl;
	}
protected:
	int b_num;
private:

};

//����˳��ֻ�ͼ̳�˳���й�
class C	:public A,protected B	//��̳�
{

public:
	C(int a, int b, int c) :B(b), A(a), c_num(c) {
		cout << "make C" << endl;
	}
	void print() {
		cout << a_num << b_num << c_num << endl;
	}
protected:
	int c_num;
private:

};

int main() {

	/*son object;
	object.print();

	son object1("hh",100);
	object1.print();*/

	{
		C object(1, 2, 3);
		object.print();
	}

	return 0;
}