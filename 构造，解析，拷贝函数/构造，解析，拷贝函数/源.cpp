#include <iostream>
#include <string>

using namespace std;

class object {

public:

	//object() {}//Ϊ�˹�����󷽱㣬����һ����һ��Ĭ�ϵĹ��캯��������ȱʡ�Ĺ��췽ʽ

	object() = default;		//ʹ��Ĭ�ϵ��޲ι��캯��;

	/*object(int age = 45, int money = 46)	//ȱʡ�Ĺ��캯�����Թ��첻�������Ķ���Ҳ���Դ��� 
	{
		this->age = age;
		this->money = money;
	}*/

	//���û��д���캯����������Ĭ�ϴ���һ�����캯�� object(){}
	object(int age, int money) //����ǹ��캯�������޷���ֵ
	{
		cout << "���ι��캯��" << endl;
		this->age = age;
		this->money = money;

	}

	void printdata() {
		cout << age << "\t" << money << endl;
	}

protected:

	int age;
	int money;

};

class ufo {

public:

	//�ȷ�һ�����캯��
	ufo(string name = "iloveyou", int age = 20) {
		cout << "���캯��" << endl;
		this->name = name;
		this->age = age;
	}

	ufo(int a) {
		this->age = a;
		cout <<"����ɣ�" << age << endl;
	}

	//�������캯��	ֻ��һ���������Զ�������� Ŀ������ʵ��һ���������һ������ĸ�ֵ ����һ�����󴴽��¶���
	ufo(ufo& op) {
		cout << "�������캯��" << endl;
		name = op.name;
		age = op.age;

	}

	~ufo() {		//������������һ����������ʱ����Զ�����
		cout << "����������";
		cout << age << endl;
	}

protected:
	string name;

	int age;

};

ufo s1(1);
void function() {

	cout << "�����˳��" << endl;

	ufo s2(2);		//
	ufo* s3 = new ufo(3);		//�����ڴ��ں������в������� ��ɾ���ŵ��ý���
	delete s3;
	ufo s4(4);		//2��4������ʱ�����������ں����������������ʱ���Զ����ý�������

}

void print1(ufo ot) {}

void test(ufo& oi){}

void print(object&& data) {
	 data.printdata();
}

int main() {

	int a = 0, b = 0, c = 0;
	//a = a + 7 = b + c;

	

	//function();

	/*//�������Ĺ��̣����ǵ��ú����Ĺ���
	object(45, 56);		//����or�������� 
	print(object(78, 65));

	//�����Լ�д�˹��캯��֮����Ķ���͵��ǹ��캯��������
	//object ui;	//��Ϊ���캯��������������������������һ���޲ζ����Ǵ��
	object oi(88, 44);
	oi.printdata();
	
	//newһ������
	//1.����һ����������
	//2.������������׵�ַ��ֵ��ָ��
	
	object array[3] = {};
	*/
//����������������������������������������������������������������--// �����ǿ�������

	//�ǿ��������ĵ���
	ufo m1 = { "hhh",36 };
	//ufo m2 = ufo{ "ooo",56 };

	ufo m3;
	m3 = m1;	

	//�������캯����ʹ��
	cout << "�����ǿ�������"<<endl;
	ufo t1;

	ufo t3(t1);		//���캯����ʹ�ã���t1��ʼ��t3��������ʽ1��

	ufo t4 = m3;

	print1(t4);
	cout << "test" << endl;
	test(t4);

	/*
		1.�������죬һ�����´������

		2��ͨ��һ�����󴴽���һ������һ���´������

		3.�ں����д��������������û�д����¶������Բ�����ÿ�������
	
	*/

	return 0;
}