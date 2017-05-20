// 25_0_类型极值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	short s1 = 65537; //short最大表示65535,65536就是0,65537就是1

	cout << s1 << endl; //1

	short s2 = 65535; //65535是所有位全部为1
	cout << s2 << endl; //输出的时候，编译器知道认为是signed类型，所以第一位当符号位，输出-1

	unsigned short s3 = 65535;
	cout << s3 << endl; //65535

	system("pause");
    return 0;
}
