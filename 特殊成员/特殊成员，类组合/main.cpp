#include <iostream>
#include <string>

using namespace std;

class p {

public:

	//��ͨ����û�в����б�ֻ�й��캯������
	p(string name, int id):id(id)
	{
		this->name = name;
	}

	void test() {
		cout << "normal here" << endl;
	}

	void test()const		//���ǳ���Ա����
	{
		cout << "const here" << endl;
		cout << this->name <<"  " << this->id << endl;
		//���Զ����ݽ��з��ʣ������ɽ����޸�

	}

	void printdata() const 
	{
		cout << this->name << this->id << endl;
	}



protected:
	const int id;
	string name;
};

const p& returnp() {
	return p("����", 456);
}

/*�������������������������������������������������������������Ǿ�̬*/

class ui {

public:
	static void print() {

		//���Ǿ�̬����
		//�����ܷ��ʷǾ�̬��Ա������ֱ�ӷ��ʾ�̬���ݳ�Ա������û��thisָ��
		cout << count << endl;
	}

	ui(string name) {
		this->name = name;
	}

protected:
	string name;
	static int count;	//��̬��Ա�������������ڳ�ʼ��

	//��̬���ݳ�Ա�����࣬�����ڶ���ÿ���������õ�ͬһ����̬��Ա

};

int ui::count = 0;	//ֻ�������ʼ������Ҫ�޶�

void print()
{

	static ui op("hh");
}


int main() {

	/*//��ͨ����
	p object1("normal",123);
	object1.test();	//��ͨ�������ȵ�����ͨ����


	//������
	const p object2("const", 1001);		//��const���εĶ���
	object2.test();	//������ֻ�ܵ��ó���Ա����

	returnp().printdata();*/
/*������������������������������������������������������������������������������������ �����Ǿ�̬*/






	return 0;
}