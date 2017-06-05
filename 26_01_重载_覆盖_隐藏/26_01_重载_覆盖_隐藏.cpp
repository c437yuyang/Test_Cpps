// 26_01_重载_覆盖_隐藏.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


// 1.重载:(同一作用域，不同参数)
// (1)相同范围(同一个类或者同一作用域内)
// (2)函数同名，参数不同(必须)，返回值任意，virtual任意

// 2.覆盖（就是通常的virtual函数被继承，必须整个签名一致）
// (1)不同范围(基类与派生类)
// (2)函数同名，参数相同，返回值相同，有virtual

// 3.隐藏（子类有一个跟父类签名不同的同名函数，或者签名相同但父类不是virtual，就构成隐藏）
// (1)不同范围(基类与派生类)
// (2)函数同名，参数不同，返回值任意，virtual任意，基类函数被隐藏(与重载的区别在于作用域)
// (3)函数同名，参数相同，返回值任意，基类没有virtual，基类函数被隐藏(与覆盖的区别在于基类函数是否是virtual)


//总结:其实就如EffectiveC++中所言，就是一个作用域的问题，
// 函数调用的时候会先搜索当前local作用域，再当前类，再当前namespace,再global
// 所以，子类里面只要有一个同名函数，便会屏蔽掉基类里面的同名函数，无论参数和返回值
// 如果要在子类里面使用基类的被屏蔽(覆盖或者是隐藏)的函数，可以使用using Base::function()来实现

class Base{
public:
	void mf1(); //(1)
	void mf1(int); //(2)
	int mf1(double); //(3) ,1,2,3之间是重载关系,注意，参数必须不同，返回值任意


	virtual void mf2();//(4)

	virtual void mf3();//(5)


};

class Derived:public Base{
	void mf2();//(6)	(4),(6)是覆盖,返回值必须相同,若参数不同,则是隐藏
	int mf2(int); //(7) 隐藏了父类的mf2

	void mf3(int); //(8) 隐藏了父类的mf3

};

int main()
{
	system("pause");
	return 0;
}

