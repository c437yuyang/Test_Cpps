// 14_02_�����ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	{
		int a[3][2] = { 1,2,3,4,5,6, };
		a[0] + 1;//����a[0][1]
		a + 1;//a[1]
	}

	{
		int a[3][2] = { 1,2,3,4,5,6, }, *p[3];
		p[0] = a[1];
		*(p[0] + 1); //����a[1][1]
	}

	{
		char a['10'];
	}
	{
#define size 10
		char str1[size], str2[size + 2];
	}

    return 0;
}

