// 29_ģ��template.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class fooo {
public:
	template<class T> //����ģ�壬���õ�ʱ��������Ը��ݲ��������ƶϵõ����ͣ���ô���Բ�ָ�����ͽ��е���
	void func(T) 
	{
		cout << typeid(T).name() << endl;
	}

	template<class T> //����ģ�壬���õ�ʱ��������ܸ��ݲ��������ƶϵõ����ͣ���ô����ָ�����ͽ��е���
	void func1(int i)
	{
		cout << typeid(T).name() << endl;
	}

};

template <class T>
class Widget 
{
public:
	void printfInfo() 
	{
		cout << t << endl;
	}

	T t;
};

//����ģ������ɱ��������ݳ���Ա�ĵ�������ʵ����Ϊ��ִ�еĺ�����

//����һ��ʵ�����˵���ģ�壬���Ա����ֻ����ʹ��ʱ�ű�ʵ������
//���һ����Ա����û�б�ʹ�ã��������ᱻʵ������

int main(int argc, char * * argv) 
{
	fooo f;
	f.func(100);
	f.func<double>(100.0); //����ģ�壬���õ�ʱ��������Ը��ݲ��������ƶϵõ����ͣ���ô���Բ�ָ�����ͽ��е���
	//f.func1(100); //�������ܸ��ݲ��������ƶϵõ�ģ�����͵�ʱ�����ָ������
	f.func1<double>(100); //���double


	//Widget w; //������ģ�����ָ��ģ������
	Widget<int> w1;
	w1.printfInfo();

	system("pause");
	return 0;
}



