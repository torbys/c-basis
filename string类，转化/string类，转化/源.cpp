#include <string>	//���ͷ�ļ���c�����е�string.h��ȫ��ͬ
#include <iostream>
#include <cstdio>

using namespace std;

struct test {

	int data;
	char* name;
	void setdata(const char* newName, int Newdata) {

		//name=newName; ����
		name = const_cast<char*>(newName);	//ֱ�Ӵ��ǲ��еģ�Ҫȥ��������
		data = Newdata;

	}


};

int mymax(int a, int b) {
	return a > b ? a : b;
}


void testString() {

	//1.���ȥ����

	//1.1��������

	string str1;	//��c++��string���࣬���Կ����񴴽�����һ������
	str1 = "i love you";	//�������ʼ��
	string str2("deep");	//Ҳ���ڴ���ʱ��ʼ��
	string str3(str2);		//Ҳ���ڴ���ʱ�������ַ�����ʼ��

	//1.2����������

	string str4(5, 'p');	//��ʾ��5���ַ���p����ʼ��
	string str5("you  are my love", 0, 8);	//��ʾ���ַ����е�0~8���ַ���ʼ��


	//2.��������

	//2.1����string����ĺ����������һЩ����
	cout << str1.size() << endl;		//��ȡԪ�ظ���
	cout << str1.length() << endl;		//��ȡ����
	cout << str1.capacity() << endl;	//��ȡ��ǰ���� ���Զ����� ��ʼΪ15

	//2.2string��ıȽ� ֱ�������������

	//str1 > str2;	
	//str1 == str2;
	//str1 != str2;
	//str1 = str2;
	//���������������ֱ�����õ�string����
	string ret;
	ret = str1 + str2;	//+���ǽ�str1,str2����

	//�����汾�ʶ�����������أ��ͺ���һ���ģ��������ߵ������Զ��������ö�Ӧ�������


	//3.string��char*  ��ת��
	//������%s�ķ�ʽ��ӡstring
	string info("c++���ַ�");
	printf("%s\n", info.c_str());	
	printf("%s\n", info.data());	//data(),c_str()���ǿ��Ի�ȡstring������ַ�����

	char name[20] = "";
	string strname("����");
	//����������ֱ�Ӹ�ֵ��Ҫ��strcpy��������c_str����

	//3.1�±����

	string pstr = "iuop";
	//ͨ��pstr.at(i)�ķ�ʽ���ʵ����±�

	cout << pstr.at(2) << endl;


}

void testcast(){

	//����ת��
	/*
	��Щת��������ָ����

	static_cast:		����c��ǿ������ת��
	const_cast			ȥ������
	reinterpret_cast	����ʹ������ָ�뻥ת
	dynamic_cast		
	
	����������ת�����ǣ����ͣ�����������

	*/

	//���ǻ�������ת��
	int ctran = (int)1.1;	//c��ǿ��ת����cppҲ������
	int cpptran = int(1.1);	//����cpp��ǿ��ת��

	//static_cast<ת��������>��ת���ı�����
	double dnum = 1.1;
	int num = static_cast<int>(dnum);	//c++�ṩ�ĸ�Ϊ��ȫ������ת��
	//��static_cast��ֵconst���ԣ�
	int x = 0;
	const int num2 = static_cast<const int>(x);	//���ǽ�x���óɳ�����Ȼ��ֵ��num2

	//��Ȼstatic_castȥ�����˳�����
	//��������һ��ָ��ָ�����ȥ�������Եĵ�ַ�ǲ��е�

	//const_cast����ȥ��������
	int* p = const_cast<int*>(&x);	


}

void testReinterpret() {

	decltype (mymax)* pmax = mymax;

	cout << hex << pmax << endl;
	int num = reinterpret_cast<int>(pmax);
	cout << num << endl;

}

int main() {

	test uio;
	char a[10] = { "uiop" };
	uio.setdata(a, 46);

	testReinterpret();


	return 0;
}