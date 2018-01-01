// 32_09_�����㷨���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric> //accumulate
#include <iterator> //back_inserter
#include <deque>
using namespace std;
bool isBigger(int a, int b) { return a > b; }
int main()
{


#pragma region find
	vector<int> v = { 1,2,3,4,556,1,1,2,1 };

	//����find�ҵ�����ָ��Ԫ��Index
	auto it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find(it, v.cend(), 1); //find���ص�һ��=1�ĵ�����
		cout << (it - v.cbegin()) << endl;
		it++;
	}
#pragma endregion
	//find_if
	it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find_if(it, v.cend(), [](int i) { return i >= 2 && i <= 3; }); //find_if���ص�һ�����������ĵ�����
		cout << (it - v.cbegin()) << endl;
		if (it == v.cend()) break;
		it++;
	}


	//count
	cout << count(v.begin(), v.end(), 1) << endl; //4

												  //accumulate
	cout << accumulate(v.begin(), v.end(), 0) << endl; //��ʼֵ0���������ɼ�
	vector<string> v1 = { "a","b","c" };
	cout << accumulate(v1.begin(), v1.end(), string("")) << endl; //��ֵһ��Ҫ�Ƕ���Ȼ����ֵ���ܼ�

																  //equal(��ָ����pred�������������ָ�������Ƿ����)
	vector<int> v2 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	cout << equal(v.cbegin(), v.cend(), v2.cbegin(), [](int i1, int i2) { return i1 == i2; }) << endl; //���1����ǰһ������ȵ�

																									   //fill��fill_n
	fill(v2.begin(), v2.end(), 0); //�ϵ�鿴
	fill_n(v2.begin(), 2, 1); //��begin()��������ֵ��Ϊ1

							  //generate,�൱����fill��Ĺ̶�ֵ�������Լ��ɿ��Ƶĺ���������
	{
		vector<int> ivec1(10);
		int i = 0;
		generate(ivec1.begin(), ivec1.end(), [&i]() { return ++i; });
		for_each(ivec1.begin(), ivec1.end(), [](int a) { cout << a << "|"; });
		generate_n(ivec1.begin(), 2, [&i]() { return (++i)*(++i); });
		cout << endl;
		for_each(ivec1.begin(), ivec1.end(), [](int a) { cout << a << "|"; });

	}

	//back_inserter
	vector<int> v3; //������
					//fill_n(v3.begin(), 10, 0); //ֱ��fill�ᱨ��
	fill_n(back_inserter(v3), 10, 0); //


									  //copy �� copy_if
	vector<int> v4, v4_1;
	copy(v3.cbegin(), v3.cend(), back_inserter(v4)); //���ؿ�����ȥ�����һ��Ԫ�صĺ���
	v3[1] = 5; v3[2] = 6; v3[7] = 10;
	copy_if(v3.begin(), v3.end(), back_inserter(v4_1), [](int i) { return i >= 5; });

	//transform ��һ�������ƶ�����һ������ȥ���ڼ���Խ��б任�����Ǻ�copy��ͬ�ĵط�
	//����ʵ���ַ����Ĵ�Сдת��(��׼���stringû���ṩת��)
	string s1 = "AbC";
	string s2;
	transform(s1.begin(), s1.end(), back_inserter(s2), ::tolower); //ע��string��vectorһ����û����Ͳ���ʹ�ã�Ҳ��ʹ��inserter����


																   //replace
	vector<int> v5 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	replace(v5.begin(), v5.end(), 1, 11); //�滻����1Ϊ11
										  //replace_if()

										  //sort,unique
	vector<int> v6 = { 3,4,1,2,5,1,3,2,5,3 };
	//sort(v6.begin(), v6.end());
	sort(v6.begin(), v6.end(), [](int a1, int a2) { return a1 > a2; }); //���Դ���һ��ν�ʣ��������ȽϷ�ʽ���������Ϊ����
	auto firstRepeat = unique(v6.begin(), v6.end()); //unique��vector������ظ���Ԫ���Ƶ�����(�Ƚ���sort����)��ǰ��ֻ�������ظ���Ԫ��
	cout << firstRepeat - v6.begin() << endl;//���ص��ǵ�һ���ظ�Ԫ�ص�iterator
	v6.erase(firstRepeat, v6.end()); //��Ҫ�ٸ�erase����ɾ��
									 //unique���÷���remove,remove_ifһ��������ֻ�ƶ�Ԫ�أ���û������ɾ��

									 //sortʹ��ν��
	vector<int> v7 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v7.begin(), v7.end(), isBigger);

	//reverse��reverse_copy,copy���Ǹ��Ƶ�ָ��λ�ã�������ı䣩
	{
		vector<int> v8 = { 1,2,3,4,5 };
		reverse(v8.begin(), v8.end());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		vector<int> v9(5); //Ŀ��λ�ñ����㹻��
		reverse_copy(v8.begin(), v8.end(), v9.begin());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		for_each(v9.begin(), v9.end(), [](int a) { cout << a << " "; });
		cout << endl;
	}

	//rotate��xx_if,rotate����Ԫ�ػ������п���һ��������ת��ЩԪ�ص�ԭ��middleԪ�ص���firstλ��
	{
		vector<int> v8 = { 1,2,3,4,5 };
		//reverse(v8.begin(), v8.end());
		rotate(v8.begin(), v8.begin() + 2, v8.end());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		//rotate_copy ����
	}


	//lambda���ʽ
	vector<int> v8 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v8.begin(), v8.end(), [](int a, int b) { return a > b; });

	vector<string> v9 = { "abc","defg","hdsaddas" };
	int sz = 3;
	auto it9 = find_if(v9.begin(), v9.end(), [sz](const string &a) { return a.size() > sz; });//���Բ���ͬ������ı���
	cout << it9 - v9.begin() << endl;

	//for_each���lambda���ʽʵ�ָ��ֹ��ܣ�Ҳ����ʵ���޸�,�������ã�
	vector<int> v10 = { 3,4,1,2,5,1,3,2,5,3 };
	for_each(v10.begin(), v10.end(), [](int a) { if (a > 3) cout << a << "|"; });
	for_each(v10.begin(), v10.end(), [](int& a) { a++; });
	for_each(v10.begin(), v10.end(), [](int a) { cout << a << "|"; });
	cout << endl;

	//random_shuffle
	random_shuffle(v10.begin(), v10.end());
	for_each(v10.begin(), v10.end(), [](int a) { cout << a << "|"; });
	cout << endl;

	//����,next_permutation,prev_permutation,next_permutation,��ֱ�Ӱ�ԭ�������� ������ԭʼ���ݱ����������
	{
		vector<int> v = { 1,2,3 };
		while (next_permutation(v.begin(), v.end()))
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}
		cout << endl;
		v = { 3,1,2 };
		while (next_permutation(v.begin(), v.end())) //���ʱ�������ֻ��321��
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}

		v = { 3,2,1 };
		while (prev_permutation(v.begin(), v.end()))//���Կ���prev_premutation�ǰ�����ǰ�ģ�����Ҳ�����ұյ����˼·
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}

	}

	//partition�ҵ���������������Ԫ�أ��ƶ���vectorǰ�Σ�
	//���ص�һ��������������Ԫ��,ǰ��ͺ����Ԫ��˳�򶼲�һ��,ֻ��������������
	{
		vector<int> v = { 1,2,3,4,5,6,7,8,9 };
		for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		partition(v.begin(), v.end(), [](int v1) { return v1 > 5; });
		for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}


	//count
	vector<int> v11 = { 3,4,1,2,5,1,3,2,5,3 };
	auto it_11 = count(v11.begin(), v11.end(), 3); // 3��
	auto it_11_1 = count_if(v11.begin(), v11.end(), [](int i) { return i == 3; });

	//min_element
	auto it_11_2 = min_element(v11.begin(), v11.end());//���ص�����
	auto it_11_3 = max_element(v11.begin(), v11.end());

	//�ϲ��㷨
	//merge���������Ѿ���������еĺϲ�,���Ժ�mergesort�����õ�����ʵ���,�������в�����
	{
		vector<int> v = { 1,2,3,4,5,6,7,8,9 };
		vector<int> v1 = { 2,3,4,5,6,7,8,9,10 };
		vector<int> v2(v.size() + v1.size());
		merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}
	//set_union���󲢼�(�����Ѿ������)
	{
		vector<int> v = { 1,2,3,4,5,6,7,8,9 };
		vector<int> v1 = { 2,3,4,5,6,7,8,9,10 };
		vector<int> v2;
		set_union(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//set_intersection���󽻼�(�����Ѿ������)
	{
		vector<int> v = { 1,2,3,4,5,6,7,8,9 };
		vector<int> v1 = { 2,3,4,5,6,7,8,9,10 };
		vector<int> v2;
		set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//set_difference����(�����Ѿ������),����ǰ�����1�в�������2�е�
	{
		vector<int> v = { 1,2,3,4,5,6,7,8,9 };
		vector<int> v1 = { 2,3,4,5,6,7,8,9,10 };
		vector<int> v2;
		set_difference(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//������
	{
		//front_inserter
		deque<int> d = { 1,2,3 };
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		front_inserter(d) = 22;
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		deque<int> d1 = { 4,5 };
		copy(d1.begin(), d1.end(), front_inserter(d));
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;

		//inserter
		inserter(d, d.begin()) = 101; //���뵽ĩβ
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;

		deque<int> d2 = { 102,103 };
		copy(d2.begin(), d2.end(), inserter(d, d.begin()));
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;

	}

	//distance,����������������,advance,������ǰ��n��
	//iter_swap()��������������
	//


	//��ֵ���㲿��:
	//accumulate
	//inner_product,��ӦԪ��������,���յ�һ�����еķ�Χ��ȷ��
	{
		vector<int> v1 = { 1,2,4 };
		vector<int> v2 = { 2,4,8 };

		cout << inner_product(v1.begin(), v1.end(), v2.begin(),0) << endl;
		//Ҳ���Ը�дʵ�ֵķ����������ڻ�������
		//����:val = op1(val,op2(elem1,elem2))
	}

	//partial_sum
	{
		vector<int> v1 = { 1,2,3,4,5 }; 
		vector<int> v2; // 1 3 6 10 15������
		partial_sum(v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//
	{
		vector<int> v1 = { 1,2,3,5,9 };
		vector<int> v2; // 1 1 1 2 4������
		adjacent_difference(v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}


	system("pause");
	return 0;
}




