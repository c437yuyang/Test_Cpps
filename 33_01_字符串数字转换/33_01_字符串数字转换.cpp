// 33_01_�ַ�������ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


template<class T>
std::string Value2String(const T& val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
T String2Value(const std::string &str)
{
	return String2Value(str.c_str());
}

template<class T>
T String2Value(const char * str)
{
	std::istringstream iss(str);
	T res;
	iss >> res;
	return res;
}


int main()
{
	char a[10], b[10];
	_itoa_s(21, a, 10);
	_itoa_s(21, b, 2);

	char *d;
	//d = _itoa(10, a, 10);

	cout << a << endl;//21
	cout << b << endl;//01011


	//����ת�����ַ���,itoa,sprintf,stringstream,to_string
	char buf[10];
	//sprintf(buf, "%d", 20);
	//cout << buf << endl;

	//�ַ���ת��������:stringstream,atoi,stoi(stof,stod)
	size_t size = 10;

	cout << stof(string("1.35"), &size) << endl;// ��򵥵�ֱ�Ӳ�Ҫ�ڶ�������,Ĭ��size��0

	cout << stoi("01111", &size, 2) << endl; //stoi��������������,stof����

	cout << Value2String(1.25) << endl;

	cout << String2Value<float>("1.25") << endl;

	return 0;
}