// 42_01_���ַ�խ�ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
//#include <WinNls.h> //ֱ�Ӱ���windows.h���������Ҫ����
using namespace std;

int main()
{

	//�ܽ�:ֱ����խ�ַ�һ���Ŀ��������ȷ�ķ�ascii���ֵ��string���������ʱ��Ҫָ��Ϊ.cstr()����Ȼ�Ҳ���\0
	//���ǿ��Բ鿴string��ÿһ����Ա��ֵ�ͷ�����ʵ���������(printf��cout���˴���)

	//����ֻ����char*��wchar_t*�����������ͣ�string��wstring��.cstr()ȡ��һ���Ĳ���

	char *str = "ab����cde"; //��Ȼ����ÿ���ֽ������룬��ʵ����Ϊ���õ���GB2312����
	wchar_t *wstr = L"ab����cde"; //���ַ�ò�������

	printf("%s\n", str);
	printf("%ws\n", wstr); //%ws,%S����������ַ�
	wprintf(L"%s", wstr); //Ҳ�����������

	//��Ϊwchar_t�������κ�encoding�ķ�ʽ���洢�ַ�������unicode,ANSI,UCS-2�ȵ�
	//��wprintf��ֱ�Ӱ����ֽ�˳�����������windows�ṩ�˽�wchar_tת����խ�ַ�(���ֽڱ�ʾ��ʽ)�ĺ���

	int len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, false); //len=10,�����������ַ�����β\0Ҳ��һ��
	char* strW2A = new char[len];
	if (len != 0) 
	{
		WideCharToMultiByte(CP_ACP, 0, wstr, -1, strW2A, len, NULL, false);
	}
	if(strW2A!=NULL)
		printf("%s\n", strW2A);
	delete[] strW2A;


	system("pause");
    return 0;
}

