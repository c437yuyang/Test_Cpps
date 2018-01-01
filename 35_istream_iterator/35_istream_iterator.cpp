// 35_istream_iterator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


// istream_iterator_istream_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

#pragma region istream_iterator���copy��cin��������
	//// Used in conjunction with copy algorithm
	//// to put elements into a vector read from cin
	//vector<int> vec(4);
	//vector<int>::iterator Iter;

	//cout << "Enter 4 integers separated by spaces & then\n"
	//	<< " a character ( try example: '2 4 6 8 a' ): "; //istream_iterator������������ͻ�ֱ��ֹͣ������������
	//istream_iterator<int> intvecRead(cin);

	//// Default constructor will test equal to end of stream
	//// for delimiting source range of vecor
	//copy(intvecRead, istream_iterator<int>(), vec.begin()); //istream_iterator<int>()��ʾ��β
	//cin.clear();

	//cout << "vec = ";
	//for (Iter = vec.begin(); Iter != vec.end(); Iter++)
	//	cout << *Iter << " "; cout << endl;
	////�ٽ��ostream_iterator��cout���
	//copy(vec.begin(), vec.end(), ostream_iterator<int>(cout));
	//cout << endl;
	//copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
#pragma endregion

#pragma region istream_iterator���ļ���������
	
	//ifstream ifs("ints.dat");
	//istream_iterator<int> dataBegin(ifs);
	//istream_iterator<int> dataEnd;
	////vector<int> v1(dataBegin,dataEnd);
	//vector<int> v2;
	//for (auto it = dataBegin;it!=dataEnd;++it) //��ʵҲ����һ�������������Խ����ú��Լӵȵ�
	//	v2.push_back(*it);

#pragma endregion


#pragma region istream_iterator����ʹ�ý���
	istream_iterator<int> it1(cin);
	istream_iterator<int> it2;

	while (it1 != it2) //ֻ�е����벻�Ƿ���������ֵ��ʱ���ֹͣ
	{
		cout << *it1 << " ";
		it1++;
	}
	cin.clear();

	istream_iterator<string> it11(cin);
	istream_iterator<string> it21;

	while (it11 != it21) //windows����ctrl+z���ܽ�����linux��������ctrl+d
	{
		cout << *it11 << " ";
		it11++;
	}

	char ch;
	while ((ch = getchar()) != '\0') //��������ctrl+@('\0')���ܽ������������ϵͳ����һ����
	{
		cout << ch << endl;
	}


#pragma endregion


}
