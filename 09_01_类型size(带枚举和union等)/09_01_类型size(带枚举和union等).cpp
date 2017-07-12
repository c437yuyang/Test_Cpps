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

class A1
{
	char c;
	int *pInt; //最小为指针，四字节，所以总共8
}a1;

typedef union {
	long i;
	int k[5];
	char c;
} DATE;
struct data {
	int cat;
	DATE cow;
	double dog;
	char c;
} too;


int main()
{

	cout << sizeof(A) << endl; //24
	cout << sizeof(A1) << endl; //8

	///实例化class A

	//int i占4个字节
	//	union U实例化为u占取16个字节（char数组占13个字节，但因为最大类型为int，所以占取只能为4字节的整数倍即最小16字节）
	//	空函数不占取字节
	//	未实例化指针不占取字节
	//	枚举类型占取4个字节
	//  指针类型占取4字节，也能充当最小单元
	//	引用类型和其引用的类型一致

	//	总共占取4 + 16 + 4 = 24个字节

	cout << sizeof(DATE) << endl; //20,union里面最大单元是Int[5]，为20，但对齐的时候，是看最小基本元素的大小，比如这里就是看long的大小来进行对齐
	cout << sizeof(too) << endl;//40,对齐的时候，是看最小基本元素的大小，这里是double，就按照8的倍数来
	system("pause");
    return 0;
}
