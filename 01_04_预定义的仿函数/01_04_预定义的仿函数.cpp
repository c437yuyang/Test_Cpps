// 01_04_Ԥ����ķº���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <functional>

#include <iostream>
#include <string>

int main()
{
	//std::greater<int> my_gt; //����
	//std::greater_equal<int> my_gt; //>=
	//std::logical_and<int> my_gt; // &&
	//std::negate<int> my_gt; //-
	//std::minus<int> my_gt; //a-b
	//std::multiplies<int> my_gt; //a*b

	std::hash<int> int_hash;
	std::hash<std::string> string_hash;
	std::cout << int_hash(10) << std::endl; //���ص���size_t����
	std::cout << int_hash(11) << std::endl;
	std::cout << string_hash(std::string("11")) << std::endl;
	std::cout << string_hash(std::string("12")) << std::endl; //���е��õ��˹�ϣֵ������Ĭ�϶���ʹ��hash<T>��Ϊ��hash����

	system("pause");
	return 0;
}

