// 03_abort��exit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdlib> //exit��abort, calloc ��malloc����Ҳ�ǰ��������ͷ�ļ������

int main()
{

	//system")

	//abort(); //�ᵯ��������ʾ
	exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);

	calloc(10, 4);

	system("pause");
    return 0;
}

