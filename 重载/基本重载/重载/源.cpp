#include <iostream>
#include <string>

using namespace std;
//��������ر���Ҫ��һ���Զ�����

class Data {

public:

	Data(int f,int s):first(f),second(s){}
	void print() {
		cout << first << " " << second << endl;
	}
	//��operator�����������
	//����Data����
	//������Ԫ�ķ�ʽ�������������ڲ�����
	friend Data operator+(Data first, Data second);		//���������һ������

	/*�������������Ա�������ء���*/
	//���ʾ�������Ԫ��ռһ�������õĶ���ռһ��
	Data operator-(const Data& object) {
		return Data(this->first - object.first, this->second - object.second);
	}

protected:

	int first;
	int second;

};

//ʵ�ֹ��̱������������Ч��
Data operator+(Data one, Data two) {

	//ΪʲôҪ����Ԫ�أ���Ҫ����Ԫ����ͻ�Ʒ�������
	//ͨ�������������󷵻�
	return 	Data(one.first + two.first, one.second + two.second);

}

int main() {

	Data data1(1, 2);
	Data data2(3, 4);

	Data data3 = data1 + data2;		//������ʵ����ʽ����

	data3.print();					

	Data result = operator+(data1, data2);	//����������ʾ���� ��ʽ���ûᱻ����������	

	//ע�⣺һ���������һ������ֻ�ܱ�����һ��			

	result.print();					

	Data data4 = data1 - data2;		//��������ʽ����

	Data result2 = data1.operator-(data2);		//��������ʾ���� ���Ա��

	result2.print();

	data4.print();

	/*�������ֺ������ض�������ʽ��ʽ���á���*/

	//= -> [] ֻ���ó�Ա�����ķ�ʽ��������
	//��Ŀ����������Ա���أ�˫Ŀ���������Ԫ�����ķ�ʽ����




	
	return 0;
}
