#include <iostream>

using namespace std;

class A {

public:
	//�β��������ݳ�Ա����ͬ
	//1.��ʼ�������б�
	//2.thisָ��
	A(int a):a(a){}
	int a;
	void print(){
		cout << "A" << endl;
	}
};

class B :public A
{
public:
	int a;
	//���B�л���һ����A������ͬ����
	//ԭ�򣺾ͽ�ԭ��
	B(int a, int b) :A(a)
	{
		this->a = b;	//�����a����B�ģ���B��������ʹ��B��a��
	}

	void print() {
		//Ҫ�������޶��Ϳ��Է��ʸ����
		cout << "B" << endl;
		cout << a << endl;
		cout << A::a << endl;

		//���A���л���ͬ������
		A::print(); //������Ҫ�޶�
	}


};


int main() {

	A object(4);
	B object1(2, 3);

	object.print();
	object1.print();		//��˭�������˭��

	object1.A::print();		//������Ҫ���ø����ͬ������Ҫ�޶�

	/*����������������*/

	A* pa = new A(5);
	B* pb = new B(8,9);
	//��������ָ�븳ֵ��ͬʱҲ���������ķ���

	/*���ӡ�>�� ����ת��*/
	A* pA = new B(5, 6);	//���ǲ�������ֵ�����������ʼ��
	pA->print();			//û��virtualʱָ�����ĸ���ľ͵����ĸ�
	pA = &object1;			//����Ҳ�ǻ���ø����

	/*�Ӹ�->��  ����ת��  һ�㲻������*/
	//B* pB = new A(12);	error  ��Ȼ��һ������ǿ��ת����B��Ҳ��


	return 0;
}