// 30_01����vector_emplace��push.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Widget {
public:
	Widget() { cout << "����" << endl; }
	Widget(const Widget& w) { m = w.m; cout << "��������" << endl; }
	//Widget(Widget&& w) noexcept { m = w.m; cout << "�ƶ�����" << endl; }
	int m;
};

int main()
{
	Widget d1;

	vector<Widget> vec;
	vec.push_back(d1);//��������
	vec.push_back((Widget&&)d1);//�ƶ�����


	vector<Widget> vec1;
	vec1.emplace_back(d1);//��������
	vec1.emplace_back((Widget&&)d1); //�ƶ�����


	Widget d2 = std::move(d1);

	//û��ô������
	vec[0].m = 11;
	cout << d1.m << endl;

	Widget *pd = nullptr;
	delete pd;

    return 0;
}

