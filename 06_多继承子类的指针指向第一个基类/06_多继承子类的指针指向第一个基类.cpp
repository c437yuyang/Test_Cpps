// 06_��̳������ָ��ָ���һ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class ParentA {

};
class ParentB {

};

class Derived :public ParentA,public ParentB
{

};
int main()
{

	Derived *pD = new Derived();
	ParentA *pA = (ParentA*)pD;
	ParentB *pB = (ParentB*)pD;

	std::cout << pD << std::endl; //ǰ������ȿ��Կ���
	std::cout << pA << std::endl;//�����Ǻ͵�һ������ĵ�ַ��ͬ
	std::cout << pB << std::endl;

    return 0;
}

