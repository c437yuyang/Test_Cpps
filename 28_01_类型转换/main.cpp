
#include <iostream>
using namespace std;

int main()
{
	//todo:��֪��Ϊɶ
	signed char a = 0xe0;
	unsigned int b = a;
	unsigned char c = a;
	unsigned char d = 0xe0;

	//����������C������������е�һ��涨���ڱ��ʽ����ʱ�������Ƚ��������������ȣ�����int����С�����ͣ�char,
	//signed char, unsigned char, short, unsigned short�ȣ�����Ҫ����Ϊint���ͣ�Ȼ����ִ�б��ʽ�����㡣

	cout << (c == a) << endl;//false,
	//����֮������false,����Ϊchar�����ڱȽϵ�ʱ�򣬻�ת�ͳ�int,����ת�ͳ�Int�Ĺ����У��ͳ����˲�һ����
	//�����������
	unsigned int i1 = c;
	signed int i2 = a;

	cout << (b == a) << endl;//true

	cout << (a == d) << endl;//false
	unsigned char e = a;


	signed int a1 = 0xe0000000;
	unsigned int b1 = a1;
	cout << (b1 == a1) << endl; //true

	signed int a2 = 0x01;
	unsigned int b2 = a2;
	cout << (b2 == a2) << endl;//true


	system("pause");
	return 0;
}
