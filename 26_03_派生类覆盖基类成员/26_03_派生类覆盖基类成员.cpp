// 26_03_�����า�ǻ����Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	int age;
	
};

class Derived:public Base {

public:
	int age;
};


int main()
{
	Derived d;
	d.age = 10;
	d.Base::age = 20;
	if (4>3>2) {
		cout << "aa" << endl;
	}



	cout << d.age << endl << d.Base::age << endl;
		
	system("pause");
    return 0;
}

