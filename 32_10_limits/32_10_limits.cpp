// 32_10_limits.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <limits.h>
#include <iostream>
int main()
{

	std::cout << std::numeric_limits<short>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;

	std::cout <<std::boolalpha<< std::numeric_limits<int>::is_signed << std::endl;


	system("pause");
    return 0;
}

