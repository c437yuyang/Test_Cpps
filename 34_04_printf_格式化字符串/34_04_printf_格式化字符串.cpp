// 34_04_printf_��ʽ���ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

//  C:scanf("%f%3o", &a, &b); ����%f��Ӧ&a��ûɶ���ʣ��ؼ��� % 3o�� % 3o�ǽ���3λ�˽�����������˼����&bƥ�䣬������ȷ��
//	A����scanf()������ָ�����ȣ������Ʒ�%6.2fΥ��������涨��
//	B����%n������Ʒ���ɶ��˼��û��������Ʒ���
//	D���ڰ��޷��ű����Ŀ��Ʒ�д��float�������Ʒ��ˡ�scanf()�������޷�����ʱֻ����%d��%ld�����Ʒ���
	//B�е�%n��ʾ������ַ��ĸ��������޷�������ʾ
	unsigned int n = -1;
	scanf("%n", &n); 
	cout << n << endl; //0

	int i; char c;
	scanf("%d%c%n", &i,&c,&n); //����%n���÷���������ȷ�����������˼��������������������룬������argv���÷�
	cout << n << endl; //0

	printf("%5s", "abcdefg"); //%5s�ǲ���5λ��ǰ���ո񣬳���5λ��ʵ�ʴ�С���
	
	//demo
	{
		char ch = -1;
		printf(" % 02x, % 02x", ch, (unsigned char)ch); //ffffffff,ff.%x���ǰ������������ģ����������Ȳ�λ������

	}

	//��������ʽ��������������������Ӱ��
	{
		char ch = 'a';int k = 12; 
		printf("%x,%o,", ch, ch, k); //����kֱ�ӱ����ԣ�����Ӱ�����
		printf("k=%%d\n", k);
	}

	system("pause");
    return 0;
}

