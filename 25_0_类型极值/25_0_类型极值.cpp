// 25_0_���ͼ�ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	short s1 = 65537; //short����ʾ65535,65536����0,65537����1

	cout << s1 << endl; //1

	short s2 = 65535; //65535������λȫ��Ϊ1
	cout << s2 << endl; //�����ʱ�򣬱�����֪����Ϊ��signed���ͣ����Ե�һλ������λ�����-1

	unsigned short s3 = 65535;
	cout << s3 << endl; //65535

	system("pause");
    return 0;
}
