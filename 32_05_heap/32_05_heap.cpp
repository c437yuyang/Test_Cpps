// 32_05_heap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>  
#include <algorithm>  //make_heap��
#include <vector>  
using namespace std;

bool PredFunc(int val1, int val2)
{
	//return val1 < val2; //Ĭ�Ͼ�����������������ѣ�stl����ܶ�������Ƿ���
	return val1 > val2; //��С��
}

int main()
{


	{



		//Ĭ��������
		int myints[] = { 10,20,30,5,15 };
		vector<int> v(myints, myints + 5);

		make_heap(v.begin(), v.end(), PredFunc); //make_heap�൱��build_heap(����heapify,heapify�Ǳ�֤�������������Ƕѵ������)
		cout << "initial max heap   : " << v.front() << endl;
		
		pop_heap(v.begin(), v.end(), PredFunc); v.pop_back(); //pop_heap �ѶѶ�Ԫ���ƶ�����β,֮�����Լ�pop_back���ɡ�
		cout << "max heap after pop : " << v.front() << endl;

		v.push_back(99); push_heap(v.begin(), v.end(),PredFunc); //��push_back,��push_heap,�൱��heap_insert(ֻ����ĩβ)
		cout << "max heap after push: " << v.front() << endl;

		sort_heap(v.begin(), v.end(),PredFunc); //���ö������������Ǵ�С������С�Ѿ��ǴӴ�С

		cout << "final sorted range :";
		for (unsigned i = 0; i < v.size(); i++) 
			cout << " " << v[i];

		cout << endl;

	}

	{
		std::vector<int> foo{ 9,5,2,6,4,1,3,8,7 };

		if (!std::is_heap(foo.begin(), foo.end()))
			std::make_heap(foo.begin(), foo.end());

		cout << "after make heap:" << endl;
		for (int i = 0; i != foo.size(); ++i)
		{
			cout << foo[i] << " ";
		}
		cout << endl;

		std::cout << "Popping out elements:";
		while (!foo.empty()) {
			std::pop_heap(foo.begin(), foo.end());   // moves largest element to back
			std::cout << ' ' << foo.back();         // prints back
			foo.pop_back();                         // pops element out of container
		}
		std::cout << '\n';
	}

	return 0;
}