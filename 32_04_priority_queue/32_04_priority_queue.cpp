// 32_04_priority_queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <queue>
#include <iostream>
using namespace std;



int main()
{

	priority_queue<int> pq;
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

    return 0;
}

