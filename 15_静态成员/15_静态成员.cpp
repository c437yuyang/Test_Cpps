// 15_��̬��Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class TestStatic {
	//static const int memCount = 0; //���Ҫ�����ڽ��г�ʼ���Ļ���������Ϊ����ֵ

	static int memCount; //������Աͬ����ѭ�������ο��Ʒ���Ȩ�޿���

public:
	
	TestStatic() { memCount++; }
	~TestStatic() { memCount--; }

	//int GetMemCount() { return memCount; } //�ǳ����ĳ�Ա���Է��ʳ�����Ա����������ʵ����
	static int GetMemCount() { return memCount; } //������Ա���ܷ��ʷǳ�����Ա����Ϊ������Ա���ڷǳ�����Ա��ʼ����

};

int TestStatic::memCount = 0; //������Ա����(����)���ⲿ����(ȫ�ַ�Χ)

int main()
{
	//int TestStatic::memCount = 0; //������Ա�������ⲿ����(�����ڲ�����)

	TestStatic ts1;
	TestStatic ts2;
	TestStatic *pTs = new TestStatic;

	//cout << ts1.GetMemCount() << endl; //��ʵ������Ȼ���Է��ʳ�����Ա�����ǳ����ĳ�Ա���Է��ʳ�����Ա����������ʵ������
	cout << TestStatic::GetMemCount() << endl;
	delete pTs;
	cout << TestStatic::GetMemCount() << endl;
	system("pause");
	return 0;
}

