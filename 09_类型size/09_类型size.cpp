// 09_����size.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <iostream>
using namespace std;

struct A {
	A() {}
	~A() {}
	int m1;
	int m2;

};
struct B :A {
	B() {}
	~B() {}
	int m1;
	char m2;
	static char m3;
	void printParentM() { cout << A::m1 << endl; cout << A::m2 << endl; } //�����ڿ��Է��ʸ����ͬ����Ա������Ͳ�����
};
struct C {
	C() {}
	virtual~C() {}
	int m1;
	short m2;
};

int main()
{

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;

	A a;
	B b;
	C c;
	cout << b.m1 << endl; //ͬ���ĳ�Ա�����໥��������ͬ���ĳ�Ա�����ᷢ�����ǡ�
	cout << b.m2 << endl;
	//cout << A::m1 << endl; //���������ǲ���ֱ�ӷ��ʸ����ͬ����Ա����

//		�𰸽�������Ĵ�Сֻ���Ա��������static���ݳ�Ա���������麯��ָ���йأ���Ҫ���ǵ�����. 
// 		��ô��A�Ĵ�С��8���ֽڣ�
// 		��B�̳���A������A��8���ֽڻ����ϣ��ټ���B�Լ��Ĵ�С8�ֽڣ�������B��С��16���ֽڣ�
// 		��C��4���ֽ� + 4���ֽڣ����Ƕ��룩 + 4���ֽڣ�ָ��������������ָ�룩 = 12���ֽ�

	system("pause");
	return 0;
}
