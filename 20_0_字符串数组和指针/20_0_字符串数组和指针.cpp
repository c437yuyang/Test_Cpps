// 20_0_�ַ��������ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	char *str; str = "Hello"; //ָ����Ժ�����ȥָ��
	//char str1[];  //1.�������ָ����С��2.���鲻�ܺ����ٸ�ֵ
	//str1 = "Hello"; 

	char *str2 = "Hello1"; //ָ����Ժ����ٸ�ֵ
	str2 = "hello2";
	cout << str2 << endl;

	*str2 = 'a'; //��Ȼ���벻��������ʱ��������������������
	cout << str2 << endl;

	system("pause");
    return 0;
}
