// 01_04_预定义的仿函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <functional>

#include <iostream>
#include <string>

int main()
{
	//std::greater<int> my_gt; //大于
	//std::greater_equal<int> my_gt; //>=
	//std::logical_and<int> my_gt; // &&
	//std::negate<int> my_gt; //-
	//std::minus<int> my_gt; //a-b
	//std::multiplies<int> my_gt; //a*b

	std::hash<int> int_hash;
	std::hash<std::string> string_hash;
	std::cout << int_hash(10) << std::endl; //返回的是size_t类型
	std::cout << int_hash(11) << std::endl;
	std::cout << string_hash(std::string("11")) << std::endl;
	std::cout << string_hash(std::string("12")) << std::endl; //所有的用到了哈希值的容器默认都是使用hash<T>作为其hash函数

	system("pause");
	return 0;
}

