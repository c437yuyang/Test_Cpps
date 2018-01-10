// 08_编译器生成的默认构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Widget
{
public:
	Widget(const Widget & other){} 
};

int main()
{

	Widget w; //可以看到，就算只是定义了拷贝构造函数，默认构造函数也就不会合成了

    return 0;
}

