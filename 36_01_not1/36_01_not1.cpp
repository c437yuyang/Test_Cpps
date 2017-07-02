// 36_01_not1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// functional_not1.cpp
// compile with: /EHsc
#include <vector>
#include <functional> //not greater bind2nd
#include <algorithm>
#include <iostream>

using namespace std;

int main()
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

	system("pause");
}

