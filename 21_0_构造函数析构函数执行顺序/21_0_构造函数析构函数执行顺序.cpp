// 21_0_���캯����������ִ��˳��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class B {
public:
	B(void)
	{
		cout << "B\t";
	}


	~B(void)
	{
		cout << "~B\t";
	}
};
struct C {
	C(void)
	{
		cout << "C\t";
	}


	~C(void)
	{
		cout << "~C\t";
	}
};
struct D : B {
	D() { cout << "D\t"; }
	~D() { cout << "~D\t"; }
private: C c;
};


int main()
{
	D d; //B C D ~D ~ C ~B


	///
// 	D�̳���B, ����Ĺ��캯����ִ�У�û�����ʡ�
// 		C��D�ĳ�Ա��������D�Ĺ��캯����ʼǰ���������г�ʼ������ִ��C�Ĺ��캯����
// 		���ִ��D�Ĺ��캯����
// 		��������ִ�е�˳���빹���෴��


	system("pause");
	return 0;
}
