// 27_01_ʱ�亯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <windows.h>
int main()
{
	time_t t;
	time_t time1;
	t = clock();//���Ǹó������������������ռ��CPU��ʱ��
	time(&time1); //Ϊ��ȡϵͳʱ��
	localtime(&time1);  //��һ��UTCʱ��תΪ����ʱ��

	GetTickCount();

	system("pause");
    return 0;
}

