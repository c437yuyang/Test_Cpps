// 31_�����ƶ�_��ֵ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int &r3 = i; //��ֵ���ð󶨵����ʽ(��ֵ)��
	int &&r1 = 42; //��ֵ���ð󶨵�������������ֵ�ı��ʽ
	int &&r2 = i * 42;
	const int &r4 = 42 * i; //const��ֵ���ÿ���ָ����

	//����ǿ������ֵ���ð󶨵���ֵ��
	int &&r5 = std::move(i);

	cout << r1 << endl;

	system("pause");
    return 0;
}

