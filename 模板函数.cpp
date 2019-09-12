#include<iostream>
#include<assert.h>
using namespace std;

//普通实现一个交换函数
void swap1(int& left,int& right)
{
	int temp = left;
	left = right;
	right = temp;
} 

void swap2(double& left,double& right)
{
	double temp = left;
	left = right;
	right = temp;
}

void swap3(char& left,char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
//普通函数实现交换，主要类型改变就要重新实现代码复用率比较低

//泛型编程：编写与类型无关的通用代码，时代码复用的一种手段
//模板  ：  函数模板   类模板

//函数模板
//模板参数 template<typename T1,typename T2,......>
//         or  template<class T>  这个常用 
//返回值类型 函数名(参数类表){}

//交换函数模板

template<typename T>
void Swap(T& left,T& right)
{
	T temp = left;
	left = right;
	right = temp;	
}

// 函数模板的实例化 
//用不同的类型使用函数模板时，称为函数模板的实例化。
//模板参数实例化有两种方式：隐式，显式 。

//隐式实例化：让编译器根据实参推演模板参数实际类型
template<class T>
T Add(const T& left,const T& right)
{
	return left + right;
} 

//显式实例化： 在函数名后<>中指定模板参数的实际类型
 

 //注意：如果类型不匹配，编译器会进行隐式类型转换，如果不行则报错。
  
  
//类模板
//template<class T1,class T2,.....,class Tn>
//class 类模板名
//{// 成员定义}；

//动态顺序表
template<class T>
class Vector
{
	public:
		 Vector(size_t capacity = 10)
		 :_pDate(new T[capacity])
		 ,_size(0)
		 ,_capacity(capacity)
		 {}
		 
		 //因为存在空间的申请和释放，所以要自己写析构函数
		 ~ Vector()
		 {
		 		if(_pDate)
	{
		delete[] _pDate; 
	}
		 }
		 
		 void pushback(const T& date)
		 {
		 	_pDate[_size++] = date;
		 }
		 
		 void popback()
		 {
		 	--_size;
		 } 
		 
		 size_t size()
		 {
		 	return _size;
		 }
		 
		 T& operator[](size_t pos)
		 {
		 	assert(pos<_size);
		 	return _pDate[pos];
		 }
	private:
		T* _pDate;
		size_t _size;
		size_t _capacity;	
};

//类模板实例化
//类模板实例化需要在类模板名字后跟<>，然后将实例化的类型放在<>中即可，类模板名字不是真正的类，而实例化的结果才是真正的类。 

int main()
{
	int a = 10, b = 20;
    double c = 10.0, d = 20.0;
	//Swap(a,b);
	//c = Add(a,b);
	//printf("%d\n",Add(a,b));//编译器实参类型自动推演为形参类型 
	//printf("%d\n",Add(c,d));//同上
	//printf("%d\n",Add(a,c));//根据实参推导时第一个为int，第二个为double。而模板中只有一个参数这是编译器无法识别，就会报错。
	//而解决这个问题有两个方法：1、用户自己来强制转换 2、采用显式实例化 
	//printf("%d\n",Add(a,(int)b));//用户强制转换 
	//printf("%d\n",Add<int>(a,b));//显式实例化 
	Vector<int> s1;
	s1.pushback(1);
	s1.pushback(2);
	s1.pushback(3);
	
	size_t i = 0;
	for(i;i<s1.size();++i)
	{
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	return 0;
 } 
 




