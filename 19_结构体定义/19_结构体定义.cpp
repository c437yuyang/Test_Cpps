// 19_�ṹ�嶨��.cpp : �������̨Ӧ�ó������ڵ㡣
//



#include "stdafx.h"
#include <iostream>
using namespace std;


struct student1
{
	int no;
	char name[10];
	float score;
};

//struct stud[20]  //��
//{
//	int no;
//char name[10];
//float score;
//};

struct student2
{
	int no;
	char name[10];
	float score;
} stud2[20];  //Ҳ��,����ṹ�岢����һ��[20]������


struct
{
	int no;
	char name[10];
	float score;
}stud3[100]; //Ҳ�ԣ�������ʾ���ʽṹ�壬���Ƕ�����[100]������


typedef struct student4
{

}stud4; //c++��C��������typedef����stud4��һ�����ͱ�����ֻ��c++Ҳ���Բ���struct��ֱ�ӷ������ͣ�����c++����typedef������ô����

//http://blog.csdn.net/itguangit/article/details/50117295

int main()
{

	//���ڵ�һ�ֶ��壬struct student1��student�����ԣ�C�������ָ��struct student1 xxx
	student1 stu1;
	student2 stu2;
	stud2[1].name;  //����ǰ������������
	stud3[1].no; //����ǰ������������

	system("pause");
	return 0;
}
