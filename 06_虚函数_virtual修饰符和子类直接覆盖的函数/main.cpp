#include<iostream>
using namespace std;

class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}

	int foo(char x[14])
	{
		return sizeof(x) + 10;
	}
};

class Derived : public Base
{
	int foo(int x) //父类是有virtual修饰符的，所以动态绑定的时候会调用子类的函数
	{
		return x * 20;
	}

	virtual int foo(char x[10]) //这里的virtual没用，做题的时候的障眼法
	{
		return sizeof(x) + 20;
	}
};

int main()
{
	Derived stDerived;
	Base *pstBase = &stDerived;

	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x)); 
	system("pause");
	return 0;
	//总结:
	//1.一个类的对象指明了的时候肯定调用该类的函数，没有什么动态绑定不绑定
	// 2.出现Base *pstBase = &stDerived这种父类指针指向子类的时候，出现动态绑定
	// 此时若是virtual函数则调用子类的函数，若不是virtual就不会动态绑定，是什么指针就调什么函数
	// 所以这里是父类指针就调用父类的函数
}