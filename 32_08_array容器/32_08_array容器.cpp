// 32_08_array����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <array>
#include <iostream>
using std::array;
using std::cout;
using std::endl;

int main()
{

	//��vector��ͬ���ǣ�array����ĳ����ǹ̶��ģ�ʹ���˾�̬�洢�������洢��ջ�ϣ�Ч�ʸ�������ͬ�����Ǹ��ӵİ�ȫ��
	{
		const int n = 5;
		array<int, n> arr = { 1,2,3,4 };
	}


	//array����������������ƾ��ǿ��Խ�һ��array����ֵ����һ��array����
	{
		std::array<double, 4> ad = { 1.2, 2.1, 3.1, 4.1 };
		std::array<double, 4> ad1;
		ad1 = ad;
	}



	system("pause");
    return 0;
}

