#include<iostream>
using namespace std;

class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}

	int foo(char x[14])
	{
		return sizeof(x) + 10;
	}
};

class Derived : public Base
{
	int foo(int x) //��������virtual���η��ģ����Զ�̬�󶨵�ʱ����������ĺ���
	{
		return x * 20;
	}

	virtual int foo(char x[10]) //�����virtualû�ã������ʱ������۷�
	{
		return sizeof(x) + 20;
	}
};

int main()
{
	Derived stDerived;
	Base *pstBase = &stDerived;

	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x)); 
	system("pause");
	return 0;
	//�ܽ�:
	//1.һ����Ķ���ָ���˵�ʱ��϶����ø���ĺ�����û��ʲô��̬�󶨲���
	// 2.����Base *pstBase = &stDerived���ָ���ָ��ָ�������ʱ�򣬳��ֶ�̬��
	// ��ʱ����virtual�������������ĺ�����������virtual�Ͳ��ᶯ̬�󶨣���ʲôָ��͵�ʲô����
	// ���������Ǹ���ָ��͵��ø���ĺ���
}