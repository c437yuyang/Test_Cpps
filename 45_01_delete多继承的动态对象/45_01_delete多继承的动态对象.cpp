// 45_01_delete多继承的动态对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//问题：多继承的子类，加入时WidgetA *pa = new WidgetC;
//WidgetA就算有虚析构函数，会直接调用子类的吗？ 因为你同时还是继承了B类

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

	delete pa; //奇了怪了，父类没定义虚析构函数也能直接删除了
	system("pause");
    return 0;
}

