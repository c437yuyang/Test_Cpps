// 24_0_����ƥ��_����ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
using namespace std;

void f1(int a) { cout << a << endl; }
void f1(float a) { cout << a << endl; }

int main()
{
	//f1(0.5); //Ĭ�ϵ�С����double���ͣ���ƥ��int��Ҳƥ��float
	
	f1(0.5f); //��ȷ

	f1(1 + 'a'); //ƥ��int
	f1('c'); //ƥ��Int

	system("pause");
    return 0;
}
