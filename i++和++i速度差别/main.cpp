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
	cout << "++i��ʱ:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime;i++)
	{
		;
	}
	cout << "i++��ʱ:" << (GetTickCount() - timeStart) << endl;
	system("pause");
	//��������,���˹�һ���ľ�Ȼi++���죡����������ƽʱ����i++�ɣ�
}