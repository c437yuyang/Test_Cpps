// 06_多态_子类没有多余成员的情况下的部分删除.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
	void f()
	{
		printf("A\n");
	}
	//virtual ~A() {}; //添加虚析构函数就不会了
};

class B : public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};

int main()
{
	A *a = new B;
	a->f();
	delete a; //报异常了

	system("pause");
	return 0;
}
