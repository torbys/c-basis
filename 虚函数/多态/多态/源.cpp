#include <iostream>
#include <string>

using namespace std;

/*
	��̬��һ����Ϊ�����в�ͬ�Ľ��
	���ɳ�ʼ������Ĳ�ͬ�����µ���Ϊ��ͬ��
	ԭ��
	1.����Ϊ���м̳�
	2.�������virtual����
	3.�����ǲ�������ָ������
*/

class girl {

public:
	virtual void print() {
		cout << "girl���麯��" << endl;
	}
};

class Boy : public girl
{

public:
	//������ͬ�������麯�� ��Boy���в���Ҫvirtual�޶������麯��
	void print() 
	{
		cout << "boy���麯��" << endl;
	}
protected:
};




int main() {

	//�����Ĵ����ͷ��ʶ��Ǿͽ�ԭ��

	//��������
	//1.����ָ������������ʼ��
	Boy object;
	girl* pg = new Boy;
	pg->print();	//������virtual��������ǿ������������ ����ָ��

	pg = new girl;
	pg->print();	//��������ʹ�õĳ�ʼ������ͬ�� ʹ�õķ�����ͬ ����Ƕ�̬

	//����ָ���ø����ʼ��������ȫ����
	Boy* pboy = dynamic_cast<Boy*>(new girl);	//�Ӹ���������ת��
	//�������ת�����ɹ���᷵��nullptr




	return 0;
}	