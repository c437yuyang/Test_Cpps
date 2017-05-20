// 24_0_参数匹配_类型转换.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;

void f1(int a) { cout << a << endl; }
void f1(float a) { cout << a << endl; }

int main()
{
	//f1(0.5); //默认的小数是double类型，既匹配int，也匹配float
	
	f1(0.5f); //正确

	f1(1 + 'a'); //匹配int
	f1('c'); //匹配Int

	system("pause");
    return 0;
}
