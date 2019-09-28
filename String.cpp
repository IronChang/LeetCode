#include<iostream>
#include <assert.h>
using namespace std;

// 深浅拷贝问题
//namespace bit
//{
//	class string
//	{
//	public:
//		/*	string()
//				:_str(new char[1])
//				{
//				*_str = '\0';
//				}*/
//
//		//string(const char* str = "\0")    错误示范
//		//string(const char* str = nullptr) 错误示范
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			// 已经拷贝'\0'
//			strcpy(_str, str);// while (*dst++ = *src++);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//string copy1(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s2;
//		// s1 = s1;
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	bit::string s1("hello");
//	s1[0] = 'x';
//	cout << s1.c_str() << endl;
//
//	bit::string copy1(s1);
//	cout << copy1.c_str() << endl;
//
//	copy1[0] = 'h';
//	cout << s1.c_str() << endl;
//	cout << copy1.c_str() << endl;
//
//	bit::string s2 = "world";
//	s1 = s2;
//	cout << s1.c_str() << endl;
//
//	return 0;
//}

//namespace bit
//{
//	// string 模拟实现  增删查改
//	class string
//	{
//	public:
//		typedef const char* const_iterator;
//		typedef char* iterator;
//
//		const_iterator begin() const 
//		{
//			return _str;
//		}
//
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			// 已经拷贝'\0'
//			strcpy(_str, str);// while (*dst++ = *src++);
//			_size = strlen(str);
//			_capacity = _size;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//
//		//string copy1(s1)
//		string(const string& s)
//			:_str(new char[s._size + 1])
//			, _size(s._size)
//			, _capacity(s._size)
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s2;
//		// s1 = s1;
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[s._size + 1];
//				strcpy(_str, s._str);
//				_size = s._size;
//				_capacity = s._capacity;
//			}
//
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		const char& operator[](size_t pos) const
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//
//		size_t capacity()
//		{
//			return _capacity;
//		}
//
//		//reverse
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n+1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		} 
//
//		void push_back(char ch)
//		{
//			//if (_size == _capacity)
//			//{
//			//	// 扩容
//			//	reserve(_capacity * 2);
//			//}
//
//			//_str[_size] = ch;
//			//++_size;
//			//_str[_size] = '\0';
//			insert(_size, ch);
//		}
//
//		// s1.append("11111");
//		void append(const char* str)
//		{
//			//size_t len = strlen(str);
//			//if (_size+len > _capacity)
//			//{
//			//	// 扩容
//			//	reserve(_size + len);
//			//}
//
//			//strcpy(_str + _size, str);
//			//_size += len;
//
//			insert(_size, str);
//		}
//
//		//s1 += ch
//		const string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		const string& operator+=(const string& s)
//		{
//			append(s._str);
//			return *this;
//		}
//
//		void insert(size_t pos, char ch)
//		{
//			assert(pos <= _size);
//			if (_size == _capacity)
//			{
//				reserve(_capacity * 2);
//			}
//
//			/*int end = _size;
//			while (end >= (int)pos)
//			{
//				_str[end + 1] = _str[end];
//				--end;
//			}*/
//
//			size_t end = _size+1;
//			while (end >= pos + 1)
//			{
//				_str[end] = _str[end - 1];
//				--end;
//			}
//
//			_str[pos] = ch;
//			++_size;
//		}
//
//		void insert(size_t pos, const char* str)
//		{
//			assert(pos <= _size);
//			size_t len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				reserve(_size + len);
//			}
//
//			/*	int end = _size;
//				while (end >= (int)pos)
//				{
//				_str[end + len] = _str[end];
//				--end;
//				}*/
//
//			size_t end = _size + len;
//			while (end >= pos + len)
//			{
//				_str[end] = _str[end-len];
//				--end;
//			}
//
//			while (*str)
//			{
//				_str[pos++] = *str++;
//			}
//
//			_size += len;
//		}
//
//		// s1 > s2
//		// hello  hello!
//		bool operator>(const string& s) const
//		{
//			const char* str1 = _str;
//			const char* str2 = s._str;
//			while (*str1 && *str2)
//			{
//				if (*str1 > *str2)
//				{
//					return true;
//				}
//				else if (*str1 < *str2)
//				{
//					return false;
//				}
//				else
//				{
//					++str1;
//					++str2;
//				}
//			}
//
//			if (*str1)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//			/*else if (*str2)
//			{
//			return false;
//			}
//			else
//			{
//			return false;
//			}*/
//		}
//
//		bool operator==(const string& s) const
//		{
//			const char* str1 = _str;
//			const char* str2 = s._str;
//			while (*str1 && *str2)
//			{
//				if (*str1 != *str2)
//				{
//					return false;
//				}
//				else
//				{
//					++str1;
//					++str2;
//				}
//			}
//
//			if (*str1 || *str2)
//			{
//				return false;
//			}
//			else
//			{
//				return true;
//			}
//		}
//
//		bool operator>=(const string& s) const
//		{
//			return *this > s || *this == s;
//		}
//		// ...
//
//		size_t find(char ch)
//		{
//
//		}
//
//		size_t find(const char* str) // strstr ->kmp   
//		{
//
//		}
//
//		// operator+
//		// operator<<
//		// operator>>
//		// getline
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//
//
//void test1()
//{
//	bit::string s1("hello");
//	cout << s1.c_str() << endl;
//	bit::string copy1(s1);
//	cout << copy1.c_str() << endl;
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		// s1.operator[](i); -> s1.operator[](&s1, i);
//		s1[i] = 'a';
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	bit::string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test2()
//{
//	bit::string s1("hello");
//	cout << s1.capacity() << endl;
//
//	s1 += "world";
//	cout << s1.capacity() << endl;
//
//	s1 += '!';
//	cout << s1.capacity() << endl;
//
//	cout << s1.c_str() << endl;
//
//	bit::string s2("helloworld!");
//	s2.insert(5, ' ');
//	cout << s2.c_str() << endl;
//	s2.insert(0, '$');
//	cout << s2.c_str() << endl;
//	s2.insert(0, "bit");
//	cout << s2.c_str() << endl;
//}
//
//int main()
//{
//	test2();
//
//	return 0;
//}

// 实现一个简单的string
// 传统写法 -> 踏实、按部就班
//class my_string
//{
//private:
//	char* _str;
//public:
//	my_string(const char* str = "")
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//
//	// my_string s2(s1)
//	my_string(const my_string& s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	// s1 = s2
//	my_string& operator=(const my_string& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//
//		return *this;
//	}
//
//	~my_string()
//	{
//		delete[] _str;
//	}
//};

// 现代写法 -> 小聪明 简单
class my_string
{
private:
	char* _str;
public:
	my_string(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	// my_string s2(s1)
	my_string(const my_string& s)
		:_str(nullptr)
	{
		my_string tmp(s._str);
		swap(tmp._str, _str);
	}

	// s1 = s2
	/*my_string& operator=(const my_string& s)
	{
	if (this != &s)
	{
	my_string tmp(s);
	swap(_str, tmp._str);
	}

	return *this;
	}*/
	// s1 = s2
	// s1 = s1
	my_string& operator=(my_string s)
	{
		swap(_str, s._str);
		return *this;
	}

	~my_string()
	{
		if (_str)
			delete[] _str;
	}
};

int main()
{
	my_string s1("hello");
	my_string s2(s1);
	my_string s3("world");

	s1 = s3;

	return 0;
}