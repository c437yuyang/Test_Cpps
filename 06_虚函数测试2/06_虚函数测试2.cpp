// 06_�麯������2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << " "; }
	void test() { func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B() { test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << " ";
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	system("pause");
	return 0;
}

//�ο�:primer 556ҳ
//���캯��������������ִ����ĳ���麯����Ӧ��ִ����֮�����������Ӧ���͵��麯���汾
// �����и����򵥵����:��ʵ����testֱ�ӾͿ�����������Ҳ��һ��test����(�̳ж�����ֻ��û��д��)������test�ٵ���ʱ��
// ����Ӧ�����ǵ��������Լ���func������