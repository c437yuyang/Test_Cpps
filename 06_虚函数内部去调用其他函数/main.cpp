#include <iostream>
using namespace std;

class CA {
public:
	virtual void f1() 
	{
		cout << "CA:f1()" << endl;
		f2();
	}
	void f2() {
		cout << "CA:f2()" << endl;
	}
};


class CB :public CA {
public:
	void f1() {
		cout << "CB:f1()" << endl;
		f2();
	}
	 void f2() {
		cout << "CB:f2()" << endl;

	}
};

class CC :public CB {
public:
	virtual void f2() {
		cout << "CC:f2()" << endl;

	}
};
int main()
{
	CC c;
	CA *pA = &c;
	pA->f1(); //f1()�����f2()���þ��ǵ���CB���ڵ��ˣ�����������ĸ����������Ƕ�̬�������ǻ�ȥ�ٴ�CA��ʼ����

	//���CB��f2()��virtual�ľͻ����CC��f2()����

	system("pause");
	return 0;
}