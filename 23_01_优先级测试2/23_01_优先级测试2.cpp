// 23_01_优先级测试2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
int main()
{
	struct t
	{
		int x; int *y;
	}*p;
	int a[] = { 1,2 };
	int b[] = { 3,4 };
	struct t c[2] = { 5,a,6,b };
	p = c;
	printf("%d,%d", *(p->y), ++(*p).x); //() > . > ++
	return 0;
}


