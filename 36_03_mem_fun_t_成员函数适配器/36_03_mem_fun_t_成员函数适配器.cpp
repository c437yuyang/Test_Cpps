// 36_03_mem_fun_t_��Ա����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// Ex13-21.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct B
{
	virtual void print() = 0;
};
struct D1 :public B
{
	void print()
	{
		cout << "I'm a D1." << endl;
	}
	D1() {}
	D1(const D1&d1) { cout << "��������" << endl; }

};
struct D2 :public B
{
	void print()
	{
		cout << "I'm a D2." << endl;
	}
};
void main(int argc, char* argv[])
{
	vector<B*> v;
	v.push_back(new D1);
	v.push_back(new D2);
	v.push_back(new D2);
	v.push_back(new D1);
	for_each(v.begin(), v.end(), mem_fun(&B::print));//private�Ļ�Ҳ��Υ��������ֱ�ӾͲ��ܷ�����
	for_each(v.begin(), v.end(), [](B* p) { p->print(); }); //�������Ͳ�����const,��Ȼ�������const�汾��Ա��������������Ҳ���ԣ�������Բ�����ô����ˡ�

	//vector<D1> v1;
	//v1.push_back(D1());
	//v1.push_back(D1());
	//for_each(v1.begin(), v1.end(), mem_fun(&D1::print)); //����ֻ�ܴ���D1*�����ܴ��ݱ���Ķ����������Ż�����ֱ���ú�������о��� ��������ǰ��֧��lambda���ʽ��ԭ���


	//const �汾�������Ƶ�
	//mem_fun_ref ������������װ����B��������B��ָ���ʱ����
	//����mem_funת�����ĺ�����ʵ���ǻ���һ��������mem_fun�����Լ����ָ��(���Ǵ�ֵ?)��mem_fun_ref������Ķ�����(�������ð�),mem_fun_1�Ϳ���ʹ�ú��в����ĳ�Ա����
	vector<vector<int>*> v2;
	v2.push_back(new vector<int>(5));
	v2.push_back(new vector<int>(3));
	v2.push_back(new vector<int>(4));
	transform(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "), mem_fun(&vector<int>::size));
	cout << endl;

	system("pause");

}
