#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<vector>
using namespace std;

//int main()
//{
//	//vector���캯���÷�
//
//    vector<int> first;//�޲ι��캯��
//	vector<int> second(4,100);//�вι��캯�� ��ʼ���ĸ�Ԫ�� ��100��ʼ��
//	vector<int> third(second.begin(), second.end());//�õ�������ʼ��
//	vector<int> four(third);//�������캯��
//
//	int myints[] = { 116,22,77,29 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));//�õ�������ʼ�� Ԫ����������е�Ԫ�ض���ͬ
//
//	cout << "The contents of fifth are:";
//	//���÷�Χforѭ������vector
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//	{
//		cout << ' ' << *it;
//	}
//	cout << endl;
//
//	//���ڷ�Χforѭ��
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
	//ʹ��const���������б�����ӡ
	vector<int>::const_iterator it = v.cbegin();//const_iterator������ֻ�ܶ����ܸ�
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
//	//ʹ�õ��������б�����ӡ
//	vector<int> ::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//ʹ�õ����������������޸�
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	//ʹ�÷�����������б�����ӡ
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	//����const���������б���
//	PrintVector(v);
//	
//	system("pause");
//	return 0;
//}

//vector::capacity
//vs��capaciity �ǰ���1.5�������� vs�汾��pj��STL��g++�������2��������SGI�汾��STL��
void my_capacity()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();//��ȡ�����Ĵ�С
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

	//����֪��Ҫ�Ŀռ�������С������� ֱ��ʹ��reserveһ���Ե�λ���ٶ�ο��ռ������
	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);//reserve()ֻ�ı�������С
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

	//��ʼ�� 
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
	vector<int> v(a, a + sizeof(a) / sizeof(int));//�õ���������ʼ��
	
	//β��
	v.push_back(5);
	v.push_back(6);
	
	//���õ�������������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//βɾ
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
	//�����find( , ),������vector���ṩ�ĵĺ����ӿڣ�����Ҫ�������������ṩ�ĵĺ���
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//ʹ�õ��������г�ʼ��

	//ʹ��find��������3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//��posλ��֮ǰ����666  insert(pos��val ) ��posλ��֮ǰ����һ����val
	v.insert(pos,666);

	//���ڷ�Χfor���б������� �ײ㻹�ǵ�����
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 666);//���¶�λposλ�� �粻���ܵ��µ�����ʧЧ
	
	//ɾ��posλ�õ�����
	v.erase(pos);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void my_operator_()
{
	//��c++98�� vector�ı�����ʽ���� operator[]+index����c++11�б������·�ʽΪfor+auto�ı���
   //��һ������� ���õľ��������ֱ�����ʽ

	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));//���õ�������ʼ��

	//ͨ��[]���б��� ��д��0��λ��
	v[0] = 10;
	cout << v[0] << endl;

	//ͨ��[i]��ʽ����vector
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> swapv;
	//swapv.swap(v);
	//swap(v, swapv);

	//����vector
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
	vector<int> v(a, a + sizeof(a) / sizeof(int));//��������ʼ������

	//ʹ��find����3λ�����ڵ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//���1��ɾ��posλ�õ����ݣ�����pos������ʧЧ
	v.erase(pos);
	//cout << *pos << endl; //�ᱨ�� posλ��ʧЧ

	//���2;��posλ�ò������ݣ�����pos������ʧЧ
	//insert�ᵼ�µ�����ʧЧ��insert����ʱ���ܵ������ݣ����ݺ�posλ�û�ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ�
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	//cout << *pos << endl;//�Ƿ����� posʧЧ
}

void my_iterator_use()
{
	int a[] = { 1, 2, 3, 4 ,5};
	vector<int> v(a, a + sizeof(a) / sizeof(int));//ʹ�õ�������ʼ��
	//ʵ��ɾ��v��ż��

	//�����
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

	//����vector
	for (auto e : v)
	{
		cout << *it << " ";
	}
	cout << endl;
}
