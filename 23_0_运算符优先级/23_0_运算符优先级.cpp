// 23_0_运算符优先级.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	//http://blog.csdn.net/nicky_zs/article/details/4053146
	cout << (5 > 2 > 7 > 8) << endl; //左到右的结合方向，所以0

	system("pause");
	return 0;
}
