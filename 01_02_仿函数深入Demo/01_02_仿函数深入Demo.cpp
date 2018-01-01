#include "stdafx.h"
#include <iostream>  
#include <list>  
#include <algorithm>  
#include <iterator>

using namespace std;

void PRINT_ELEMENTS(list<int>& lt)
{
	list<int>::iterator it;
	for (it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << " , ";
	}
	cout << endl;
}

class IntSequence
{
private:
	int value;
public:
	IntSequence(int initValue) : value(initValue)
	{
	}

	int operator()()
	{
		return value++;
	}
};

int main()
{
	//��ֵ������
	{
		list<int> col;
		IntSequence seq(1);
		generate_n(back_inserter(col), 4, seq); //Ĭ���Ǵ�ֵ�ģ���˲���ı�º�����״̬����������������Ǵ�1��ʼ
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, IntSequence(42));
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, seq); //���Կ���������� 1 2 3 4
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, seq);
		PRINT_ELEMENTS(col);
	}


	//�����õ�����
	{
		list<int> col1;
		IntSequence seq(1);
		//������������  
		generate_n<back_insert_iterator<list<int>>, int, IntSequence&>(
			back_inserter(col1),
			4,
			seq);
		//1 2 3 4;  
		PRINT_ELEMENTS(col1);

		//�൱�����¹���һ�������42��ʼ����4��Ԫ��  
		generate_n(back_inserter(col1),
			4,
			IntSequence(42));
		//1 2 3 4; 42 43 44 45   
		PRINT_ELEMENTS(col1);

		//ǰ��ʹ�õ����������ͣ�����seq���ڲ�״̬�Ѿ����ı���  
		//��ֵ���ϴ���ɺ��5��ʼ  
		//ע�⣺��ε�����Ȼʹ�õ��Ǵ�ֵ����  
		generate_n(back_inserter(col1),
			4,
			seq);
		//1 2 3 4; 42 43 44 45; 5 6 7 8   
		PRINT_ELEMENTS(col1);

		//��һ�ε���ʹ�õ��Ǵ�ֵ���ͣ�������λ��Ǵ�5��ʼ��ֵ      
		generate_n(back_inserter(col1),
			4,
			seq);
		//1 2 3 4; 42 43 44 45; 5 6 7 8; 5 6 7 8             
		PRINT_ELEMENTS(col1);
	}


	system("pause");
	return 0;
}
