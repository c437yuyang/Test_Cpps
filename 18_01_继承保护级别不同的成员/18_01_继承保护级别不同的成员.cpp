// 18_01_继承保护级别不同的成员.cpp : 定义控制台应用程序的入口点。
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
	a.printfInfo(); //若B不实现printInfo方法，输出都是1，可以看到 printInfo在哪个类，输出的就是哪个类的age

	system("pause");
	return 0;
}
