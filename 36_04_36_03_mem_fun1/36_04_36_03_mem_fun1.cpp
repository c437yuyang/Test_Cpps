// Ex13-23.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct operation
{
	virtual double eval(double) = 0;
};
struct square :public operation
{
	double eval(double x)
	{
		return x*x;
	};
};
struct Negate :public operation
{
	double eval(double x)
	{
		return -x;
	}
};
struct B
{
	virtual int f(int x)const = 0;
};
struct D :public B
{
	int val;
	D(int x) :val(x)
	{


	};
	int f(int x)const
	{
		return val + x;
	};
};
void main(int argc, char* argv[])
{
	vector<operation*>operations;
	vector<double>operands;
	operations.push_back(new square);
	operations.push_back(new square);
	operations.push_back(new square);
	operations.push_back(new square);
	operations.push_back(new square);
	operands.push_back(1);
	operands.push_back(2);
	operands.push_back(3);
	operands.push_back(4);
	operands.push_back(5);
	transform(operations.begin(), operations.end(), operands.begin(),
		ostream_iterator<double>(cout, "\n"),
		mem_fun(&operation::eval)); //��Ϊmem_fun1�Ĺ��캯��������ʹ�ã����ʹ��mem_fun�Ĺ��캯���������ʵ��������mem_fun1����
	cout << endl;
	//
	vector<B*>v;
	v.push_back(new D(3));
	v.push_back(new D(4));
	v.push_back(new D(5));
	int A[3] = { 7,8,9 };
	transform(v.begin(), v.end(), A, ostream_iterator<int>(cout, " "), mem_fun(&B::f));
	cout << endl;
}

