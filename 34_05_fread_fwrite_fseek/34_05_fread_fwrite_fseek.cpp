// 34_05_fread_fwrite_fseek.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdio.h>

int main()

{

	FILE *fp;  //����һ���ļ�ָ��fp

	int i, a[6] = { 1,2,3,4,5,6 }, k;  //�����������ʱ����

	fp = fopen("data.dat", "w+b");  //��һ���ɶ���д�ļ�������ļ��������򴴽�֮���Զ����Ƶķ�ʽ����

	for (i = 0; i < 6; i++)  //ѭ������

	{

		fseek(fp, 0L, 0);  //���ļ�ָ��ָ���ļ��Ŀ�ͷ,���ÿ�ζ�д�����ʼ

		fwrite(&a[5 - i], sizeof(int), 1, fp);  //������Ӻ��濪ʼ���ַ�����д�뵽fp��ָ���ļ���

	}

	rewind(fp);//���ļ�ָ��ָ���ļ��Ŀ�ͷ

	fread(&k, sizeof(int), 1, fp);  //��ȡ�ļ��е�һ��int�����ݣ�д�뵽k������

	fclose(fp);  //�ر��ļ�ָ��

	printf("%d", k);  //��ӡk��ֵ1
	getchar();
	return 0;
}

