// 34_02_cout的高级用法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
int main()
{
	bool a = false;

	//指定将bool按照格式输出
	cout << a << endl; //0
	cout << boolalpha << a << endl; // false


	cout << hex << 10 << endl; //a
	cout << dec << 0x10 << endl; //16


	cout << nouppercase << "ABbcA" << endl;


    return 0;
}

