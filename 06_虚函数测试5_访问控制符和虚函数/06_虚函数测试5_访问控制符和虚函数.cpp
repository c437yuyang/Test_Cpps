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
	virtual void printInfo2() {
		cout << "Base:printInfo2()" << endl;
	}

};

class Drived :public Base
{
private:
	void printInfo() override {
		cout << "Drived" << endl;
	}
public:
	void printInfo1() {
		cout << "Drived1" << endl;
	}
	virtual void printInfo2()
	{
		cout << "derived:printInfo2()" << endl;
	}

};

int main()
{

	//����:���ʿ��Ʒ����麯�����ϵ�ʱ�򣬲�Ӱ���麯�����߷��ʿ��Ʒ���������ã���ɶ������ɶ��
	//ֻ�Ǳ���ʱ�ľ�̬����ȡ���ڸ��࣬��˸������ٵþ��з����Բ��У�������ܻᱻ�ƻ���װ�ԡ�(��printInfo��ʹ��)
	//�����ø���������麯���ķ�����һ��Ӧ�á�



	Base *p = new Drived;
	p->printInfo(); //������public��������private,ͨ�������麯���ķ�ʽ���ܹ����õ�����private�ķ���
	//p->printInfo1(); //����������private,�������÷���

	//p->printInfo2(); //����������private�����÷��ʣ���ʱpָ���ҵ���������ľ�̬���������Ǹ���ģ���ѭ����ı�׼����˸�������������ʱȥ���������(���벻��)



	system("pause");
	return 0;
}

