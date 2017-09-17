// 32_01_map����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main()
{

	map<string, int> m1 = { //��ֵ�б���ʽ
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


	//unordered�汾ʹ��
	unordered_map<string, int> table = {
		unordered_map<string, int>::value_type("aa",1),
		unordered_map<string, int>::value_type("bb",2),
		unordered_map<string, int>::value_type("cc",3),
		unordered_map<string, int>::value_type("dd",4)
	};


	for_each(table.begin(), table.end(), [](const unordered_map<string, int>::value_type& val) {cout << val.first << "-" << val.second << endl; });



	return 0;
}

