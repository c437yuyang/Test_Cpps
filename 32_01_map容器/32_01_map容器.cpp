// 32_01_map容器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <map>
#include <iostream>
#include <string>
using namespace std;


int main()
{

	map<string, int> m1 = {
		map<string, int>::value_type("aa",2),
		map<string, int>::value_type("aaa",3)
	};

	cout << m1["aa"] << endl;

	pair<map<string, int>::iterator, bool> result =
		m1.insert(map<string, int>::value_type("aaaa", 4));//map的insert返回的是一个pair类型

	cout << result.second << endl;//1，即true
	cout << result.first->first << endl;//键值
	cout << result.first->second << endl;//value

	cout << m1["aaaaa"] << endl; //只要使用到了下标就会自行插入
	
	auto it = m1.find("aaaa");
	cout << (it == m1.end() ? "没找到":"找到了") << endl;

	it = m1.find("aaaaa");
	cout << (it == m1.end() ? "没找到" : "找到了") << endl;

	it = m1.find("aaaaa1");
	cout << (it == m1.end() ? "没找到" : "找到了") << endl;

	return 0;
}

