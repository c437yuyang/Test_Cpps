// 12_λ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//ָ��λ��xyzһ��ռ��һ���ֽ�
struct s
{
	int x : 3;
	int y : 4;
	int z : 5;
	int x1 : 3;
	int x2 : 17; //ֻҪǰ�治����һ��intռ���ֽ�(32λ)���͹���һ��int�ĳ���
	//����17�����8��18�����12
	int num1;
};


int main()
{
	cout << sizeof(s) << endl;
	system("pause");
    return 0;
}

