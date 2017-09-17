// 09_01_类型size(带枚举和union等).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//总结:


//基本规则
//1、数据成员对齐规则：结构(struct)(或联合(union))的数据成员，第一个数据成员放在offset为0的地方，
//以后每个数据成员存储的起始位置要从该成员大小或者成员的子成员大小
//（只要该成员有子成员，比如说是数组，结构体等）的整数倍开始(比如int在３２位机为４字节, 则要从４的整数倍地址开始存储)
//基本类型不包括struct/class/uinon

//2、结构体作为成员的对齐规则:如果一个结构里有某些结构体成员, 则结构体成员要从其内部"最宽基本类型成员"的整数倍地址开始存储.
//(struct a里存有struct b, b里有char, int, double等元素, 那b应该从8的整数倍开始存储.)。
//
//3、收尾工作 : 结构体的总大小, 也就是sizeof的结果, .必须是其内部最大成员的"最宽基本类型成员"的整数倍.不足的要补齐.
//(基本类型不包括struct / class / uinon)。
//
//4、sizeof(union)，以结构里面size最大元素为union的size, 因为在某一时刻，union只有一个成员真正存储于该地址。


//一些说明
//1.虚函数一旦有一个就会占用4字节，去指向虚函数表，但是不管声明几个虚函数，都只占用四字节
//2.成员函数不占字节大小
//3.未实例化函数指针不占取字节
//4.枚举类型占取4个字节
//5.指针类型和虚函数指针都是可以充当最小单元的，这两个为4字节，除了struct / class / uinon都是基本类型
//6.成员进行对齐的时候，是看基本类型的大小，比如数组或者struct就不是基本类型
//7.引用类型和其引用的类型一致
//8.类为空的时候占一个字节
//9.子类继承父类的大小的基础上，加上自己成员的大小，同名成员不会直接替换，也是追加，因为访问都可以访问Base::xxx，因此子类的大小只能增不能减
//10.union或者sturct或者枚举如果定义在类内部，如果只是定义，但不实例化一个对象的话，是不占取字节的
//11.柔性数组，直接不占字节，如果只有一个柔性数组成员，可直接理解为空，即占一个字节
//12.static成员不考虑大小

int main()
{
	//case1
	{
		class A
		{
		public:
			int i; //4
			union U
			{
				char buff[13];
				int i;
			}uu; //16 union U实例化为uu占取16个字节（char数组占13个字节，但因为最大类型为int，所以占取只能为4字节的整数倍即最小16字节）
			void foo() {    } //函数不占
			typedef char* (*f)(void*); //未实例化指针不占
			enum { red, green, blue }; //定义一个未命名枚举但不实例化，不占字节
			enum direction {
				up, left, right, bottom
			} u, l, r, b; //定义一个枚举类，再定义四个枚举变量，16字节
		};

		class A1
		{
			char c;
			int *pInt; //最小为指针，四字节，所以总共8
		};

		cout << sizeof(A) << endl; //36
		cout << sizeof(A1) << endl; //8
		cout << sizeof(A::direction) << endl; //4
	}

	//case2 union对象作为成员
	{
		typedef union {
			long i;
			int k[5];
			char c;
		} DATE;

		struct data {
			int cat; //4
			DATE cow; //  20
			double dog; //8
			char c;//1，最后补全成8
		} too;

		cout << sizeof(DATE) << endl; //20,union里面最大单元是Int[5]，为20，但对齐的时候，是看最小基本元素的大小，比如这里就是看long的大小来进行对齐
		cout << sizeof(too) << endl;//40,对齐的时候，是看最小基本元素的大小，这里是double，就按照8的倍数来
	}

	//case3 虚函数指针demo1
	{

		class P  //虚函数一旦有一个就会占用4字节，去指向虚函数表，但是不管声明几个虚函数，都只占用四字节
		{
		public:
			virtual ~P() = 0;
			virtual void printInfo() {};
		};

		class P1 : public P
		{
		public:
			//virtual ~P1() = 0; //声明或不声明都一样，父类虚函数了子函数都是虚函数了

		};

		cout << sizeof(P) << endl;//4
		cout << sizeof(P1) << endl;//4
	}


	//case4 虚函数指针demo2
	{
		class X {
		public:
			virtual void printInfo() = 0;
			char c;
		};

		class X1 :public X {
		public:
			/*virtual void printInfo();*/
		};

		cout << sizeof(X) << endl; //8 虚函数指针也充当基本类型，然后char为1，最后补充
		cout << sizeof(X1) << endl; //8
	}

	//case5 数组作为成员,并不影响对齐，对齐还是看基本类型的大小
	{
		struct {
			char a[10]; //10
			int b; //4 但需要先按照4的整数倍移动到12开始
			short c[3]; //6 但结束后需要补充为4的整数倍
		}X;

		cout << sizeof(X) << endl; //24,
	}
	
	//case6空类型的大小
	{
		class A {};
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

		class G1
		{
		public:
			int a;
			char b;
			int a1[0];
		};

		class G2
		{
		public:
			int a1[0];
		};

		cout << sizeof(A) << endl; //1 空类型为1
		cout << sizeof(C) << endl; //1，成员函数不影响大小
		cout << sizeof(D) << endl; //4
		cout << sizeof(E) << endl; //8
		cout << sizeof(F) << endl; //1 仍然是1，所以有一个char和没有char占得大小是一样的
		cout << sizeof(G) << endl; //4，，柔性数组直接不考虑(和成员函数一样)，可见并没有增加大小
		cout << sizeof(G1) << endl; //8，可见并没有增加大小
		cout << sizeof(G2) << endl; //4，可见并没有增加大小

	}


	//case7常规demo
	{
		class A
		{
			int a;
			short b;
			int c;
			char d;
		};
		class B
		{
			double a;
			short b;
			int c;
			char d;
		};
		cout << sizeof(A) << endl; //16,最后的补齐是按照最宽基本数据成员
		cout << sizeof(B) << endl; //24

		cout << sizeof(int *) << endl;
	}


	system("pause");
	return 0;
}
