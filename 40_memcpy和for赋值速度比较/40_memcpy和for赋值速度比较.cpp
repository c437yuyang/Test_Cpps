// 40_memcpy��for��ֵ�ٶȱȽ�.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main() {

	int nTestTime = 10000;
	DWORD timeStart = GetTickCount();
	int nTestSize = 65536*2;
	byte *p = new byte[nTestSize]();
	byte *p1 = new byte[nTestSize]();

	for (int i = 0; i != nTestTime; ++i)
	{
		for (int j = 0; j != nTestSize; ++j)
		{
			p1[j] = p[j];
		}
	}
	cout << "forѭ������byte" << nTestSize << "��" << nTestTime << "�κ�ʱ:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		memcpy_s(p1, nTestSize, p, nTestSize);
	}
	cout << "memcpy_s��ʱ:" << (GetTickCount() - timeStart) << endl;
	//���Կ����ٶȲ�໹�Ƿǳ����
	system("pause");

}