// 34_01_io��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>  //����geiline(istream,string)
using namespace std;

int main()
{

	//string�Ķ��룬����:>>��getline()
	{
		string temp;
		cin >> temp; //cin��Ϊ����Ļ���������ܿհ��ַ�
		cout << "�������" << temp << endl;
		getline(cin, temp); //���԰����հ��ַ����Իس�����

	}
	
	//get,put����
	{
		char arr[7];
		//����EOF(CTRL+Z)�������
		//cin.get(arr,6); //ָ���������6���ַ�
		cin.get(arr, 6,'\n'); //ָ���������6���ַ���������'\n'����,Ĭ��Ҳ������'\n'����

		cout << arr << endl; 

	}


	//char c[10];
	//cin.getline(&c[0], 5, 'g'); //ָ������5-1���ַ�����Ϊ���һ����\0

	
	

	system("pause");
	return 0;
}

