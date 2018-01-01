// 34_02_ifstream_ofstream.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	//�����ƴ򿪺��ı���ʽ�򿪵�����:
	//https://www.cnblogs.com/litaozijin/p/6582048.html
	//�ܽ�һ�¾���:linux��û������windows�����ı�ģʽ�Ļ���д���ļ���\n����\r\n,��ȡ����\r\n��ת����\n,������ģʽ�򲻻�

	//�ܽ�:ofs.write����readʹָ�뷢���仯
	//seekp�ǵ���дָ�룬Ĭ�ϵڶ���������ios::beg,�ӿ�ͷ����ƫ��
	//tellp���ص�ǰ����λ�ã��ʼ��0
	//ios::cur�Ǹ��ڲ���Ա������ֵ��1������ǰλ��
	//seekp��put����д��seekg��get���Ƕ�
	//seek�������ְ汾��һ���Ǿ���λ�ã�һ�������λ��

	ofstream ofs("../a.txt", ios::binary); //�����Ʒ�ʽ��
	cout << ofs.tellp() << endl;
	ofs.write("abc", 3);
	cout << ofs.tellp() << endl; //3
	ofs.seekp(10, ios::beg);
	cout << ofs.tellp() << endl; // 10
	ofs.write("defg", 4);
	cout << ofs.tellp() << endl;
	ofs.seekp(20);
	cout << ofs.tellp() << endl;
	ofs.write("hijkl", 5);
	ofs.seekp(30);
	ofs.write("abc���ǵ�", 9);
	ofs.close();


	ifstream ifs("../a.txt");
	char buf[CHAR_MAX];
	ifs.read(buf, 10);
	cout << buf << endl;
	cout << ifs.tellg() << endl; //10
	ifs.read(buf, 10);
	cout << buf << endl;
	cout << ifs.tellg() << endl; //20
	ifs.read(buf, 10);
	cout << buf << endl;
	ifs.read(buf, 10);
	cout << buf << endl;

	ifs.close();

	ifs.open("HA9F7220.JPG",ios::ate); //�򿪾Ͷ�λ���ļ�β
	cout << ifs.tellg() << endl; //��������ֱ�ӻ�ȡ�ļ���С



    return 0;
}

