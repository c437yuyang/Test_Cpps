// 44_01_const����ֻ�ܵ���const��Ա����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget {

public:

	int getID() { return id; }

	int id;

};

int main()
{

	const Widget cw;
	//cw.getID(); //����const����ֻ�ܵ���const��Ա��������ʹ��Ա�����������޸Ķ���(���Ծ������޸ĵľ�����Ϊconst��Ա)

    return 0;
}

