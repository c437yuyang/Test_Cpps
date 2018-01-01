// 00_someDemos_01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <atlimage.h>
#include <vector>
using namespace std;
//void f(int n);
int main()
{

	//数组
	{
		//float a[10], x;
		//a = &x; //数组只能在定义的时候赋值，如果定义的是float *a，才能这样


		//int a[3][4] = {0};
		//for (int i=0;i!=12;++i)
		//{
		//	int w1 = i / 4;
		//	int w2 = i % 4;
		//	a[w1][w2] = i;
		//}
		//int j = a[9]; //不能直接a[9]来访问，a[9]在这里是*(a+9)，是一个一维的数组，不可修改  
	}


	//函数不能嵌套定义
	{
		//void printInfo() { cout << " " << endl; } //报错
	}



	//二维数组
	{
		//int a[2][3] = { 1,2,3,4,5,6 };

		////int a1 = (&a[0] + 1)[2];
		//int *p1 = (&a[0] + 1)[1];
		//cout << *p1 << endl;
		////int *p = (&a[0] + 1); //表达式的类型是int(*)[3] ,一个指针，指向有三个成员的数组
		//int a2 = *(*(a + 1) + 2);
		//int a3 = ((int *)(&a[0] + 1))[2];
	}




	//break后for不会再执行i++
	{
		//int i;
		//for (i=0;i!=8;++i)
		//{
		//	if(i==1) break;
		//}
	}


	//i++带来的未定义行为
	{
		int i = 0;
		i = i++; //这里是一个未定行为 ，取决于编译器先执行i++返回了当前值之后的自加还是=号
	}


#pragma region 指针变量直接由整数赋值

	//int *i = 1; //但是不能用整数赋值
	int *i = 0; //可以为0，就是NULL

#pragma endregion

	//一维数组初始化
	{
		int a[10] = {}; //初始化为了全0,但是这貌似是VC的问题，C++标准没有规定这样也初始化
		int a1[10] = { 10 }; //初始化为了后面全0
		int a2[10] = { 10,-1,1.1 };// 数组里面本身也是必须要求匹配的类型，VC可以过虽然，但是数据还是错的
		for_each(a, a + 10, [](int val) { cout << val << " "; });
		cout << endl;


	}

	// 二维数组初始化
	{
		using std::printf;
		//int arr[][4]; //还是错的，省去第一维的话必须有赋值数量才能推断
		int arr[][4] = { 1,2,3,4,5,6 }; //正确


		//可以看到二维数组没分配第一维的时候就按照需要来分配，
		// 比如第一个就是2，第二个一共5个数，所以第一维需要3，最后总共是6
		// 且必须制定分配的列数，行数可以不指定，自动判别
		int a[][2] = { 1,2,3,4 };
		printf("%d\n", sizeof(a) / sizeof(int)); //输出4
		int a1[][2] = { 1,2,3,4,5 };
		printf("%d\n", sizeof(a1) / sizeof(int)); //6()
		int a2[4][2] = { 1,2,3,4 ,5 };
		printf("%d\n", sizeof(a2) / sizeof(int)); //输出8

		int a3[2][2] = { { 1 },2,3 };
		printf("%d\n", sizeof(a3) / sizeof(int)); //输出4（这个写法是对的）等价于{{1,0},2,3}

												  //新标准的遍历方式可以这样
		int a4[] = { 1,2,3,4,5 };
		for (auto it = begin(a4); it != end(a4); ++it)
		{
			printf("%d\t", *it);
		}
		cout << endl;
		//二维要对每一维再取迭代器
		int a5[2][2] = { 1,2,3,4 };

		for (auto it = begin(a5); it != end(a5); ++it)
		{
			for (auto it1 = begin(*it); it1 != end(*it); ++it1)
			{
				printf("%d\t", *it1);
			}
			cout << endl;

		}
		cout << endl;
	}

	//控制台调用CImage，要#include <atlimage.h>
	{
		CImage m;
		std::wstring imgPath = _T("lena.jpg");
		m.Load(imgPath.c_str());
		std::cout << m.GetWidth() << std::endl;
	}

	{
		//取反是连着符号位一起取反的
		int i = 1;
		int j = ~i; //符号位也反了，变成了负数
	}

	{
		//逻辑真值，只要是非0值就可以，double,float都行，不需要是整数
		double d = 1.1;
		if (d)
			cout << "not zero" << endl;

	}

	{
		//字符串可以放在除了字符数组之外的数组？
		//答案可以

		class Widget
		{
		public:
			Widget(const string&str) :str(str) {}
			string str;
		};

		Widget w[2] = { "a","b" };


	}

	{
		//修改const的值后
		const int i = 0;
		int *j = (int *)&i;
		*j = 1;
		printf("%d,%d", i, *j); //c++里面还是0,1,C里面是1,1



		//C++中的常量折叠：指const变量（即常量）值 放在编译器的符号表中 ，计算时编译器直接从表中取值，省去了访问内存的时间，从而达到了优化。
		//	具体可以看这个：
		//	http ://blog.csdn.net/heyabo/article/details/8745942


		//分析：C语言中的const是运行时const，编译时只是定义，在运行才会初始化。C语言中const变量不能用于成为数组长度等作为编译时常量的情况，原因就在此。C语言const变量在运行时改变了是可以再次读出改变后的值的。
		//	C++中，const变量是编译时的常量，可以向#define定义的常量一样使用。故C++中const变量的值在编译时就已经确定了，直接对cosnt变量进行了值的替换，因此当const变量的值改变时，const的变量值是不会得到更新的。
		//	这几行代码在C和C++中都会改变const变量的值，只不过C++中const变量在编译的时候已经确定了，而C中的const变量可以在运行时改变后再次读取。以下代码核实了C++中的const变量确实被改变了。

	}


	//移位运算符:
	{
		//1.负数右移运算高位补1
		//2.运算对象可以是整形或者字符型(这里的整形包含了很多，比如long,short这些都是，其实就是除了double这种前几位是表示指数，后面表示实际的这种表示方法都是可以移位运算符的)
		//3.按位取反只需要一个操作数，其他位运算符是两个操作数
		char a = 'a';
		a << 1;
		unsigned short b = 1;
		b << 1;

	}

	//double和float也是可以++运算的
	{
		double d1 = 1.1;
		double d2 = d1++; //d1 = 2.1
	}

	//无符号数和有符号数
	{
		cout << endl;
		unsigned int i = -2147483647 - 1;
		float a = 0.0;
		//a-1
		unsigned int c = 1u - 2u; //两个无符号数相减，如果小于0，则会产生溢出，这里就成了基本上是最大的无符号数了
		bool b = 1u - 2u < 0; //false 

		printf("%u\n", i);

	}

	//f(5);

	{ //在C语言中变量或函数可以重复声明，但是不能重复定义
		//声明在内部，则这个声明只有内部作用域有效
		void f(int n);
		f(5);
	}
	//f(5); //也不能访问到内部作用域的f

	{

			std::vector<int> v;
			auto it = v.end();
			--v.end();
			int * func();
			//int *p = --func(); // 报错，C++不允许对内置类型的临时变量进行修改
	}

	::system("pause");
	return 0;
}

void f(int n)
{
	printf("%d\n", n);
}

