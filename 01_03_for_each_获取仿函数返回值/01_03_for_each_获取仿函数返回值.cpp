// 01_03_for_each_��ȡ�º�������ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;

class MeanValue
{
private:
	long num;
	long sum;
public:
	MeanValue() : num(0), sum(0)
	{
	}
	void operator() (int elem)
	{
		num++;
		sum += elem;
	}

	double value()
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

int main()
{
	vector<int> col1;
	for (int i = 1; i <= 8; ++i)
	{
		col1.push_back(i);
	}
	MeanValue mv1;
	MeanValue mv = for_each(col1.begin(), col1.end(),mv1); //for_each����һ�����󱣴��˲������ֵ
	//MeanValue mv = for_each(col1.begin(), col1.end(), MeanValue()); //���� ����һ����ʱ����
	//for_each(col1.begin(), col1.end(), MeanValue().operator()); //��������Ҳ����
	cout << mv1.value() << endl; //���Կ���mv1������û��
	cout << "Mean Value: " << mv.value() << endl;
	system("pause");
	return 0;
}