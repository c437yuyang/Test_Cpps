#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	const int *p = NULL; //�ײ�
	int const *p1 = NULL; //ͬ��Ҳ�ǵײ�
	int * const p2 = NULL;//�������Ƕ���

	//���е�����(һ��A(3,3)=6��)
	const int *p4 = NULL;
	const * int p5 = NULL;
	int const * p6 = NULL;
	int * const p7 = NULL;
	*int const p8 = NULL;
	*const int p9 = NULL;
	//�ܽ�:����int������*��߲������int *���ͣ���ֻ��3�ֿ�����

	//const��*����⣬ָ����ָ������ݲ��ɱ䣬��*p���ɱ䣻
	// ����ı����ָ��p������p++��֪��ָ��ָ�����������*p��û���õ�ֵ
	//	const��*���Ҳָ࣬�벻�ɱ䣬��p++��������


	system("pause");
    return 0;
}
