// 20_0_字符串数组和指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	char *str; str = "Hello"; //指针可以后面再去指向
	//char str1[];  //1.数组必须指明大小，2.数组不能后面再赋值
	//str1 = "Hello"; 

	char *str2 = "Hello1"; //指针可以后面再赋值
	str2 = "hello2";
	cout << str2 << endl;

	//*str2 = 'a'; //虽然编译不报错，运行时会出错，常量区不允许更改
	cout << str2 << endl;


	char str3[10] = "aaaa";
	char str3_1[10] = { "aaaa" }; //二者等价


	char *str4 = "hello"; 
	char *str5 = "hello";
	cout << (str4 == str5) << endl; //1
	cout << ("hello" == "hello") << endl;//1 说明常量是固定位置的


	system("pause");
	return 0;
}
