#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main() {

	cout << sizeof(bool) << endl; //可以看到bool类型占一个字节，而下面的BOOL是封装的int所以占4个字节
	cout << sizeof(int) << endl;
	cout << sizeof(BOOL) << endl;
	system("pause");
}