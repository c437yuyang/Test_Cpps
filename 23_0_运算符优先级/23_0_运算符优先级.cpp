// 23_0_��������ȼ�.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	//http://blog.csdn.net/nicky_zs/article/details/4053146
	cout << (5 > 2 > 7 > 8) << endl; //���ҵĽ�Ϸ�������0


	int x = 10;
	x += x -= x - x; //��������
	cout << x << endl; //20  
	system("pause");
	return 0;
}
