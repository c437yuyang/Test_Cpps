// 06_֤���麯��ָ�����_��memset����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class parent
{
public:
	virtual void output();
};
void parent::output()
{
	printf("parent!");
}

class son : public parent
{
public:
	virtual void output();
};
void son::output()
{
	printf("son!");
}

int main()
{

	son s;
	memset(&s, 0, sizeof(s));
	parent& p = s;
	p.output(); //����ʱ�����麯��ָ�뱻����0��

	system("pause");
    return 0;
}

