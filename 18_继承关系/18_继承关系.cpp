// 18_�̳й�ϵ.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�����￴�����̳й�ϵ�����������������������Ȼ���Է��ʻ����protected��Ա
	void printInfo() { cout << b1 << endl; }//��ֻ�������ڷ��ʣ�����ͨ��������ʣ�

};


int main()
{
	Derived d;
	Derived1 d1;
	
	cout << d.p1 << endl;
	cout << d1.p1 << endl;

	d1.printInfo();
	
	//cout << d.b1 << endl; //protected���ܷ��ʣ�������ֻ�������ڷ��ʣ�����ͨ��������ʣ�
	//cout << d1.b1 << endl;

	system("pause");
	return 0;
}
