// 09_01_����size(��ö�ٺ�union��).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class A
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo() {    }
	typedef char* (*f)(void*);
	enum { red, green, blue } color;
}a;

int main()
{

	cout << sizeof(A) << endl; //24

	///ʵ����class A

	//int iռ4���ֽ�
	//	union Uʵ����Ϊuռȡ16���ֽڣ�char����ռ13���ֽڣ�����Ϊ�������Ϊint������ռȡֻ��Ϊ4�ֽڵ�����������С16�ֽڣ�
	//	�պ�����ռȡ�ֽ�
	//	δʵ����ָ�벻ռȡ�ֽ�
	//	ö������ռȡ4���ֽ�

	//	�ܹ�ռȡ4 + 16 + 4 = 24���ֽ�


	system("pause");
    return 0;
}
