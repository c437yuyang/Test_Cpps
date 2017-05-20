//
//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//
//
//int main()
//{
//	int N;
//	int i, j;
//	int s;
//
//	scanf("%d", &N);
//
//	int **a = (int **)malloc(sizeof(int) * N); //N��ָ��--����ռ�
//	if (a == NULL)
//		return 0;
//
//	//��ÿ�з���ռ�
//	for (i = 0; i < N; i++)
//	{
//		if (NULL == (a[i] = (int *)malloc(sizeof(int) * N)))
//		{
//			//ע�⣬����ռ�ʧ�ܵĻ����������Ƿ��أ���Ҫ�ͷŵ�֮ǰ�����
//			while (i--)
//				free(a[i]);
//			free(a);
//			return 0; //����ռ�ʧ�ܣ�����Ŷ
//		}
//	}
//
//	//��ֵ
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			s = i + j;
//			//if (s < N) //�ϰ���
//			//{
//			//	a[i][j] = s * (s + 1) / 2 + (s % 2 == 0 ? i : j);
//			//}
//			//else //�°���
//			//{
//			//	s = (N - 1 - i) + (N - 1 - j);
//			//	a[i][j] = N * N - s * (s + 1) / 2 - (N - ((s % 2 == 0 ? i : j)));
//			//}
//
//			if (s < N)
//			{
//				a[i][j] = s * (s + 1) / 2 + (s % 2 == 0 ? i : j);
//			}
//			else
//			{
//				s = (N - 1 - i) + (N - 1 - j);
//				a[i][j] = N * N - s * (s + 1) / 2 - (N - ((s % 2 == 0 ? i : j)));
//			}
//
//
//		}
//	}
//
//	//��ӡ���
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//
//	getchar();
//	getchar();
//	return 0;
//}




#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int N;
	int s, i, j;
	int squa;
	scanf("%d", &N);
	int **a = (int **)malloc(N * sizeof(int));
	if (NULL == a)
	{
		return 0;
	}
	//�ռ����
	for (i = 0; i < N; i++)
	{
		if (NULL == (a[i] = (int*)malloc(N * sizeof(int))))
		{
			while (--i >= 0)
			{
				free(a[i]);
			}
			free(a);
			return 1;
		}
	}
	squa = N * N;
	//���Ӧλ����Ӧ��д��ֵ
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			s = i + j;

			if (s < N)//������
			{
				s = i + j;//Ϊ�˿��ĸ�����������������������ԳƵ����    
				a[i][j] = s * (s + 1) / 2 + ((0 == (i + j) % 2) ? i : j);
			}
			else//������
			{
				s = (N - 1 - i) + (N - 1 - j);
				a[i][j] = squa - s * (s + 1) / 2 - (N - ((0 == (i + j) % 2) ? i : j));
			}
		}
	}
	//��ӡ���
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}