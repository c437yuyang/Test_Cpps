// 41_新式转型.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void doSomething(double &d) {}

class  Widget
{
public:
	Widget();
	virtual ~Widget();

private:

};

class SpecialWidget :public Widget {};

class SpecialWidget1 {};

Widget::Widget()
{
}

Widget::~Widget()
{
}

int main()
{

	// 1.static_cast类似于旧式转型，但是不能去除常量性
	double d = static_cast<double>(5);
	double d1 = 1.1;
	const double d2 = static_cast<const double>(d1); //可以加上常量性

	// 2.const_cast，移除常量性
	const double d3 = 1.1;
	doSomething(const_cast<double&>(d3));

	// 3.dynamic_cast实现向下安全转型，由父类指针向下转型
	Widget *w = new SpecialWidget;
	//SpecialWidget *w1 = w;//报错
	SpecialWidget *w1 = dynamic_cast<SpecialWidget*>(w); //要求类型必须具有多态性质(虚函数)
	//SpecialWidget1 *w11 = dynamic_cast<SpecialWidget*>(w); //没有继承关系也不能转型


	// 4.reinterpret_cast实现低级转型，比如pointer to int 转 int
	int *p1 = new int(10);
	//int i = p1; //报错
	int i = reinterpret_cast<int>(p1); //打印出来就是指针的地址值

	// 5.以上四个，除了dynamic_cast旧式操作无法实现(也可以转，只是不检测是否可以正确的转型)
	// 旧式操作都可以实现

	cout << i << endl;

	return 0;
}

