#include <iostream>
#include <string>

using namespace std;

#define N 10;

class object {

	//������c++��11����֧�������г�ʼ��

	//�����������Խ���Ȩ���޶��ʣ����ڽṹ����Ҳ����ʹ��
	//��д�ؼ���Ĭ����˽��private���ԣ��ڽṹ����Ĭ���ǹ���public����

	int age;	//�������޶���Ϊ˽������

public:			//public�����еĹ����ӿڣ�������ͨ��public�������е����ݵ��ֶ�
	int num;
	void print() {	//���ຯ��Ĭ��Ϊ��������
		auto pt = [this]() { cout << this->age << endl; };	//thisָ�������lambd���ʽ
		cout << name << " " ;
	}

	object self() {
		return *this;	//thisָ���ָ�������ĵ�ַ��*this������౾��
	}

	void setdata(string newName,int newMoney,int newNum)	//����ͨ�����εķ�ʽ��ʼ������,����ͨ������ӿڷ�������
	{
		name = newName;
		money = newMoney;
		num = newNum;
	}

	string& getname() {	//ͨ�����÷��ʣ���ȡ����
		return name;
	}

	void setdata2(string name, int money, int num)	//����βκ����ݳ�Ա����һ��
	{

		cout <<"this:" << this << endl;
		object::name = name;	//�����������޶�
		this->money = money;	//��thisָ���޶�
		this->num = num;		//thisָ�������������Ķ����ָ���������ĵ�ַ���������뿪���󵥶����ڡ�

	}

protected:
	string name{"iloveyou"};	//�������ԣ�һ��ʹ������Ŀ������

private:			//�������ⲿ����ϵдΪ˽������
	int money = 114514;

	//��Щ�޶��ʶ����޶���������еķ��ʣ��������һ�㶼��Ҫ����
	//ֻ�о�̬���ݳ�ԱҲ��Ȩ�ޣ����Բ���Ҫ�������

	//����ֻ�ܷ���public��Ա
	//protected��private�������Ա����ʣ����ǵ��������ڼ̳�����

	//��Ȼ�����ж�����ȥ����û���޶�

};
//����

int** testarray() {

	int** array = new int* [10];

	for (int i = 0; i < 10; i++) {
		array[i] = new int[5];
	}

	return array;
}

void deletearray(int** &array,int row) {

	for (int i = 0; i < row; i++) {
		delete[]array[i];
	}
	delete[]array;
	array = nullptr;
}

void testobject() {

	object girl;	//��������

	girl.num = 520;
	girl.setdata("С�һ�", 520, 1314);
	girl.print();

}

int main() {

	//testobject();

	object array[3];	//�������飬�������������ݽṹһ��ʹ��

	object* p = array;

	//���������һ�����ݣ������Ժ���������һ��ʹ��

	object mm;
	cout << &mm << endl;
	mm.setdata2("���",16, 89);
	mm.print();

	object pp;
	cout << &pp << endl;
	pp.setdata2("����", 44, 33);
	pp.print();

	object why;

	//1,����auto�ƶ���ĺ���ָ��
	auto func = &object::print;	//�õ������Ա������ָ�룬����Ҫ��ȡ��ַ��
	(why.*func)();	//��*func���ʾ���print��




	return 0;
}