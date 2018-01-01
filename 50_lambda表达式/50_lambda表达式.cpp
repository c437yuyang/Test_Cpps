// 50_lambda���ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class CTest
{
public:
	CTest() : m_nData(20) { NULL; }
	void TestLambda()
	{
		vector<int> vctTemp;
		vctTemp.push_back(1);
		vctTemp.push_back(2);

		// �޺�����������������1 2   
		{
			for_each(vctTemp.begin(), vctTemp.end(), [](int v) { cout << v << endl; });
		}

		// ��ֵ��ʽ���������������пɼ��ľֲ�����������this���������11 12   
		{
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(), [=](int v) { cout << v + a << endl; });
		}

		// �����÷�ʽ���������������пɼ��ľֲ�����������this���������11 13 12   
		{
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(), [&](int v)mutable { cout << v + a << endl; a++; });
			cout << a << endl;
		}

		// ��ֵ��ʽ���ݾֲ�����a�������11 13 10   
		{
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(), [a](int v)mutable { cout << v + a << endl; a++; });
			cout << a << endl;
		}

		// �����÷�ʽ���ݾֲ�����a�������11 13 12   
		{
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(), [&a](int v) { cout << v + a << endl; a++; });
			cout << a << endl;
		}

		// ����this�������21 22 
		{
			for_each(vctTemp.begin(), vctTemp.end(), [this](int v) { cout << v + m_nData << endl; });
		}

		// ��b�����ô����⣬��������ֵ���ݣ������11 12 17   
		{
			int a = 10;
			int b = 15;
			for_each(vctTemp.begin(), vctTemp.end(), [=, &b](int v) { cout << v + a << endl; b++; });
			cout << b << endl;
		}
		// ���������غ������������ô��ݣ������2 3   
		{
			for_each(vctTemp.begin(), vctTemp.end(), [](int &v) { v++; });
			for_each(vctTemp.begin(), vctTemp.end(), [](int v) { cout << v << endl; });
		}
		// �յ�Lambda���ʽ   
		{
			[]() {}();    [] {}();
		}
	}
private:  int m_nData;
};
int main()
{
    return 0;
}

