// 23_02_运算符逻辑运算符优先级.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 3, b = 4, c = 5;
	int i = !(a + b) + c - 1 && b + c / 2; //&&(逻辑运算符优先级最低)

	cout << i << endl; //1

	system("pause");
    return 0;
}
