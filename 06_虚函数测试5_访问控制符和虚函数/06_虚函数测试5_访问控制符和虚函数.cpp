// 06_虚函数测试5_访问控制符和虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	virtual void printInfo() {
		cout << "base" << endl;
	}

private:
	void printInfo1() {
		cout << "base1" << endl;
	}


};

class Drived :public Base
{
private:
	void printInfo() {
		cout << "Drived" << endl;
	}
public:
	void printInfo1() {
		cout << "Drived1" << endl;
	}


};

int main()
{

	//结论:访问控制符与虚函数相结合的时候，不影响虚函数或者访问控制符本身的作用，是啥样就是啥样



	Base *p = new Drived;
	p->printInfo(); //父类是public，子类是private,通过这种虚函数的方式，能够调用到子类private的方法
	//p->printInfo1(); //报错，父类是private,根本不让访问


	cin
	return 0;
}

