// 53_01_try_catch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using std::stack;


int main()
{

	stack<int> s;
	s.push(1);

	s.pop();
	//s.pop(); //��ʱVS�ᱨassertion failed ��������Ļ����ͻ���ʾ������һ���ϵ㡣
	//�����release�Ļ��Ͳ��ᱨ������


	
	try //tryס�Ļ�Ҳ���У�������������Ա���C# �����׳����쳣��˵��STL��ʵ�ֲ���ͨ���쳣��
	{
		//s.pop(); //stl��Pop���ǲ�����ֵ�ģ����ǵ��Լ�ȥ��top��ȡ��Ϊ���쳣��ȫ�ԣ�����μ�exceptional c++  ����10
		////��ȻC#��java�е�pop���ǿ���ֱ�ӷ��صġ�
		//s.top(); //���Կ���top���ص������ã������ڲ���ʵ����
	}
	catch (...)
	{
		throw;
	}

	//����throw
	{
		if (true)
		{
			throw "aa"; //throw��ʱ��ᵯ����ʾ��(ò��ֻ��debug����)����������������ִ�У�������жϾͲ�����
		}
		std::cout << "aaa" << std::endl; //
	}

    return 0;
}

