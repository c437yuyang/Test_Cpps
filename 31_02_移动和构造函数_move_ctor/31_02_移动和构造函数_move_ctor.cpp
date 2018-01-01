// 31_02_�ƶ��͹��캯��_move_ctor.cpp : �������̨Ӧ�ó������ڵ㡣
//

//http://blog.csdn.net/wangshubo1989/article/details/49748703

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class A
{
public:

	// Simple constructor that initializes the resource.
	explicit A(size_t length)
		: mLength(length), mData(new int[length])
	{
		std::cout << "A(size_t). length = "
			<< mLength << "." << std::endl;
	}

	// Destructor.
	~A()
	{
		std::cout << "~A(). length = " << mLength << ".";

		if (mData != NULL) 
		{
			std::cout << " Deleting resource.";
			delete[] mData;  // Delete the resource.
		}

		std::cout << std::endl;
	}

	// Copy constructor.���������캯��Ҳ����ʹ�ó�ʼֵ�б�
	A(const A& other)
		: mLength(other.mLength), mData(new int[other.mLength]) //����д����666
	{
		std::cout << "A(const A&). length = "
			<< other.mLength << ". Copying resource." << std::endl;

		std::copy(other.mData, other.mData + mLength, mData);
	}

	// Copy assignment operator.
	A& operator=(const A& other)
	{
		std::cout << "operator=(const A&). length = "
			<< other.mLength << ". Copying resource." << std::endl;

		if (this != &other) { //����д�����жϵ�ַ��ʡȥ���Լ���ʵ��operator==����ʵ��һ������жϵĺ���
			delete[] mData;  // Free the existing resource.
			mLength = other.mLength;
			mData = new int[mLength];
			std::copy(other.mData, other.mData + mLength, mData);
		}
		return *this;
	}

	// Move constructor.
	A(A&& other) : mData(NULL), mLength(0)
	{
		std::cout << "A(A&&). length = "
			<< other.mLength << ". Moving resource.\n";

		// Copy the data pointer and its length from the 
		// source object.
		mData = other.mData;
		mLength = other.mLength;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		other.mData = NULL;
		other.mLength = 0;
	}

	// Move assignment operator.
	A& operator=(A&& other)
	{
		std::cout << "operator=(A&&). length = "
			<< other.mLength << "." << std::endl;

		if (this != &other) {
			// Free the existing resource.
			delete[] mData;

			// Copy the data pointer and its length from the 
			// source object.
			mData = other.mData;
			mLength = other.mLength;

			// Release the data pointer from the source object so that
			// the destructor does not free the memory multiple times.
			other.mData = NULL;
			other.mLength = 0;
		}
		return *this;
	}

	// Retrieves the length of the data resource.
	size_t Length() const
	{
		return mLength;
	}

	int * Data()const 
	{
		return mData;
	}

private:
	size_t mLength; // The length of the resource.
	int* mData;     // The resource.
};
int main()
{
	{
		A a1(10);

		A &&rra = std::move(a1);

		A a2 = rra;
		A a3(rra);
		A a4 = std::move(a1); //ֻ�����������õ�move ctor,�������ַ�ʽ�����õ�copy ctor

	}

	//move�����ĺô�:
	//vector������֪��C++11���vectorҲ������һЩ�Ż���
	//����vector::push_back()������Ϊ�����ְ汾�����أ�
	//һ����cosnt T&��ֵ��Ϊ������һ����T&&��ֵ��Ϊ��������������Ĵ��룺
	{
		std::vector<A> v;
		v.push_back(A(25)); //���Կ���������Ϊ����ʱ�������̵������������������������е�length = 0,�������õ�move ctor
		cout << "==" << endl;
		v.push_back(A(75));
		//��������push_back()�������push_back(T&&)�汾����Ϊ���ǵĲ���Ϊ��ֵ(��ʱ���󣬼���������)�����������Ч�ʡ�

		A a1(30); //���Ƿ���ʱ�����������ȥpush_back�Ļ���������ֵ����Ϊ�������޷��ж������ֵ֮���ǲ��ǻ�Ҫʹ�ã���ֻ�ܵ��ÿ������캯����
		v.push_back(a1);
		cout << endl;

		//�ƺ�push_back(T&&)��Զ�����ѡ�񣬵���һ��Ҫ��ס�� 
		//push_back(T&&) ʹ�ò���Ϊ�ա����������Ҫ����������ֵ���������ʱ����Ҫʹ�ÿ������������ƶ���

	}

	{
		std::vector<A> v;
		A a2(31);
		//v.push_back(std::move(a2)); //ǿ�Ƶ����ƶ����캯��
		//֮��������������棬�����length��0��Ҳ����˵����move ctor��a2�ͳ��˿տ��ˡ�

		//����2
		// calls push_back(T&&)
		v.push_back(static_cast<A&&>(a2));

	}
	
	{
		//std::swap��������еĽ������Ҳ�ǵ��õ�move ctor��move assignment
		//��һ������ģ�����������
		A a1(10);
		A a2(20);

		cout << a1.Length() << " " << a2.Length() << endl;
		cout << a1.Data() << " " << a2.Data() << endl;

		std::swap(a1, a2);

		cout << a1.Length() << " " << a2.Length() << endl;
		cout << a1.Data() << " " << a2.Data() << endl;
	}

	system("pause");
    return 0;
}

