// 18_01_�̳б�������ͬ�ĳ�Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
private:
	
	int age = 1;
public:
	
	void printfInfo() { cout << age << endl; }
};

class B :public A {

private:
	int age = 2;

public:
	void printfInfo() { cout << age << endl; }

};


int main()
{

	B b;
	b.printfInfo();
	A a;
	a.printfInfo(); //��B��ʵ��printInfo�������������1�����Կ��� printInfo���ĸ��࣬����ľ����ĸ����age

	system("pause");
	return 0;
}
