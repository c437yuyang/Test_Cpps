// 12_位域对齐.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//指定位域，xyz一共占用一个字节
struct s
{
	int x : 3;
	int y : 4;
	int z : 5;
	int x1 : 3;
	int x2 : 17; //只要前面不超出一个int占得字节(32位)，就公用一个int的长度
	//所以17就输出8，18就输出12
	int num1;
};


int main()
{
	cout << sizeof(s) << endl;
	system("pause");
    return 0;
}

