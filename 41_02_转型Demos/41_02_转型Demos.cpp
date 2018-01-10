// 41_02_ת��Demos.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

//��������Ӷ�����exceptional C++ ����44
class A { public: virtual ~A(); };
A::~A() {}

class B :private virtual A {};
class C :public A {};
class D :public B, public C {};

A a1; B b1; C c1; D d1;
const A a2;
const A&ra1 = a1;
const A&ra2 = a2;
char c;

//f()�п�����ÿ�־�ʽת�������滻�ɵ���ʽת��
void f()
{
	A *pa; B *pb; C *pc;

	pa = (A*)&ra2; //��������ȡ��ַ��Ȼ��const��ָ��
	auto p = &ra2; //��auto �ؼ��ֿ��Կ�����p������������const A*
	pa = const_cast<A *>(&ra2); //a2��const����ʹ�����ָ�뽫����δ����Ľ��

	pb = (B*)&c1; //�����C��B�������޹صģ������Ҫʹ��reinterpret_cast
	pb = reinterpret_cast<B*>(&c1);

	pc = (C*)&d1; //D�̳���C ����ֱ���ø����ָ��ָ��
	//��������
	pc = &d1;//�����Ҳ������ת��(����ת��)
	pc = static_cast<C*>(&d1); //static_cast ֻҪ�������й�ϵ�Ϳ���
	pc = dynamic_cast<C*>(&d1); //dynamic_cstҲ��������ת��
	pc = reinterpret_cast<C*>(&d1); //reinterpret_cast ��ǿ��ɶ���ܸ�
}

//�����g()����������ÿ��ת�͵���ȷ��
void g()
{
	//unsigned char * puc = static_cast<unsigned char *>(&c); //������������ȫ����ɵ�����
	//Ӧ��:
	unsigned char * puc = reinterpret_cast<unsigned char *>(&c);

	auto p = &c;
	char * p1;
	//signed char * psc = static_cast<signed char *> (p1); //���ǲ��У������޹أ�������char* �� signed char * Ҳ���޹صġ���

	void *pv = static_cast<void *>(&b1);
	pv = &b1;
	B* pb1 = static_cast<B*>(pv);

	A*pa1 = const_cast<A*>(&ra1); //const_castȥ���������ԣ���ʵ���ַ�����̫�ã�����ͨ��mutable�ؼ���������

	A *pa2 = const_cast<A*>(&ra2); //�ǿ���ȥ����������Ϊa2������const��(��������Գ��������������Ż�)������������ȥ���˺�����ʹ��������󣬻����δ�����ֵ

	B *pb3 = dynamic_cast<B*>(&c1); //����ʱ��dynamic_cast���pb3��ֵ����ΪNULL,��Ϊ������û�й�ϵ��ʵ������ʵ��Ҫת���Ļ�ֻ��ʹ��reinterpret_cast

	//A *pa3 = dynamic_cast<A*> (&b1); //������Ȼb��A�̳У����ǲ���public�̳У���˱�������g()�����B�� ��Ԫ�������ɡ�������reinterpret_cast��Ȼ���ԣ�����Ͳ�˵�ˡ�





}


int main()
{

	f();
	g();
	return 0;
}

