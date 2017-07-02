// 30_01容器vector_emplace和push.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Widget {
public:
	Widget() { cout << "构造" << endl; }
	Widget(const Widget& w) { m = w.m; cout << "拷贝构造" << endl; }
	//Widget(Widget&& w) noexcept { m = w.m; cout << "移动构造" << endl; }
	int m;
};

int main()
{
	Widget d1;

	vector<Widget> vec;
	vec.push_back(d1);//拷贝构造
	vec.push_back((Widget&&)d1);//移动构造


	vector<Widget> vec1;
	vec1.emplace_back(d1);//拷贝构造
	vec1.emplace_back((Widget&&)d1); //移动构造


	Widget d2 = std::move(d1);

	//没怎么看明白
	vec[0].m = 11;
	cout << d1.m << endl;

	Widget *pd = nullptr;
	delete pd;

    return 0;
}

