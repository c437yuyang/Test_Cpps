// 06_��̬_����û�ж����Ա������µĲ���ɾ��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//virtual ~A() {}; //��������������Ͳ�����
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
	delete a; //���쳣��

	system("pause");
	return 0;
}
