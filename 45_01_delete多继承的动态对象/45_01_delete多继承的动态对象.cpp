// 45_01_delete��̳еĶ�̬����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//���⣺��̳е����࣬����ʱWidgetA *pa = new WidgetC;
//WidgetA��������������������ֱ�ӵ���������� ��Ϊ��ͬʱ���Ǽ̳���B��

class WidgetA {

};


class WidgetB {};


class WidgetC:public WidgetA,public WidgetB {
	int c;
};

int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif

	WidgetA* pa = new WidgetC;

	delete pa; //���˹��ˣ�����û��������������Ҳ��ֱ��ɾ����
	system("pause");
    return 0;
}

