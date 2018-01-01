// 32_03_vector����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <windows.h>
using namespace std;



#pragma region ���ֱ�����ʽ
typedef vector<int> vInt;
void traverse_vec_operator(const vInt & v)//����һ�������±����
{
	int i;
	int j;
	for (i = 0; i < v.size(); i++)
	{
		j = v[i];
	}
}

void traverse_vec_at(const vInt & v)//����һ�������±����
{
	int i;
	int j;
	for (i = 0; i < v.size(); i++)
	{
		j = v.at(i);
	}
}

void traverse_vec_iterator(const vInt &v)//�����������õ���������
{
	int i;
	for (vInt::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		i = *iter;
	}
}

void traverse_vec_iterator_no_end(const vInt &v)//�����������õ���������,������ǰ���ú�end
{
	auto end = v.end();
	int i;
	for (vInt::const_iterator iter = v.begin(); iter != end; iter++)
	{
		i = *iter;
	}
}

void traverse_vec_algorithm(const vInt &v)//�������������������ݸ��Ƶ�cout�󶨵ĵ�����
{
	int i = 0;
	for_each(v.begin(), v.end(), [&](int val) {i = val; });
}

class AAA
{
public:
	void MakeFull2()
	{
	}
};


#pragma endregion



class A {
public:
	A(int i1) :i(i1) {};
	int i;

	bool operator==(const A&rhs) const //������const�汾��const ��Ա��������!!!!!
	{
		return this->i == rhs.i;
	}
};



int main()
{

#pragma region vector�����Աʱ�ڴ����ʾ��
	//����:����������ʱ�������µĲŻ���������
	//����������ʱ(VS��С��3����ʱ��)��ÿ�ζ���1������VS����ÿ�������ӵ�ǰ������һ��
	//��mingw������ÿ�����ӵ�ǰ����һ����С
	vector<int> v;
	cout << "��ʼ����:" << v.size() << "," << v.capacity() << endl; //0,0
	for (int i = 0; i != 20; ++i)
	{
		v.push_back(1);
		cout << "����1��:" << v.size() << "," << v.capacity() << endl; //0,0
	}

#pragma endregion

#pragma region vetor�ж���ȣ���ʵ<����������Ҳ��һ���ĵ���
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 1,2,3,4,5 };

	for (auto it = vec1.begin(); it != vec1.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << (vec1 == vec2) << endl; //���Կ�������ȵ�



	vector<string> vec3 = { string("aaa"),string("bbb"),string("ccc") };
	vector<string> vec4 = { string("aaa"),string("bbb"),string("ccc") };
	for (auto it = vec3.begin(); it != vec3.end(); ++it)
	{
		cout << (*it).c_str() << endl;
	}
	cout << (vec3 == vec4) << endl; //���Կ�������ȵ�

	cout << (string("s1") == string("s1")) << endl; //���
	cout << (string("s1").compare(string("s1"))) << endl;//���0����ʾ���


	vector<A> vec5 = { A(1),A(2),A(3) };
	vector<A> vec6 = { A(1),A(2),A(3) };

	cout << (vec5 == vec6) << endl; //ֱ���޷����У�û�и�д==
#pragma endregion

#pragma region ��ȷ�ͷ�vector���ڴ�
	{
		//vector<T>��clear�󣬲�Ӱ��capacity,Ҫͬʱ���capacityӦ��:
		vector<string> v;
		v.push_back("aa");
		v.push_back("bb");
		v.clear();
		vector<string>(v).swap(v);
	}



#pragma endregion

	//vector��������Ч�ʲ���
	//debugģʽ��:�ӿ쵽��:at��for_each��opertor[]��iterator_no_end��iterator
	//releaseģʽ����ֱ�Ӹ��Ż��ˣ��жϵ������û��������������忴������֪��
	{
		int nCount = 1000000;
		std::vector< int > vAAA(nCount,1);

		// ʱ��
		int start, end;


		start = GetTickCount();
		size_t count = vAAA.size();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_operator(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_at(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;


		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_iterator(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_iterator_no_end(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;


		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_algorithm(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

	}

	system("pause");
	return 0;
}

