// 34_02_ifstream_ofstream.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{


	//总结:ofs.write或者read使指针发生变化
	//seekp是调整写指针，默认第二个参数是ios::beg,从开头往后偏移
	//tellp返回当前所在位置，最开始是0
	//ios::cur是个内部成员变量，值是1，代表当前位置

	ofstream ofs("../a.txt", ios::binary); //二进制方式打开
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
	ofs.write("abc我们的", 9);
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

    return 0;
}

