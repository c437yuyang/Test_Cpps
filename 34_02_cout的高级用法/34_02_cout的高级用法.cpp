// 34_02_cout�ĸ߼��÷�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
int main()
{
	bool a = false;

	//ָ����bool���ո�ʽ���
	cout << a << endl; //0
	cout << boolalpha << a << endl; // false


	cout << hex << 10 << endl; //a
	cout << dec << 0x10 << endl; //16


	cout << nouppercase << "ABbcA" << endl;


    return 0;
}

