// 33_03_string_find.cpp : �������̨Ӧ�ó������ڵ㡣
//



#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

	string s1 = "abcde";
	
	cout << (int)s1.find("bcf") << endl; //-1
	cout << (int)s1.find("f") << endl; //-1
	cout << (int)s1.rfind("def") << endl; //-1 
	cout << (int)s1.find_last_of("def") << endl; //4

	//�ܽᣬfind��rfind��Ҫ����ȫ�����ַ���������findxxxofxxxֻҪ������ַ������κ�һ���ַ���ע��of

	string s2 = "E:\\a";
	cout << (int)s2.find("\\/") << endl;
	cout << (int)s2.find_last_of("\\/") << endl;

	system("pause");
    return 0;
}

