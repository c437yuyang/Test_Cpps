// 18_继承关系.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;


class Base {

public:
	int p1 = 20;

protected:
	int b1 = 10;
};


class Derived :public Base
{


};


class Derived1 :public Derived
{
public:
	//从这里看出，继承关系可以延续，派生类的子类仍然可以访问基类的protected成员
	void printInfo() { cout << b1 << endl; }//（只能在类内访问，不能通过对象访问）

};


int main()
{
	Derived d;
	Derived1 d1;
	
	cout << d.p1 << endl;
	cout << d1.p1 << endl;

	d1.printInfo();
	
	//cout << d.b1 << endl; //protected不能访问？？？（只能在类内访问，不能通过对象访问）
	//cout << d1.b1 << endl;

	system("pause");
	return 0;
}
