
//�ο��� More Effective C++
//4.4 M8:operator new �� new operator
// 1.new һ�������ʱ�򣬵��õ���new operator,�����ϵͳ�Ĳ������������޸�
// 2.new Widget()  (��ʱ���ǵ��õ�new operator)���ڲ������operator new,�ٵ��ù��캯��������
// operator new�����þ�������malloc����������ڴ棬������ȫ�͹��캯���޹�
// 3.placement new�������Ƕ����Ѿ�����õ�raw�ڴ棬��ʽ���ù��캯����������ٷ�����ָ��
// 4.�����Ҫ���ƶѶ��󴴽����ڴ������̣�������дoperator new

//��������https://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html

//new operator/delete operator����new��delete����������operator new / operator delete�Ǻ�����
//
//new operator
//��1������operator new�����㹻�Ŀռ䣬��������ض���Ĺ��캯��
//��2�������Ա�����
//
//operator new
//��1��ֻ������Ҫ��Ŀռ䣬��������ض���Ĺ��캯�������޷�������Ҫ�����Ŀռ�ʱ����
//->�����new_handler�������new_handler������
//->���ûҪ���׳��쳣����nothrow����������ִ��bad_alloc�쳣������
//->����0
//��2�����Ա�����
//��3������ʱ���������ͱ�������Ϊvoid*
//��4������ʱ����һ���������ͱ���Ϊ���Ҫ�����ռ�Ĵ�С���ֽڣ�������Ϊsize_t
//��5������ʱ�����Դ���������
//
//delete �� delete operator���ƣ�delete operator�ȵ��������������ٵ���operator deleteɾ���ڴ�
//
//new operator��delete operator����Ϊ�ǲ��ܹ�Ҳ��Ӧ�ñ��ı䣬����C++��׼�����ĳ�ŵ��
//��operator new��operator delete��C�����е�malloc��free��Ӧ��ֻ������估�ͷſռ䡣
//��ʹ��operator new����Ŀռ����ʹ��operator delete���ͷţ�������ʹ��free����Ϊ���Ƕ��ڴ�ʹ�õĵǼǷ�ʽ��ͬ��
//����������һ�������������operator new��operator delete��ʵ�ֶ��ڴ����Ĳ�ͬҪ��
//���㲻������new operator��delete operator�Ըı����ǵ���Ϊ��
//
//Ϊʲô�б�Ҫд�Լ���operator new��operator delete��
//��ͨ���ǣ�Ϊ��Ч�ʡ�ȱʡ��operator new��operator delete���зǳ��õ�ͨ����
//�������������Ҳʹ����ĳЩ�ض��ĳ����£����Խ�һ��������������.
//��������Щ��Ҫ��̬��������ĵ���С�Ķ����Ӧ�ó�������������ˡ�
//����ɲο���Effective C++���еĵڶ����ڴ����

#include "stdafx.h"
#include <iostream>
#include <string>
#include <new>
using namespace std;

class X
{
public:
	X() { cout << "constructor of X" << endl; }
	~X() { cout << "destructor of X" << endl; }

	static void* operator new(size_t size) //operator new Ӧ������Ϊ��̬(��ʹû��ʹ��static����������������Ȼ�Ǿ�̬�ģ�����ʹ�����Ȼ���ֵø��麯��һ��),������operator new�Ļ���Ҫ������Ӧ��operator delete
	{
		cout << "operator new size: " << size << endl;
		return ::operator new(size);
	}

	static void* operator new(size_t size, string str) //��������,������Ϊ����placement new����operator new��һ������汾�����������operator new�Ͳ���ʹ��placement new��
	{
		cout << "operator new size " << size << " with string " << str << endl;
		return ::operator new(size);
	}

	static void operator delete(void* pointee)
	{
		cout << "operator delete" << endl;
		::operator delete(pointee);
	}

	static void operator delete(void* pointee, string str) //���������ʵһ������²��ᱻ����,ֻ�е����캯�����쳣��ʱ��Ż���ö�Ӧ������汾
		//�������������汾���ڶ�Ӧ�汾��operator new ���쳣��ʱ��͸����������������������
		//����ֻ�е����쳣��ʱ������汾�����òŻ����ֳ�����
		//�ο���:https://www.cnblogs.com/cly-blog/p/5984660.html
	{
		cout << "operator delete with string" << endl; 
		::operator delete(pointee);
	}



private:
	int num;
};

int main()
{
	X *px = new("A new class") X;
	X *px1 = new X;
	delete px; //���ǻ���õ������汾��operator delete
	delete px1;

	X*px2 = (X *)operator new(sizeof(X)); //���õ�ȫ�ֵ�
	X*px3 = (X *)X::operator new(sizeof(X)); //���õ�X�ľ�̬����
	
	//������������operator new������£���û�������������? (����ʹ��placement new��)
	//���ǿ���ʹ��new operator������������������������ڵ��Ժ�����
	//X* px4 = new((void *)px3) X();

	//�μ�:http://blog.csdn.net/wudaijun/article/details/9273339

	return 0;
}
