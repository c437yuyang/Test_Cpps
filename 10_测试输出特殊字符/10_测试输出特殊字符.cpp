// 10_������������ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
int main()
{

	//����ascii��:����ctrl+@����\0�ͻ��˳�
	//����س���\n(���з�) 10
	// ����ctrl+m ��������س�  ���õ���Ҳ��10  ��ӳ��������һ�����з�����ʵ��һ��\r���س���
	while (char c = getchar())
	{
		cout << (int)c << endl;

	}


	return 0;
}

