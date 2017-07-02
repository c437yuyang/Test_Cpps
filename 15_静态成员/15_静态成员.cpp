// 15_静态成员.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class TestStatic {
	//static const int memCount = 0; //如果要在类内进行初始化的话，必须设为常量值

	static int memCount; //常量成员同样遵循访问修饰控制符的权限控制

public:
	
	TestStatic() { memCount++; }
	~TestStatic() { memCount--; }

	//int GetMemCount() { return memCount; } //非常量的成员可以访问常量成员（必须先有实例）
	static int GetMemCount() { return memCount; } //常量成员不能访问非常量成员（因为常量成员先于非常量成员初始化）

};

int TestStatic::memCount = 0; //常量成员必须(必须)在外部声明(全局范围)

int main()
{
	//int TestStatic::memCount = 0; //常量成员必须在外部声明(函数内部不行)

	TestStatic ts1;
	TestStatic ts2;
	TestStatic *pTs = new TestStatic;

	//cout << ts1.GetMemCount() << endl; //有实例了依然可以访问常量成员，（非常量的成员可以访问常量成员（必须先有实例））
	cout << TestStatic::GetMemCount() << endl;
	delete pTs;
	cout << TestStatic::GetMemCount() << endl;
	system("pause");
	return 0;
}

