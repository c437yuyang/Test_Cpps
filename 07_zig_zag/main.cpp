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
//	int **a = (int **)malloc(sizeof(int) * N); //N行指针--分配空间
//	if (a == NULL)
//		return 0;
//
//	//给每行分配空间
//	for (i = 0; i < N; i++)
//	{
//		if (NULL == (a[i] = (int *)malloc(sizeof(int) * N)))
//		{
//			//注意，分配空间失败的话，不仅仅是返回，还要释放掉之前申请的
//			while (i--)
//				free(a[i]);
//			free(a);
//			return 0; //分配空间失败，返回哦
//		}
//	}
//
//	//赋值
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			s = i + j;
//			//if (s < N) //上半区
//			//{
//			//	a[i][j] = s * (s + 1) / 2 + (s % 2 == 0 ? i : j);
//			//}
//			//else //下半区
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
//	//打印输出
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
	//空间分配
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
	//求对应位置上应填写的值
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			s = i + j;

			if (s < N)//上三角
			{
				s = i + j;//为了看的更清楚，这里加了这条与下面对称的语句    
				a[i][j] = s * (s + 1) / 2 + ((0 == (i + j) % 2) ? i : j);
			}
			else//下三角
			{
				s = (N - 1 - i) + (N - 1 - j);
				a[i][j] = squa - s * (s + 1) / 2 - (N - ((0 == (i + j) % 2) ? i : j));
			}
		}
	}
	//打印输出
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