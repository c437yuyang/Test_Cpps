// 00_someDemos_01.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

#pragma region ����
	//float a[10], x;
//a = &x; //����ֻ���ڶ����ʱ��ֵ������������float *a����������


//int a[3][4] = {0};
//for (int i=0;i!=12;++i)
//{
//	int w1 = i / 4;
//	int w2 = i % 4;
//	a[w1][w2] = i;
//}
//int j = a[9]; //����ֱ��a[9]�����ʣ�a[9]��������*(a+9)����һ��һά�����飬�����޸�  
#pragma endregion

#pragma region ��������Ƕ�׶���
	//void printInfo() { cout << " " << endl; } //����
#pragma endregion

#pragma region ��ά����

	//int a[2][3] = { 1,2,3,4,5,6 };

	////int a1 = (&a[0] + 1)[2];
	//int *p1 = (&a[0] + 1)[1];
	//cout << *p1 << endl;
	////int *p = (&a[0] + 1); //���ʽ��������int(*)[3] ,һ��ָ�룬ָ����������Ա������
	//int a2 = *(*(a + 1) + 2);
	//int a3 = ((int *)(&a[0] + 1))[2];

#pragma endregion


#pragma region break��for������ִ��i++
	//int i;
	//for (i=0;i!=8;++i)
	//{
	//	if(i==1) break;
	//}

#pragma endregion

#pragma region i++������δ������Ϊ


	int i = 0;
	i = i++; //������һ��δ����Ϊ ��ȡ���ڱ�������ִ��i++�����˵�ǰֵ֮����Լӻ���=��

#pragma endregion




	system("pause");
	return 0;
}

