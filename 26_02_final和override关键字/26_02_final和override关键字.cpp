// 26_02_final��override�ؼ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Base {
public:
	virtual void mf1() const final;
	virtual void mf2() const;
};


class Derived:public Base {
public:
	//void mf1() const; //�����޷���дfinal���εĺ���
	//void mf2() override; //����������ʽ��ȫһ��������const
	void mf2() const override; //��ȷ
};


class NoDerived final{

};

//class Derived1 :public NoDerived {};  //final���ε��಻�ܱ��̳�

int main()
{

	system("pause");
    return 0;
}

