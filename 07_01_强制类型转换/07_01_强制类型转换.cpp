// 07_01_ǿ������ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget
{
public:
	int _val = 1;
	operator int()// ���붨������������ܹ�ǿ��ת������ʽת���Ļ�������һ����explicit�Ĺ��캯��������һ��int���͵Ĳ���
	{
		return _val;
	}
};

int main()
{
	Widget w;
	int i = static_cast<int>(w);
	cout << i << endl;


    return 0;
}

