// 39_01_main����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

static int time = 0;

int main()
{
	cout << "main " << endl;
	time++;
	if (time > 10) //����ͨ��static��������ȫ�ֱ���������
	{
		return 0;
	}
	main(); //������ʾ�ݹ���õ�
	return 0;
}

