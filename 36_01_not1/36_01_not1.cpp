// 36_01_not1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


// functional_not1.cpp
// compile with: /EHsc
#include <vector>
#include <functional> //not greater bind2nd
#include <algorithm>
#include <iostream>

using namespace std;
// ȡ����:negator(not)��ʹ��

#include <iostream>  
#include <vector>  
#include <functional>  
using namespace std;

//���һ�㺯����Ƶĺ��������  
bool isThree(int em)
{
	if (em == 3)
	{
		cout << em << "is 3" << endl;
		return true;
	}
	else
	{
		cout << em << "is not 3" << endl;
		return false;
	}
}

bool isElement(int em, int rem)
{
	if (em == rem)
	{
		cout << em << "is " << rem << endl;
		return true;
	}
	else
	{
		cout << em << "is not " << rem << endl;
		return false;
	}
}


int main()
{
	{
		vector<int> col1;
		for (int i = 0; i < 9; ++i)
		{
			col1.push_back(i);
		}
		for_each(col1.begin(), col1.end(), not1(ptr_fun(isThree))); //��һ�㺯��isThreeת���ɷº��� ������ֻ�ǰѷ���ֵ��ת�ˣ�����������ں����ڲ����ģ����ﷵ��ֵû�ã����Կ�����Ч�� 
		cout << endl; //not1��תһԪν�ʵ������,not2��ת2Ԫν�ʵ������
		for_each(col1.begin(), col1.end(), bind2nd(ptr_fun(isElement), 5));
	}



	{
		vector<int> v1;
		vector<int>::iterator Iter;

		int i;
		for (i = 0; i <= 7; i++)
		{
			v1.push_back(5 * i);
		}

		cout << "The vector v1 = ( ";
		for (Iter = v1.begin(); Iter != v1.end(); Iter++)
			cout << *Iter << " ";
		cout << ")" << endl;

		vector<int>::iterator::difference_type result1;
		// Count the elements greater than 10
		result1 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 10));
		cout << "The number of elements in v1 greater than 10 is: "
			<< result1 << "." << endl;

		vector<int>::iterator::difference_type result2;
		// Use the negator to count the elements less than or equal to 10
		result2 = count_if(v1.begin(), v1.end(),
			not1(bind2nd(greater<int>(), 10)));

		cout << "The number of elements in v1 not greater than 10 is: "
			<< result2 << "." << endl;
	}
	

	system("pause");
}

