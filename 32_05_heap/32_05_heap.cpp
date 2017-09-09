// 32_05_heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>  
#include <algorithm>  
#include <vector>  
using namespace std;

int main() {
	//默认是最大堆
	int myints[] = { 10,20,30,5,15 };
	vector<int> v(myints, myints + 5);

	make_heap(v.begin(), v.end());
	cout << "initial max heap   : " << v.front() << endl;

	pop_heap(v.begin(), v.end()); v.pop_back();
	cout << "max heap after pop : " << v.front() << endl;

	v.push_back(99); push_heap(v.begin(), v.end());
	cout << "max heap after push: " << v.front() << endl;

	sort_heap(v.begin(), v.end()); //利用堆排序，从小到大输出

	cout << "final sorted range :";
	for (unsigned i = 0; i < v.size(); i++) cout << " " << v[i];

	cout << endl;

	return 0;
}