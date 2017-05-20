// 09_01_类型size(带枚举和union等).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class A
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	void foo() {    }
	typedef char* (*f)(void*);
	enum { red, green, blue } color;
}a;

int main()
{

	cout << sizeof(A) << endl; //24

	///实例化class A

	//int i占4个字节
	//	union U实例化为u占取16个字节（char数组占13个字节，但因为最大类型为int，所以占取只能为4字节的整数倍即最小16字节）
	//	空函数不占取字节
	//	未实例化指针不占取字节
	//	枚举类型占取4个字节

	//	总共占取4 + 16 + 4 = 24个字节


	system("pause");
    return 0;
}
