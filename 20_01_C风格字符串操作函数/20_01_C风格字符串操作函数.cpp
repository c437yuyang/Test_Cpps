// 20_01_C����ַ�����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	char *s1 = "abcde";
	char s2[] = "aaaaaaa";


	strcpy(s2, s1); //������ȥ���󣬻��ں������\0

	char s3[10] = "z\0zzzzz";

	strcat(s3, s1); //strcat ���ַ������ӵ���һ���ַ����׸�\0��λ��,������ɺ󣬻���������\0����ʵ��Ҳ���Ǽ���\0����Ϊ��str2����������\0

	cout << s1 << endl;
	cout << s3 << endl;
	system("pause");
    return 0;
}

