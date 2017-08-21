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

#pragma region 二维数组

	//int a[2][3] = { 1,2,3,4,5,6 };

	////int a1 = (&a[0] + 1)[2];
	//int *p1 = (&a[0] + 1)[1];
	//cout << *p1 << endl;
	////int *p = (&a[0] + 1); //表达式的类型是int(*)[3] ,一个指针，指向有三个成员的数组
	//int a2 = *(*(a + 1) + 2);
	//int a3 = ((int *)(&a[0] + 1))[2];

#pragma endregion


#pragma region break后for不会再执行i++
	//int i;
	//for (i=0;i!=8;++i)
	//{
	//	if(i==1) break;
	//}

#pragma endregion

#pragma region i++带来的未定义行为


	int i = 0;
	i = i++; //这里是一个未定行为 ，取决于编译器先执行i++返回了当前值之后的自加还是=号

#pragma endregion




	system("pause");
	return 0;
}

