// 33_02_string_compare��operator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "aaab";
	string s2 = "aaaba";

	cout << s1.compare(s2) << endl; //-1�����ص���int����
	cout << (s1 < s2) << endl;//1 operator<���ص���bool����
	cout << (s1 <= s2) << endl;//1 operator<=���ص���bool����

	system("pause");
	return 0;
}

