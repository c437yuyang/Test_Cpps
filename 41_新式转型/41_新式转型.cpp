// 41_��ʽת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void doSomething(double &d) {}

class  Widget
{
public:
	Widget();
	virtual ~Widget();

private:

};

class SpecialWidget :public Widget {};

class SpecialWidget1 {};

Widget::Widget()
{
}

Widget::~Widget()
{
}

int main()
{

	// 1.static_cast�����ھ�ʽת�ͣ����ǲ���ȥ��������(ֻ�ǵײ�const����ȥ��)
	double d = static_cast<double>(5);
	double d1 = 1.1;
	const double d2 = static_cast<const double>(d1); //���Լ��ϳ�����

	double dd = static_cast<double>(d2); //��ͨconst�Ͷ���const�ǿ���ȥ����
	double * const p1 = &d;
	double * p2 = static_cast<double *>(p1);

	const double * p3 = &d;
	//double *p4 = static_cast<double *>(p3); //��������ȥ���ײ�const


	// 2.const_cast���Ƴ������ԣ������ײ�const
	const double d3 = 1.1;
	doSomething(const_cast<double&>(d3));

	// 3.dynamic_castʵ�����°�ȫת�ͣ��ɸ���ָ������ת��
	Widget *w = new SpecialWidget;
	//SpecialWidget *w1 = w;//����
	SpecialWidget *w1 = dynamic_cast<SpecialWidget*>(w); //Ҫ�����ͱ�����ж�̬����(�麯��)
	//SpecialWidget1 *w11 = dynamic_cast<SpecialWidget*>(w); //û�м̳й�ϵҲ����ת��


	// 4.reinterpret_castʵ�ֵͼ�ת�ͣ�����pointer to int ת int,����int*ֱ��ת����char *,ת�����Ǻ�Σ�յ�
	int *p1 = new int(10);
	//int i = p1; //����
	int i = reinterpret_cast<int>(p1); //��ӡ��������ָ��ĵ�ֵַ

	// 5.�����ĸ�������dynamic_cast��ʽ�����޷�ʵ��(Ҳ����ת��ֻ�ǲ�����Ƿ������ȷ��ת��)
	// ��ʽ����������ʵ��

	cout << i << endl;

	return 0;
}

