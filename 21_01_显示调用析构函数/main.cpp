#include <iostream>

class Widget
{
public:
	Widget()
	{
		std::cout << "���캯��" << std::endl;
	}

	void PrintInfo()
	{
		std::cout << "hello" << std::endl;
	}

	~Widget()
	{
		std::cout << "��������" << std::endl;

	}
};

int main()
{
	{
		Widget w;
		w.~Widget();
		w.PrintInfo();
	} //���Կ��������������������,���û�������ڴ���Щ��Ҫ�ͷŵ���Դ�Ļ�����ʵ���ã����ᱨ�쳣������ظ��ͷžͻᱨ�쳣��


	system("pause"); 
	return 0;
}