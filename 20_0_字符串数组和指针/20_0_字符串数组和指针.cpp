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
	//str6++; //ֱ�ӱ����ˣ������ǲ�����ı�ָ��ֵ�ģ�Ĭ���ǳ���ָ��
	str6[1] = 'a'; //�����ǿ��Ե�


	{
		char ca[3][5] = { "A", "BB", "CCC" }; //ÿ���������С����1
		char ca1[][5] = { "A", "BB", "CCC" }; //��СΪ3�Ķ�ά����
		char ca3[4][5] = { "A", "BB", "CCC" }; //��СΪ4�Ķ�ά���飬���һ����
		char *ca2[3] = { "A", "BB", "CCC" }; //���ǺϷ�������
	}

	//ifelse��֧����
	{
		int k1, k2, k3,x;
		k1 = 1;
		k2 = 2;
		k3 = 3;
		x = 15;
		if (!k1) //��֧���ÿһ����ͬ�ȵģ�����һ���Ͳ����ٽ�ͬһ���ķ�֧������������ֱ���ߵ�else if��û������else��
			x--;
		else if (k2) 
			x = 4;
		else 
			x = 3;

	}

	system("pause");
	return 0;
}
