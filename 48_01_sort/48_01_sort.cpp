// 48_01_sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   /* �Ա߼�����Edge�ṹ�Ķ��� */

int main()
{

	Edge edges[20];
	for (int i=0;i!=20;++i)
	{
		edges[i].weight = 20 - i;
	}

	std::sort(edges, edges + 20, [](const Edge&lhs, const Edge&rhs) {return lhs.weight < rhs.weight; });

	for (int i = 0; i < 20; i++)
	{
		printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}


    return 0;
}

