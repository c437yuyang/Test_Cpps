// 06_��̬_����û�ж����Ա������µĲ���ɾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
//��һ�����ڳ����ﶨ��һ�º꣨���鶨����stdafx.hͷ�ļ��У�
#ifdef _DEBUG
//for memory leak check
#define _CRTDBG_MAP_ALLOC //ʹ���ɵ��ڴ�dump�����ڴ�����ľ������Ϊֹ
#include <stdlib.h> 
#include <crtdbg.h>
#define CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#endif 

//�ܽ�:���༴ʹ��û����Ҫר��д���������ĳ�Ա������£�����Ҳ������������������������ֱ��deleteָ������ĸ���ָ�뻹�ǻᱨ��

using namespace std;
class A
{
public:
	virtual void f()
	{
		printf("A\n");
	}
	//virtual void f() = 0;
	virtual ~A() {
		cout << "~A()" << endl;
	}
};

class B : public A
{
public:
	void f()
	{
		printf("B\n");
	}
	~B() {
		cout << "~B()" << endl;
	}

};

int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	A *a = new B;
	a->f();
	delete a; //ֻ�л��������������������Ż�����������������

	system("pause");
	return 0;
}
