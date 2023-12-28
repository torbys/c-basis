#include <iostream>
#include <string>

using namespace std;

class A {

public:

	A(string name=" ",int age=10):name(name),age(age){}
	//友元方式进行流重装
	friend istream& operator>>(istream& in, A& object);
	friend ostream& operator<<(ostream& out, A& object);

protected:

	string name;
	int age;

};

istream& operator>>(istream& in, A& object) {

	cout << "输入object的信息:";
	in >> object.name >> object.age;

	return in;
}

ostream& operator<<(ostream& out, A& object) {

	out << object.name << "\t" << object.age;

	return out;
}


int main() {

	A object;
	cin >> object;		
	cout << object;		
	


	return 0;
}