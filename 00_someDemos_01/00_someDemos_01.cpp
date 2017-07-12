// 00_someDemos_01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

#pragma region 数组
	//float a[10], x;
//a = &x; //数组只能在定义的时候赋值，如果定义的是float *a，才能这样


//int a[3][4] = {0};
//for (int i=0;i!=12;++i)
//{
//	int w1 = i / 4;
//	int w2 = i % 4;
//	a[w1][w2] = i;
//}
//int j = a[9]; //不能直接a[9]来访问，a[9]在这里是*(a+9)，是一个一维的数组，不可修改  
#pragma endregion

#pragma region 函数不能嵌套定义
	//void printInfo() { cout << " " << endl; } //报错
#pragma endregion




	system("pause");
	return 0;
}

