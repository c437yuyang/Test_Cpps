// 35_02_istreambuf_iterator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ifstream ifs("test.txt");

	if (!ifs.is_open())
		return -1;
	//istreambuf_iterator���Զ���ո񣬲������κ��ַ���ע�⣬(istreambuf_iterator<char>(ifs))����������������
	string fileContent((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

	//string str;
	//copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), str.end()); //��������������ֱ��getline��


	string strWithSpace("ab c d\nf g");

	copy(strWithSpace.begin(), strWithSpace.end(), ostream_iterator<char>(cout));

	system("pause");
	return 0;
}

