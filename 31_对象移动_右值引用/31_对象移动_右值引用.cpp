// 31_�����ƶ�_��ֵ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void f(int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }




int main()
{
	int i = 1;
	int &r3 = i; //��ֵ���ð󶨵����ʽ(��ֵ)��
	int &&r1 = 42; //��ֵ���ð󶨵�������������ֵ�ı��ʽ
	int &&r2 = i * 42;
	const int &r4 = 42 * i; //const��ֵ���ÿ���ָ����

	//����ǿ������ֵ���ð󶨵���ֵ��
	int &&r5 = std::move(i);

	cout << r1 << endl;

	{
		//http://blog.csdn.net/wangshubo1989/article/details/49745781
		int i = 77;
		f(i);    // lvalue ref called
		f(99);   // rvalue ref called

		f(std::move(i));  // ��ʽ������ֵ�汾
		//���һ�����ʽ�Ľ����һ����ʱ�Ķ�����ô������ʽ������ֵ
		//��:
		vector<string> v;
		v.push_back(string("aa")); //���������ʱ����string("aa")������ֵ�ģ����õ�push_backҲ����ֵ�汾��
	}

	

	system("pause");
    return 0;
}

