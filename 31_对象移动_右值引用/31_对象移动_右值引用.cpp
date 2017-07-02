// 31_对象移动_右值引用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int &r3 = i; //左值引用绑定到表达式(左值)上
	int &&r1 = 42; //右值引用绑定到常量，返回右值的表达式
	int &&r2 = i * 42;
	const int &r4 = 42 * i; //const左值引用可以指向常量

	//可以强制让右值引用绑定到左值上
	int &&r5 = std::move(i);

	cout << r1 << endl;

	system("pause");
    return 0;
}

