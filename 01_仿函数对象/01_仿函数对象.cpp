// 01_仿函数对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//一个类如果重写了operator()的话就是仿函数
//仿函数的基类有两个:unary_function 和 binary_function
//仿函数的优点主要是速度更快(调用operator())，函数指针的调用方法涉及到指针调用因此很慢。


template<class T>
struct plus
{
	T operator()(const T&x,const T& y)
	{
		return x + y;
	}
};

//另一种做法
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
	std::cout << plus<int>() (1, 2) << std::endl; //使用临时对象

	std::cout << minus()(3, 4) << std::endl;

	system("pause");
    return 0;
}

