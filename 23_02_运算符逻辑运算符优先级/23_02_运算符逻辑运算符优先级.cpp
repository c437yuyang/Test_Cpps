// 23_02_������߼���������ȼ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 3, b = 4, c = 5;
	int i = !(a + b) + c - 1 && b + c / 2; //&&(�߼���������ȼ����)

	cout << i << endl; //1

	system("pause");
    return 0;
}
