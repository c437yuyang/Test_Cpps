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

	//demo1
	{
		int a = 'A' + 1.6; //1.6ת�ͳ�1
	}


	//�޷��������з��������л�������ʱ���з��������Զ�ת�����޷�����
	{
		int n = -1;
		unsigned int i = 10;
		cout << (i < n) << endl; //true,-1ת��Ϊ�޷������󷴶���һ���ܴ��ֵ
	}

	system("pause");
    return 0;
}
