#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	const int *p = NULL; //�ײ�
	int const *p1 = NULL; //ͬ��Ҳ�ǵײ�
	int * const p2 = NULL;//�������Ƕ���

	//const��*����⣬ָ����ָ������ݲ��ɱ䣬��*p���ɱ䣻
	// ����ı����ָ��p������p++��֪��ָ��ָ�����������*p��û���õ�ֵ
	//	const��*���Ҳָ࣬�벻�ɱ䣬��p++��������

	system("pause");
    return 0;
}
