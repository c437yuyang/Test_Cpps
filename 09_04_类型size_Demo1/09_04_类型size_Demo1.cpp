// 09_04_����size_Demo1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//1�����ݳ�Ա������򣺽ṹ(struct)(������(union))�����ݳ�Ա����һ�����ݳ�Ա����offsetΪ0�ĵط���
//�Ժ�ÿ�����ݳ�Ա�洢����ʼλ��Ҫ�Ӹó�Ա��С���߳�Ա���ӳ�Ա��С
//��ֻҪ�ó�Ա���ӳ�Ա������˵�����飬�ṹ��ȣ�����������ʼ(����int�ڣ���λ��Ϊ���ֽ�, ��Ҫ�ӣ�����������ַ��ʼ�洢)
//�������Ͳ�����struct/class/uinon��

//2���ṹ����Ϊ��Ա:���һ���ṹ����ĳЩ�ṹ���Ա, ��ṹ���ԱҪ�����ڲ�"���������ͳ�Ա"����������ַ��ʼ�洢.
//(struct a�����struct b, b����char, int, double��Ԫ��, ��bӦ�ô�8����������ʼ�洢.)��
//
//3����β���� : �ṹ����ܴ�С, Ҳ����sizeof�Ľ��, .���������ڲ�����Ա��"���������ͳ�Ա"��������.�����Ҫ����.
//(�������Ͳ�����struct / class / uinon)��
//
//4��sizeof(union)���Խṹ����size���Ԫ��Ϊunion��size, ��Ϊ��ĳһʱ�̣�unionֻ��һ����Ա�����洢�ڸõ�ַ��


class A
{
	int a;
	short b;
	int c;
	char d;
};
class B
{
	double a;
	short b;
	int c;
	char d;
};


int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	cout << sizeof(int *) << endl;

	system("pause");
	return 0;
}

