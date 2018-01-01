#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void TestCriticalPath();
int main()
{
	TestCriticalPath();

	int nTestTime = 10000000000000;
	DWORD timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; ++i)
	{
		;
	}
	cout << "++i��ʱ:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		;
	}
	cout << "i++��ʱ:" << (GetTickCount() - timeStart) << endl;


	//����Ҫע�⣬++i���ص���i�����ã���ֵ
	//��i++���ص���i��ֵ�ĸ��������ܵ���ֵ

	int i = 0;
	(++i) += 1;
	//(i++) += 1; //����������ֵ
	cout << i << endl; //2
	system("pause");
	//��������,���˹�һ���ľ�Ȼi++���죡����������ƽʱ����i++�ɣ�
}


double Poly1(double arr[], double x, long degree)
{
	long i;
	double result = arr[0];
	double xpwr = x;
	for (i = 1; i <= degree; ++i)
	{
		result += arr[i] * xpwr;
		xpwr = x * xpwr;
	}
	return result;
}

double Poly2(double arr[], double x, long degree)
{
	long i;
	double result = arr[degree];
	for (int i = degree - 1; i >= 0; --i)
	{
		result = arr[i] + x*result;
	}
	return result;
}

//����CSAPP���ϵ���ϰ��5.5��5.6 ��������ʱ���Լ���Ϊ���Ż���ʵ�Ǵ����
void TestCriticalPath()
{
	double arr[] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	long degree = 7;
	double x = 3.14151231;
	int nTestTime = 10000000000000;

	DWORD timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; ++i)
	{
		double d = Poly1(arr, x, degree);
	}
	cout << "poly1��ʱ:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		double d = Poly2(arr, x, degree);
	}
	cout << "poly2��ʱ:" << (GetTickCount() - timeStart) << endl;

}