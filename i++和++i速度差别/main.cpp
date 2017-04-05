#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main(){

	int nTestTime = 10000000000000;
	DWORD timeStart = GetTickCount();
	for (int i=0;i!= nTestTime;++i)
	{
		;
	}
	cout << "++i耗时:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime;i++)
	{
		;
	}
	cout << "i++耗时:" << (GetTickCount() - timeStart) << endl;
	system("pause");
	//经过测试,日了狗一样的竟然i++更快！！！，所以平时就用i++吧；
}