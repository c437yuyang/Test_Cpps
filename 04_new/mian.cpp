#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

class A
{
public:
	A() { cout << "AĬ�Ϲ��캯��!" << endl; }
	A(int i) :m_a(i) { cout << "A��1���������캯��" << endl; }
	A(int i,int j) :m_a(i),m_b(j) { cout << "A��2���������캯��" << endl; }

	int m_a;
	int m_b;
	~A() { cout << "A��������!" << endl; }
};


int main()
{
	int *p1 = new int[10]; //δ���г�ʼ�� 
	int *p3 = new int[10](); //�����ţ�����Ĭ��ֵ��ʼ��
	int *p2 = new int[10]{ 1,2,3,4,56 }; //�б��ʼ���������Ľ���ֵ��ʼ��

	//A *pA = new A[5](10); //����
	A *pA = new A[5](); //����5��Ĭ�Ϲ��캯��,new���治�ܵ��ô������Ĺ��캯��!
	cout << endl;
	A *pA4 = new A[5];//Ҳ�ǵ���5��Ĭ�Ϲ��캯��
	A *pA3 = new A; //����Ĭ�Ϲ��캯��
	A *pA1 = new A(10); //���ǵ��������ʱ����Ե��ô������Ĺ��캯��
	cout << pA1->m_b << endl; //���Կ�����Ĭ�ϳ�ʼ����Ϊδ�����ֵ��
	A *pA2 = new A(10, 20);


	int *p4 = new int(10);
	cout << *p4 << endl;
	//�����������ͣ�new���������deleteҲ����delete[]
	//���Ƕ�����������,delete��delete�Ͳ��ܻ�����

	A *pA5 = new A[5];
	delete []pA5; //����delete�Ļ����ᱨ������delete[] ��������ι��캯������������

	system("pause");
}