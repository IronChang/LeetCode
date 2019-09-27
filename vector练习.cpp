#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
using namespace std;

//int main()
//{
//	//vector构造函数用法
//
//    vector<int> first;//无参构造函数
//	vector<int> second(4,100);//有参构造函数 初始化四个元素 用100初始化
//	vector<int> third(second.begin(), second.end());//用迭代器初始化
//	vector<int> four(third);//拷贝构造函数
//
//	int myints[] = { 116,22,77,29 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));//用迭代器初始化 元素区间和其中的元素都相同
//
//	cout << "The contents of fifth are:";
//	//利用范围for循环遍历vector
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//	{
//		cout << ' ' << *it;
//	}
//	cout << endl;
//
//	//基于范围for循环
//	cout << "The contents of fifth are:";
//	for (auto e : second)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//
//}

void PrintVector(const vector<int>& v)
{
	//使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.cbegin();//const_iterator迭代器只能读不能改
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	//使用迭代器进行遍历打印
//	vector<int> ::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//使用迭代器迭代器进行修改
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	//使用反向迭代器进行遍历打印
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	//利用const迭代器进行遍历
//	PrintVector(v);
//	
//	system("pause");
//	return 0;
//}

//vector::capacity
//vs下capaciity 是按照1.5倍增长的 vs版本下pj的STL，g++情况下是2倍增长的SGI版本的STL；
void my_capacity()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();//获取容量的大小
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);

		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void my_reserve()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);

		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}

	cout << "===================================" << endl;

	//在已知需要的空间容量大小的情况下 直接使用reserve一次性到位减少多次开空间的消耗
	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);//reserve()只改变容量大小
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}


}

void my_resize()
{
	vector<int> myvector;

	//初始化 
	for (int i = 1; i < 10; i++)
	{
		myvector.push_back(i);
	}

	myvector.resize(5);
	myvector.resize(10,100);
	myvector.resize(12);
	myvector.resize(2);

	cout << "myvector contains:";
	for (int i = 0; i < (int)myvector.size(); ++i)
	{
		cout << " " << myvector[i];
	}
	cout << endl;
}

void my_push_backpop_back()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//用迭代器·初始化
	
	//尾插
	v.push_back(5);
	v.push_back(6);
	
	//利用迭代器遍历容器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//尾删
	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void my_find_insert_erase()
{
	//这里的find( , ),并不是vector所提供的的函数接口，所以要有其他库中所提供的的函数
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//使用迭代器进行初始化

	//使用find（）查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//在pos位置之前插入666  insert(pos，val ) 在pos位置之前插入一个数val
	v.insert(pos,666);

	//基于范围for进行遍历容器 底层还是迭代器
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 666);//从新定位pos位置 如不可能导致迭代器失效
	
	//删除pos位置的数据
	v.erase(pos);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void my_operator_()
{
	//在c++98中 vector的遍历方式还是 operator[]+index，在c++11中遍历的新方式为for+auto的遍历
   //在一般情况中 常用的就是这两种遍历方式

	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//利用迭代器初始化

	//通过[]进行遍历 读写第0个位置
	v[0] = 10;
	cout << v[0] << endl;

	//通过[i]方式遍历vector
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> swapv;
	//swapv.swap(v);
	//swap(v, swapv);

	//遍历vector
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;




}

void my_iterator()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//迭代器初始化容器

	//使用find查找3位置所在的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//情况1：删除pos位置的数据，导致pos迭代器失效
	v.erase(pos);
	//cout << *pos << endl; //会报错 pos位置失效

	//情况2;在pos位置插入数据，导致pos迭代器失效
	//insert会导致迭代器失效，insert插入时可能导致增容，增容后pos位置还指像原来的空间，而原来的空间已经释放
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	//cout << *pos << endl;//非法访问 pos失效
}

void my_iterator_use()
{
	int a[] = { 1, 2, 3, 4 ,5};
	vector<int> v(a, a + sizeof(a) / sizeof(int));//使用迭代器初始化
	//实现删除v中偶数

	//会崩溃
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);
	//	}
	//	++it;
	//}

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
				
	}

	//遍历vector
	for (auto e : v)
	{
		cout << *it << " ";
	}
	cout << endl;
}
