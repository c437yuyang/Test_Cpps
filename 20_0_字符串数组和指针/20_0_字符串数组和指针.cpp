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

	//*str2 = 'a'; //��Ȼ���벻��������ʱ��������������������
	cout << str2 << endl;


	char str3[10] = "aaaa";
	char str3_1[10] = { "aaaa" }; //���ߵȼ�


	char *str4 = "hello"; 
	char *str5 = "hello";
	cout << (str4 == str5) << endl; //1
	cout << ("hello" == "hello") << endl;//1 ˵�������ǹ̶�λ�õ�


	char str6[] = "hello";
	str6++; //ֱ�ӱ����ˣ������ǲ�����ı�ָ��ֵ�ģ�Ĭ���ǳ���ָ��
	str[1] = 'a'; //�����ǿ��Ե�

	system("pause");
	return 0;
}
