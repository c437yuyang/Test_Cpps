// 21_0_构造函数析构函数执行顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class B {
public:
	B(void)
	{
		cout << "B\t";
	}


	~B(void)
	{
		cout << "~B\t";
	}
};
struct C {
	C(void)
	{
		cout << "C\t";
	}


	~C(void)
	{
		cout << "~C\t";
	}
};
struct D : B {
	D() { cout << "D\t"; }
	~D() { cout << "~D\t"; }
private: C c;
};


int main()
{
	D d; //B C D ~D ~ C ~B


	///
// 	D继承自B, 基类的构造函数先执行，没有疑问。
// 		C是D的成员函数，在D的构造函数开始前，会对其进行初始化所以执行C的构造函数。
// 		最后执行D的构造函数。
// 		析构函数执行的顺序与构造相反。


	system("pause");
	return 0;
}
