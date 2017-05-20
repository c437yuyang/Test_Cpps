#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	const int *p = NULL; //底层
	int const *p1 = NULL; //同样也是底层
	int * const p2 = NULL;//这样才是顶层

	//const在*的左测，指针所指向的内容不可变，即*p不可变；
	// 本题改变的是指针p本身，但p++后不知道指针指向了哪里。所以*p是没有用的值
	//	const在*的右侧，指针不可变，即p++不被允许；

	system("pause");
    return 0;
}
