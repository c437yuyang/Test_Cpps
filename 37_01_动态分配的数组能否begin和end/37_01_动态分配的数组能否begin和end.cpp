// 37_01_��̬����������ܷ�begin��end.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{

	int *p = new int[20]();
	int p1[] = { 1,2,34,445 };

	auto it = begin(p); //������������
	auto it1 = begin(p1); //ջ�ϵ�����ſ���


	system("pause");
    return 0;
}

