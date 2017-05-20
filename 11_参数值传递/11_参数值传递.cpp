// 11_参数值传递.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	int age;
	A(int i) :age(i) { cout << "A构造函数" << endl; }
	A(const A&a) 
	{ 
		cout << "A拷贝构造函数" << endl;
		this->age = a.age; 
	}
};

void fun(A a) 
{
	++a.age;
	cout << a.age << endl;
}


int main()
{

	A a1(10);
	A a2(20);
	fun(a1); //可以看到执行完了后a1的age还是10，所以就算不是基本类型，依然是传递的副本（调用拷贝构造函数）
	cout << a1.age << endl;

	return 0;
}

