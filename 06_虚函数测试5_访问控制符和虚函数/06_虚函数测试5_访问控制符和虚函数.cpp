// 06_�麯������5_���ʿ��Ʒ����麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	virtual void printInfo() {
		cout << "base" << endl;
	}

private:
	void printInfo1() {
		cout << "base1" << endl;
	}


};

class Drived :public Base
{
private:
	void printInfo() {
		cout << "Drived" << endl;
	}
public:
	void printInfo1() {
		cout << "Drived1" << endl;
	}


};

int main()
{

	//����:���ʿ��Ʒ����麯�����ϵ�ʱ�򣬲�Ӱ���麯�����߷��ʿ��Ʒ���������ã���ɶ������ɶ��



	Base *p = new Drived;
	p->printInfo(); //������public��������private,ͨ�������麯���ķ�ʽ���ܹ����õ�����private�ķ���
	//p->printInfo1(); //����������private,�������÷���


	cin
	return 0;
}

