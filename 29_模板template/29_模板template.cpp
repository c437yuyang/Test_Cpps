// 29_模板template.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class fooo {
public:
	template<class T>
	void func(T) {
		cout << typeid(T).name() << endl;
	}
};

//函数模板必须由编译器根据程序员的调用类型实例化为可执行的函数。

//对于一个实例化了的类模板，其成员函数只有在使用时才被实例化。
//如果一个成员函数没有被使用，则它不会被实例化。

int main(int argc, char * * argv) 
{
	fooo f;
	f.func<int>(100);
	system("pause");
	return 0;
}



