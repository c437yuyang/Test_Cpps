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

class A1
{
	char c;
	int *pInt; //��СΪָ�룬���ֽڣ������ܹ�8
}a1;

typedef union {
	long i;
	int k[5];
	char c;
} DATE;
struct data {
	int cat;
	DATE cow;
	double dog;
	char c;
} too;


int main()
{

	cout << sizeof(A) << endl; //24
	cout << sizeof(A1) << endl; //8

	///ʵ����class A

	//int iռ4���ֽ�
	//	union Uʵ����Ϊuռȡ16���ֽڣ�char����ռ13���ֽڣ�����Ϊ�������Ϊint������ռȡֻ��Ϊ4�ֽڵ�����������С16�ֽڣ�
	//	�պ�����ռȡ�ֽ�
	//	δʵ����ָ�벻ռȡ�ֽ�
	//	ö������ռȡ4���ֽ�
	//  ָ������ռȡ4�ֽڣ�Ҳ�ܳ䵱��С��Ԫ
	//	�������ͺ������õ�����һ��

	//	�ܹ�ռȡ4 + 16 + 4 = 24���ֽ�

	cout << sizeof(DATE) << endl; //20,union�������Ԫ��Int[5]��Ϊ20���������ʱ���ǿ���С����Ԫ�صĴ�С������������ǿ�long�Ĵ�С�����ж���
	cout << sizeof(too) << endl;//40,�����ʱ���ǿ���С����Ԫ�صĴ�С��������double���Ͱ���8�ı�����
	system("pause");
    return 0;
}
