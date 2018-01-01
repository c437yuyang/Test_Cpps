// 01_�º�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

//һ���������д��operator()�Ļ����Ƿº���
//�º����Ļ���������:unary_function �� binary_function
//�º������ŵ���Ҫ���ٶȸ���(����operator())������ָ��ĵ��÷����漰��ָ�������˺�����


template<class T>
struct plus
{
	T operator()(const T&x,const T& y)
	{
		return x + y;
	}
};

//��һ������
struct minus
{
	template<class T>
	T operator()(const T&x, const T&y)
	{
		return x - y;
	}
};


int main()
{
	plus<int> plusObj;
	std::cout << plusObj(1, 2) << std::endl;
	std::cout << plus<int>() (1, 2) << std::endl; //ʹ����ʱ����

	std::cout << minus()(3, 4) << std::endl;

	system("pause");
    return 0;
}

