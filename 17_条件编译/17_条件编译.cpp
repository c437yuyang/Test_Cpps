// 17_��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define condition1 0

int main()
{

	cout << condition1 << endl;

#if condition1 //ֻ��condition1��ֵΪ�߼����ʱ��Ż�ִ�������
	cout << "condition1" << endl;
#endif

#if condition1==0 //condition1��ֵΪ�߼��ٵ�ʱ��
	cout << "condition1 ��" << endl;
#else				//condition1��ֵΪ�߼����ʱ��
	cout << "condition1 ��" << endl;
#endif


#ifdef condition1
	cout << "condition1 is defined" << endl;
#endif // condition1


#ifndef condition1
	cout << "condition1 is not defined" << endl;
#endif // !condition1




	system("pause");
    return 0;
}
