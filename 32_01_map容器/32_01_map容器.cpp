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

	cout << result.second << endl;//1����true
	cout << result.first->first << endl;//��ֵ
	cout << result.first->second << endl;//value

	cout << m1["aaaaa"] << endl; //ֻҪʹ�õ����±�ͻ����в���
	
	auto it = m1.find("aaaa");
	cout << (it == m1.end() ? "û�ҵ�":"�ҵ���") << endl;

	it = m1.find("aaaaa");
	cout << (it == m1.end() ? "û�ҵ�" : "�ҵ���") << endl;

	it = m1.find("aaaaa1");
	cout << (it == m1.end() ? "û�ҵ�" : "�ҵ���") << endl;

	return 0;
}

