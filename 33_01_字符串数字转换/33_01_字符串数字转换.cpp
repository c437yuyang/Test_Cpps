// 33_01_字符串数字转换.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	char a[10], b[10];
	_itoa_s(21, a,10);
	_itoa_s(21, b, 2);

	char *d;
	d=itoa(10, a, 10);

	cout << a << endl;//21
	cout << b << endl;//01011
	return 0;
}