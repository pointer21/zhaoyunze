#include<iostream>
#include<memory>
using namespace std;
template<class T>
class zauto_ptr
{
	T* obj = nullptr;
public:
	zauto_ptr(T* ptr) :obj(ptr)
	{

	}
	zauto_ptr()  = default;
	~zauto_ptr() 
	{
		delete obj;
	}
	zauto_ptr(zauto_ptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	zauto_ptr & operator=(zauto_ptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T *newptr)
	{
		delete obj;
		obj = newptr;
	}
	T*release()
	{
		auto tem = obj;
		obj = nullptr;
		return tem;
	}
	T & operator*()
	{
		return obj;
	}
	T * operator->()
	{
		return obj;
	}
	T * get()
	{
		return obj;
	}
};
class T
{
	int val;
	string vas;
public:
	T(int a, string b)
	{
		val = a;
		vas = b;
		cout << "构造" << endl;
	}
	T()
	{
		cout << "无参构造" << endl;
	}
	T(const T& a)
	{
		vas = a.vas;
		val = a.val;
		cout << "拷贝" << endl;
	}
	T(T&& a)
	{
		vas = a.vas;
		val = a.val;
		cout << "移动" << endl;
	}
	T & operator=(T&a)
	{
		val = a.val;
		vas = a.vas;
		cout << "重载" << endl;
		return *this;
	}
	~T()
	{
		cout << "析构" << endl;
	}
};
void main()
{
	T t1(3, "zhaoyunze"),t2(5,"zyz");
	T &t3=t2;
	T t4(t1);
	zauto_ptr<T> pt1{ new T(t1) };
	zauto_ptr<T> pt2=pt1;
	*(pt1).get();
}