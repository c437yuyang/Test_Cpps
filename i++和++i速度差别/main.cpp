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


	//����Ҫע�⣬++i���ص���i�����ã���ֵ
	//��i++���ص���i��ֵ�ĸ��������ܵ���ֵ

	int i = 0;
	(++i) += 1;
	//(i++) += 1; //����������ֵ
	cout << i << endl; //2

	system("pause");
	//��������,���˹�һ���ľ�Ȼi++���죡����������ƽʱ����i++�ɣ�
}