// 15_��̬��Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class TestStatic {
	//static const int memCount = 0; //���Ҫ�����ڽ��г�ʼ���Ļ���������Ϊ����ֵ,��������(ints,chars,bools)�ı�������
	//��ʵ���ﻹ������ʽ�������Ƕ���ʽ�����Ҫȡ���ĵ�ַ�Ļ����ͻ������ṩ����ʽ(���Բ���ֵ�ˣ�������ʱ�����)�������뿴effective C++ M2
	//const static double salary = 0.0; //���󣬲�������
	const static char a = 'a'; //const char ����Ҳ�������ڳ�ʼ��

	static int memCount; //��̬��Աͬ����ѭ�������ο��Ʒ���Ȩ�޿���

public:
	
	TestStatic() { memCount++; }
	~TestStatic() { memCount--; }

	//int GetMemCount() { return memCount; } //�Ǿ�̬�ĳ�Ա���Է��ʳ�����Ա����������ʵ����
	static int GetMemCount() { return memCount; } //��̬��Ա���ܷ��ʷǾ�̬��Ա����Ϊ��̬��Ա���ڷǾ�̬��Ա��ʼ����

};

int TestStatic::memCount = 0; //��̬��Ա����(����)���ⲿ����(ȫ�ַ�Χ)

int main()
{
	//int TestStatic::memCount = 0; //��̬��Ա�������ⲿ����(�����ڲ�����)

	TestStatic ts1;
	TestStatic ts2;
	TestStatic *pTs = new TestStatic;

	//cout << ts1.GetMemCount() << endl; //��ʵ������Ȼ���Է��ʾ�̬��Ա�����Ǿ�̬�ĳ�Ա���Է��ʾ�̬��Ա����������ʵ������
	cout << TestStatic::GetMemCount() << endl;
	delete pTs;
	cout << TestStatic::GetMemCount() << endl;
	system("pause");
	return 0;
}

