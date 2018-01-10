// 42_02_char_traits.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <assert.h>
#include <iostream>
//char_traits�������ַ���Ľ�����ʽ�������ṩeq,lt,compare��find�ĸ���������ʵ�ṩ�Ļ��ܶ࣬�������F12��Դ��
//���������ʵ��һ����Сд�����е�ci_string��

struct ci_char_traits :public std::char_traits<char>
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2) || tolower(c1) == tolower(c2);
	}
	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
	static int compare(const char *s1, const char *s2,size_t n)
	{
		return _memicmp(s1, s2, n);
	}

	static const char * find(const char*s, int n, char a)
	{
		while (n-- > 0 && toupper(*s) != toupper(a))
		{
			++s;
		}
		return n >= 0 ? s : 0;
	}

	//std::ostream& operator<<(std::ostream & os) //��Ϊstd::cout ʵ������ std::basic_ostream<char,std::char_traits<char>>���������಻����cout�����(Ҳ������.c_str()��ʵ��)�����Ե��Լ���д
	//{
	//	//����ʵ�ֲ��ܣ�ֻ�����·��
	//}

};
typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream& operator<<(std::ostream & os,ci_string str)
{
	return os << str.c_str(); //���������� os << str.c_str()���У�ֱ�ӵ���os << str ֮���Բ���������Ϊ�ݹ����������
}


//��Ȼ������ֻ����ʾ�����ʹ�ã�ʵ���ϲ��ʺϰ������Сд����������Ϊ�����������ʵ�֣�����stricmpҲ����Ϊ������������ʵ�ֵ�(���忴���ϵ�����)
int main()
{

	ci_string s1 = "abcde";
	ci_string s2 = "ABCde";

	assert(s1 == s2);
	std::cout << s1 << std::endl; //



	system("pause");
    return 0;
}

