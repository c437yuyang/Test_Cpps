// 32_04_priority_queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

struct IntLess :binary_function<const int, const int, bool>
{
public:
	bool operator()(const int lhs, const int rhs) const
	{
		return lhs > rhs;
	}
};

struct MyLess //ʹ��ģ�庯��ʹ�ò���������
{
	template<class T>
	constexpr bool operator()(const T _Left, const T _Right) const
	{	// apply operator< to operands
		return (_Left > _Right);
	}
};

template <class T>
struct MyLess1 
{
	constexpr bool operator()(const T&left, const T&right) const { return left > right; }
};

struct  Person
{
	int age;
	int salary;
};

struct sortByAge 
{
	bool operator()(const Person&lhs, const Person& rhs) {
		return lhs.age < rhs.age;
	}
};

struct sortBySalary
{
	bool operator()(const Person&lhs, const Person& rhs) {
		return lhs.salary < rhs.salary;
	}
};


int main()
{

	priority_queue<int> pq; //Ĭ���Ǵ����
	pq.push(10);
	pq.push(1);
	pq.push(33);
	pq.push(5);
	pq.push(22);
	size_t size = pq.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	//priority_queue<int, vector<int>, less<int> > min_pq;
	//priority_queue<int, vector<int>, MyLess1<int> > min_pq;
	priority_queue<int, vector<int>,  MyLess> min_pq;
	//priority_queue<int, vector<int>, IntLess > min_pq; //���ﴫ�ıȽϺ������ϵıȽ��Ƿ���
	min_pq.push(10);
	min_pq.push(1);
	min_pq.push(33);
	min_pq.push(5);
	min_pq.push(22);
	size = min_pq.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << min_pq.top() << endl;
		min_pq.pop();
	}


	Person p1{ 10,200 };
	Person p2{ 20,100 };
	Person p3{ 5,1000 };

	priority_queue<Person, vector<Person>, sortByAge> pq_age;
	pq_age.push(p1);
	pq_age.push(p2);
	pq_age.push(p3); //�Ӷϵ㿴pq_age�����ݻ��Ǵ���˳��ģ���Ϊ�ǰ���vector������ģ�������pop�Ͳ�������ᰴ����Ҫ���˳�򵯳�

	return 0;
}

