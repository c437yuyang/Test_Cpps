// 32_01_map����.cpp : �������̨Ӧ�ó������ڵ㡣
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
		m1.insert(map<string, int>::value_type("aaaa", 4));//map��insert���ص���һ��pair����
	
	cout << result.second << endl;;
	cout << result.first->first << endl;

	cout << result.first->second << endl;

		return 0;
}

