#include <iostream>
using namespace std;

int main()
{
	

	char p1[100];
	sprintf(p1, "%d", 20);

	FILE *pFile = fopen("1.txt","w");
	fprintf(pFile, "%d,%d", 20, 21);
	fclose(pFile); //b����Ҫfclose��������������ʾˢ��һ�»�����
	cout << p1 << endl;
	system("pause");
}
