// 47_01_11�±�׼�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <random>
#include <iostream>
using namespace std;

int main()
{
#pragma region ����1,�ͺ���ǰ��rand���
	//std::default_random_engine e;

	//for (size_t i = 0; i < 10; i++) {
	//	cout << e() << endl;
	//}
	//Ĭ������£�����������������Χ��default_randm_engine::min()��default_random_engine::max()֮�䡣
#pragma endregion

#pragma region ��2:����5-20�ľ��ȷֲ�
	//std::default_random_engine e;
	//std::uniform_int_distribution<int> u(5, 20); //ע����int,double�ᱨ��
	////int��Ҳ���Բ���unsigned���͵�
	//std::uniform_real_distribution<double> u_d(2.0, 30.0);
	//for (size_t i = 0; i < 10; i++) {
	//	//cout << u(e) << endl;   //ע��,���ݵ���e����
	//	cout << u_d(e) << endl;
	//}
#pragma endregion


#pragma region gamma�ֲ�
	std::default_random_engine e;
	std::gamma_distribution<> u(1.0, 2.0);
	for (size_t i = 0; i < 10; i++) {
		cout << u(e) << endl;   //ע��,���ݵ���e����
	}
#pragma endregion



	system("pause");
    return 0;
}

