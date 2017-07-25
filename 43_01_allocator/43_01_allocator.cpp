// 43_01_allocator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Widget
{
public:
	Widget(int id1) :id(id1) { cout << "Widget ctor" << endl; }
	~Widget() { cout << "Widget dtor" << endl; }

	void printInfo() { cout << "Widget:" << id << endl; }
	int id;
};

int main()
{
	allocator<Widget> waloc;
	Widget *const p = waloc.allocate(10); //�ȷ����ڴ棬ԭʼ�ڴ棬δ����
	auto q = p;
	waloc.construct(q++, 1); //�����ڴ������¹������
	waloc.construct(q++, 2);
	waloc.construct(q++, 3);

	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}

	q = p;
	waloc.destroy(q++); //destroyֻ�ǰѶ��������ˣ��ڴ�û���ͷ�
	waloc.destroy(q++);
	waloc.destroy(q++);

	//�����˻��ǿ������(������)��
	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}
	q = p;
	waloc.construct(q++, 4);
	waloc.construct(q++, 5);
	waloc.construct(q++,6);

	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}

	
	waloc.deallocate(p, 10);  //deallocate�����ͷ��ڴ�

	for (int i = 0; i != 3; ++i) //�ͷ����ڴ���������Ǵ������
	{
		p[i].printInfo();
	}
	system("pause");
	return 0;
}



