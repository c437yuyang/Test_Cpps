// 11_����ֵ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	int age;
	A(int i) :age(i) { cout << "A���캯��" << endl; }
	A(const A&a) 
	{ 
		cout << "A�������캯��" << endl;
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
	fun(a1); //���Կ���ִ�����˺�a1��age����10�����Ծ��㲻�ǻ������ͣ���Ȼ�Ǵ��ݵĸ��������ÿ������캯����
	cout << a1.age << endl;

	return 0;
}

