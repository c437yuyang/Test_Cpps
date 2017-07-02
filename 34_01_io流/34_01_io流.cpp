// 34_01_io流.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	string temp;
	char c[10];
	cin.getline(&c[0], 5, 'g'); //指定接受5-1个字符，因为最后一个是\0


	system("pause");
	return 0;
}

