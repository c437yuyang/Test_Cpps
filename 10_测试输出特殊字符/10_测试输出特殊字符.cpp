// 10_测试输出特殊字符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
int main()
{

	//根据ascii表:输入ctrl+@就是\0就会退出
	//输入回车是\n(换行符) 10
	// 输入ctrl+m 就是输入回车  最后得到的也是10  反映出来就是一个换行符，其实是一个\r（回车）
	while (char c = getchar())
	{
		cout << (int)c << endl;

	}


	return 0;
}

