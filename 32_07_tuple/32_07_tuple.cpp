// 32_07_tuple.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <tuple>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <iostream>
using namespace std;

int main()
{
	typedef std::tuple<int, string, double> stdTuple;
	typedef boost::tuple<int, string, double> boostTuple;
	stdTuple tp1(10, "s", 1.0);
	//myTp tp1(10, "a"); //std�İ汾��֧��Ĭ�Ϲ���
	boostTuple tp2(10, "a"); //boost�İ汾֧��Ĭ�Ϲ���
	
	
	stdTuple tp3 = tp1; //��������

	int x = 10;
	std::tuple<int &> tp4(x); //���������ã����Ǳ��븽��ֵ

	//��������
	std::tuple<int, string, double> tp5 = std::make_tuple(1, "a", 1.0);

	//cout << tp5.get<0>() << endl; //vs��֧�֡���

	boost::tuple<int, string, double> tp6 = boost::make_tuple(1, "a", 1.0);
	cout << tp6.get<0>() << endl; //boost�İ汾֧��
	//cout << tp6 << endl; //��֧��

	//�ܽ�:���Ǳ����ˣ������ã�һ����˵pair����struct������

	/*tp1[0] = 1;*/ //�����±����

	system("pause");
    return 0;
}

