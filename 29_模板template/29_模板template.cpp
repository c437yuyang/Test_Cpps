// 29_ģ��template.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class fooo {
public:
	template<class T>
	void func(T) {
		cout << typeid(T).name() << endl;
	}
};

//����ģ������ɱ��������ݳ���Ա�ĵ�������ʵ����Ϊ��ִ�еĺ�����

//����һ��ʵ�����˵���ģ�壬���Ա����ֻ����ʹ��ʱ�ű�ʵ������
//���һ����Ա����û�б�ʹ�ã��������ᱻʵ������

int main(int argc, char * * argv) 
{
	fooo f;
	f.func<int>(100);
	system("pause");
	return 0;
}



