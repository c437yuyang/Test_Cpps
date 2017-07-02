// 06_�麯������4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	Base(int j) : i(j) {}
	virtual~Base() {}
	void func1() {
		i *= 10;
		func2();
	}
	int getValue() {
		return  i;
	}
protected:
	virtual void func2() {
		i++;
	}
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) : Base(j) {}
	void func1() {
		i *= 100;
		func2();
	}
protected:
	void func2() {
		i += 2;
	}
};
int main() {
	Base * pb = new Child(1);
	pb->func1(); //func1()�����麯�������Ե��ø����func1()
	//func1()�������func2()������func2()���麯�������Ծ͵��������func2��
	cout << pb->getValue() << endl; delete pb;
}

