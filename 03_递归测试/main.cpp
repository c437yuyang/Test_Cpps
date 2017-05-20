#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int Fibonacci(int n)
{
	if (n==1 || n==0)
	{
		return 1;
	}
	else
	{

		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	Fibonacci(10);
	int i = 0;
	system("pause");
}