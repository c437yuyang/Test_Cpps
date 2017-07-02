// 06_虚函数测试2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << " "; }
	void test() { func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B() { test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << " ";
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	system("pause");
	return 0;
}

//参考:primer 556页
//构造函数或析构函数里执行了某个虚函数，应该执行与之所属类型相对应类型的虚函数版本
// 这里有个更简单的理解:其实这里test直接就看做子类里面也有一个test函数(继承而来，只是没有写出)，所以test再调的时候
// 理所应当就是调用子类自己的func函数了