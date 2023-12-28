#include <iostream>

using namespace std;

class stack {
	//ADT
public:
	virtual void push(int data) = 0;
	virtual void pop()			= 0;
	virtual int top() const		= 0;
	virtual bool empty() const  = 0;
	virtual int size() const    = 0;

};

class arraystack :public stack
{
	//抽象类继承后，子类没有重写纯虚函数，则子类仍是抽象类
public:
	arraystack(int capacity = 10) {
		array = new int[capacity];
		stacktop = -1;
	}
	void push(int data) {

	}
	void pop() {


	}
	int top() const {


	}
	bool empty() const {


	}
	int size() const {


	}
protected:
	int* array;
	int stacktop;
};

class liststack :public stack
{

public:


};

void test(stack* object) {

	for (int i; i < 5; i++) {
		object->push(i);
	}
	while (!object->empty()) {

	}


}


int main() {


	return 0;
}