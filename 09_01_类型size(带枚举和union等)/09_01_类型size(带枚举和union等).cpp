// 09_01_����size(��ö�ٺ�union��).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//�ܽ�:


//��������
//1�����ݳ�Ա������򣺽ṹ(struct)(������(union))�����ݳ�Ա����һ�����ݳ�Ա����offsetΪ0�ĵط���
//�Ժ�ÿ�����ݳ�Ա�洢����ʼλ��Ҫ�Ӹó�Ա��С���߳�Ա���ӳ�Ա��С
//��ֻҪ�ó�Ա���ӳ�Ա������˵�����飬�ṹ��ȣ�����������ʼ(����int�ڣ���λ��Ϊ���ֽ�, ��Ҫ�ӣ�����������ַ��ʼ�洢)
//�������Ͳ�����struct/class/uinon

//2���ṹ����Ϊ��Ա�Ķ������:���һ���ṹ����ĳЩ�ṹ���Ա, ��ṹ���ԱҪ�����ڲ�"���������ͳ�Ա"����������ַ��ʼ�洢.
//(struct a�����struct b, b����char, int, double��Ԫ��, ��bӦ�ô�8����������ʼ�洢.)��
//
//3����β���� : �ṹ����ܴ�С, Ҳ����sizeof�Ľ��, .���������ڲ�����Ա��"���������ͳ�Ա"��������.�����Ҫ����.
//(�������Ͳ�����struct / class / uinon / ����)��
//
//4��sizeof(union)���Խṹ����size���Ԫ��Ϊunion��size, ��Ϊ��ĳһʱ�̣�unionֻ��һ����Ա�����洢�ڸõ�ַ��(��ȻҪ�����ڴ����)


//һЩ˵��
//1.�麯��һ����һ���ͻ�ռ��4�ֽڣ�ȥָ���麯�������ǲ������������麯������ֻռ�����ֽ�
//2.��Ա������ռ�ֽڴ�С
//3.δʵ��������ָ�벻ռȡ�ֽ�
//4.ö������ռȡ4���ֽ�
//5.ָ�����ͺ��麯��ָ�붼�ǿ��Գ䵱��С��Ԫ�ģ�������Ϊ4�ֽڣ�����struct / class / uinon���ǻ�������
//6.��Ա���ж����ʱ���ǿ��������͵Ĵ�С�������������struct�Ͳ��ǻ�������
//7.�������ͺ������õ�����һ��
//8.��Ϊ�յ�ʱ��ռһ���ֽ�
//9.����̳и���Ĵ�С�Ļ����ϣ������Լ���Ա�Ĵ�С��ͬ����Ա����ֱ���滻��Ҳ��׷�ӣ���Ϊ���ʶ����Է���Base::xxx���������Ĵ�Сֻ�������ܼ�
//10.union����sturct����ö��������������ڲ������ֻ�Ƕ��壬����ʵ����һ������Ļ����ǲ�ռȡ�ֽڵ�
//11.�������飬ֱ�Ӳ�ռ�ֽڣ����ֻ��һ�����������Ա����ֱ�����Ϊ�գ���ռһ���ֽ�
//12.static��Ա�����Ǵ�С
//13.�ڴ����涨���ṹ����ܴ�СΪ�ṹ�����������ͳ�Ա��С��������,�������ʽֻ�Ƕ�����ݷ���һ����ѡ�
//14.��ס�ṹ����ÿһ����Ա��ÿһ����Ա�������Ա���ǰ���union��struct���ڣ�����ʼ��ַҪ�� �ó�Ա��С����������

int main()
{
	//case1
	{
		class A
		{
		public:
			int i; //4
			union U
			{
				char buff[13];
				int i;
			}uu; //16 union Uʵ����Ϊuuռȡ16���ֽڣ�char����ռ13���ֽڣ�����Ϊ�������Ϊint������ռȡֻ��Ϊ4�ֽڵ�����������С16�ֽڣ�
			void foo() {    } //������ռ
			typedef char* (*f)(void*); //δʵ����ָ�벻ռ
			enum { red, green, blue }; //����һ��δ����ö�ٵ���ʵ��������ռ�ֽ�
			enum direction {
				up, left, right, bottom
			} u, l, r, b; //����һ��ö���࣬�ٶ����ĸ�ö�ٱ�����16�ֽ�
		};

		class A1
		{
			char c;
			int *pInt; //��СΪָ�룬���ֽڣ������ܹ�8
		};

		cout << sizeof(A) << endl; //36
		cout << sizeof(A1) << endl; //8
		cout << sizeof(A::direction) << endl; //4
	}

	//case2 union������Ϊ��Ա
	{
		typedef union {
			long i;
			int k[5];
			char c;
		} DATE;

		struct data {
			int cat; //4
			DATE cow; //  20
			double dog; //8
			char c;//1�����ȫ��8
		} too;

		cout << sizeof(DATE) << endl; //20,union�������Ԫ��Int[5]��Ϊ20���������ʱ���ǿ���С����Ԫ�صĴ�С������������ǿ�long�Ĵ�С�����ж���
		cout << sizeof(too) << endl;//40,�����ʱ���ǿ���С����Ԫ�صĴ�С��������double���Ͱ���8�ı�����
	}

	//case3 �麯��ָ��demo1
	{

		class P  //�麯��һ����һ���ͻ�ռ��4�ֽڣ�ȥָ���麯�������ǲ������������麯������ֻռ�����ֽ�
		{
		public:
			virtual ~P() = 0;
			virtual void printInfo() {};
		};

		class P1 : public P
		{
		public:
			//virtual ~P1() = 0; //������������һ���������麯�����Ӻ��������麯����

		};

		cout << sizeof(P) << endl;//4
		cout << sizeof(P1) << endl;//4
	}


	//case4 �麯��ָ��demo2
	{
		class X {
		public:
			virtual void printInfo() = 0;
			char c;
		};

		class X1 :public X {
		public:
			/*virtual void printInfo();*/
		};

		cout << sizeof(X) << endl; //8 �麯��ָ��Ҳ�䵱�������ͣ�Ȼ��charΪ1����󲹳�
		cout << sizeof(X1) << endl; //8
	}

	//case5 ������Ϊ��Ա,����Ӱ����룬���뻹�ǿ��������͵Ĵ�С
	{
		struct {
			char a[10]; //10
			int b; //4 ����Ҫ�Ȱ���4���������ƶ���12��ʼ
			short c[3]; //6 ����������Ҫ����Ϊ4��������
		}X;

		cout << sizeof(X) << endl; //24,
	}
	
	//case6�����͵Ĵ�С
	{
		class A {};
		class C { void printInfo() {}; };
		class D { int a; void printInfo() {}; };
		class E { int a; void printInfo() {}; char c; short s; };
		class F { char c; };
		class G
		{
		public:
			int a;
			int a1[0];
		};//��������,����ṹ���С�ɱ�

		class G1
		{
		public:
			int a;
			char b;
			int a1[0];
		};

		class G2
		{
		public:
			int a1[0];
		};

		cout << sizeof(A) << endl; //1 ������Ϊ1
		cout << sizeof(C) << endl; //1����Ա������Ӱ���С
		cout << sizeof(D) << endl; //4
		cout << sizeof(E) << endl; //8
		cout << sizeof(F) << endl; //1 ��Ȼ��1��������һ��char��û��charռ�ô�С��һ����
		cout << sizeof(G) << endl; //4������������ֱ�Ӳ�����(�ͳ�Ա����һ��)���ɼ���û�����Ӵ�С
		cout << sizeof(G1) << endl; //8���ɼ���û�����Ӵ�С
		cout << sizeof(G2) << endl; //4���ɼ���û�����Ӵ�С

	}


	//case7����demo
	{
		class A
		{
			int a;
			short b;
			int c;
			char d;
		};
		class B
		{
			double a;
			short b;
			int c;
			char d;
		};
		cout << sizeof(A) << endl; //16,���Ĳ����ǰ������������ݳ�Ա
		cout << sizeof(B) << endl; //24

		cout << sizeof(int *) << endl;
	}


	//case8 λ������
	{
		//ָ��λ��xyzһ��ռ��һ���ֽ�
		struct s
		{
			int x : 3;
			int y : 4;
			int z : 5;
			int x1 : 3;
			int x2 : 17; //ֻҪǰ�治����һ��intռ���ֽ�(32λ)���͹���һ��int�ĳ���
						 //����17�����8��18�����12
			int num1;
		};
		cout << sizeof(s) << endl; //8,ǰ��xyz,x1,x2����һ���ֽ�
	}


	//case 9 �����union
	{
		struct stu
		{
			union
			{
				char bj[5];
				short bh[2];
			} demo;
			char xm[8];
			float cj;
		}xc;
		cout << sizeof(stu::demo) << endl;//6 ,��Ϊchar����ռ��5���ֽڣ�short����ռ��4���ֽڣ�������������short������2�ı�����䣬ռ��6
		std::cout << sizeof(stu) << endl; //20, unionռ��6���ֽڣ�����������������float����˰���4�ı������ж��룬ռ��6+2,char����պ�8��floatռ��4���ֽڣ�����8+8+4=20
	}


	//case 10 union���ڴ����
	{
		union
		{
			int m, n, y;
			char arr[5];
		} mm;
		cout << sizeof(mm) << endl; //8 ��Ȼ����Ա��5������Ҫ����������������int��Ȼ������ڴ����


	}


	system("pause");
	return 0;
}
