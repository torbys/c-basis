#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
//#include <bits/stdc++.h>	

using namespace std;

struct ui {
	//c++�Ľṹ�������ĺ�cһ��
	//����c++�������к���


	//���ݳ�Ա
	char name[20];
	int age;

	//������Ա
	void test() {
		cout << "����" << " ";
		cout << name << " " << age << endl;	//�ṹ����ĺ�������ֱ��ʹ������ı���
	}
	void testop();	//���Ҫ�ڽṹ���������ṹ�庯��������ڽṹ����������������

	void dataset(const char* newName,int newAge); //Ҳ�����ڽṹ���ﶨ��һ������ ֻ�����һ�������Ϳ�����������
	//�������ݵĲ��������Է�װ���Լ��Ľṹ������ȥ

};

void ui::testop() {	//�ṹ��������
	cout << age << endl;
}

void dataset(const char* newName, int newAge) {
	
}

void testnew() {

	int* cpp = new int[3];

	cpp[0] = 520;
	cout << cpp[0] << endl;

	delete[] cpp;

	//�����ڴ沢�ҳ�ʼ��
	//c++�е��������ã��������������{}

	//����
	int* op = new int(100);	//������ռ��ֵ����Ϊ100

	//���
	int* ip = new int[3] { 1, 2, 3 };


}

void testcourt() {

	//������100���ֽڴ�С���ڴ�
	char* sum = new char[100];
	//�������ɿ������100���ֽ�
	int* pint = new(sum + 0)int [4] {5, 6, 3, 5};	//����ǰ��16���ֽڷ�4������
	
	char* pchar = new(pint+4)char[20] {"i love you"};	//��16���ֽں�Ķ�ʮ���ֽڷ��ַ���

	//ͨ�������֪����new���()������ĸ��ط���ʼ�ٷ����ڴ棬ע()��Ҫ�ж�Ӧ��ָ����Ϊ������
	// 
	//��sum+0�����sum�ĵ�0�����ݳ��ȿ�ʼ����pint+4�����pint���͵ĵ�4�����ݳ��ȿ�ʼ����

	cout << *(pint+1) << endl;
	cout << pchar << endl;

	delete[] sum;

}


void teststruct() {

	ui* ps = new ui{ "���",555 };	//����typedef������ֱ���ýṹ������

	cout << ps->name << " " << ps->age << " " <<  endl;

	ps->test();

	//c++�ṹ�������ڴ�
	//����û�й��캯����������ǶԵ�

	ui* p = new ui{};	//����һ���ڴ�,���ô����ų�ʼ��
	//Ҳ��һһ��Ӧ��ʼ��
	delete p;
	p = nullptr;

	ui* array = new ui[3];	//����������ǽṹ��������



}

int main() {

	//testcourt();

	ui op;

	op.testop();

	
	





	//teststruct();
	return 0;
}