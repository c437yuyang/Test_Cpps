#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	const int *p = NULL; //底层
	int const *p1 = NULL; //同样也是底层
	int * const p2 = NULL;//这样才是顶层

	//所有的排列(一共A(3,3)=6种)
	const int *p4 = NULL;
	const * int p5 = NULL;
	int const * p6 = NULL;
	int * const p7 = NULL;
	*int const p8 = NULL;
	*const int p9 = NULL;
	//总结:首先int必须在*左边才能组成int *类型，就只有3种可能了

	//const在*的左测，指针所指向的内容不可变，即*p不可变；
	// 本题改变的是指针p本身，但p++后不知道指针指向了哪里。所以*p是没有用的值
	//	const在*的右侧，指针不可变，即p++不被允许；


	system("pause");
    return 0;
}
