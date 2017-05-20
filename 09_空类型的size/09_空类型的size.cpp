// 09_空类型的size.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A{};
class B { int a; };
class C { void printInfo() {}; };
class D { int a; void printInfo() {}; };
class E { int a; void printInfo() {}; char c; short s; };
class F { char c; };
class G
{
public:
	int a; 
	int a1[0];
};//柔性数组,代表结构体大小可变

int main()
{
	cout << sizeof(A) << endl; //1
	cout << sizeof(B) << endl; //4
	cout << sizeof(C) << endl; //1
	cout << sizeof(D) << endl; //4
	cout << sizeof(E) << endl; //8
	cout << sizeof(F) << endl; //1
	cout << sizeof(G) << endl; //
	//结论,只有成员本身才占空间，函数不占空间，然后要考虑对齐，以及空类型的话占一个字节。

	//可变长度结构体的使用
	// 申明一个长度为0的数组，就可以使得这个结构体是可变长的。对于编译器来说，此时长度为0的数组并不占用空间，因为数组名本身不占空间，它只是一个偏移量， 数组名这个符号本身代 表了一个不可修改的地址常量 （注意：数组名永远都不会是指针！ ），但对于这个数组的大小，我们可以进行动态分配 请仔细理解后半部分，对于编译器而言，数组名仅仅是一个符号，它不会占用任何空间，它在结构体中，只是代表了一个偏移量，代表一个不可修改的地址常量！
	//对于0长数组的这个特点，很容易构造出变成结构体，如缓冲区，数据包等等：
	//	注意 : 构造缓冲区就是方便管理内存缓冲区, 减少内存碎片化, 它的作用不是标志结构体结束, 而是扩展
	G g;
	g.a1[0] = 1;
	g.a1[1] = 2;
	g.a1[2] = 3; 
	cout << g.a1[0] << "," << g.a1[1] << "," << g.a1[2] << endl;


	system("pause");
    return 0;
}

