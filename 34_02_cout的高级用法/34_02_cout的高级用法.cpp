// 34_02_cout�ĸ߼��÷�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace  std;
int main()
{
	bool a = false;

	//ָ����bool���ո�ʽ���
	cout << a << endl; //0
	cout << boolalpha << a << endl; // false


	cout << hex << 10 << endl; //a
	cout << showbase << hex << 10 << endl; //0xa
	cout << uppercase <<showbase << hex << 10 << endl; //0xA
	cout << dec << 0x10 << endl; //16
	cout << scientific << 3.14159 << endl; //3.141590e+00
	cout << fixed << 3.14159 << endl; //��������ʽ��ûɶ�仯

	

	cout << nouppercase << "ABbcA" << endl; //���Ǹ������õģ�ֻ�������ֵ����� 0x ��e ������������


	//���þ���
	double d = 3.141592768;
	cout.precision(3); //3.14
	cout << d << endl;

	system("pause");
    return 0;
}

