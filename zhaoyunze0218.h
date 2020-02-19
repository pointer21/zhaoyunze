#pragma once
#include<iostream>
using namespace std;
template<class T> class zwp;
template<class T>
class Ref {//计数器，包括引用次数r，引用次数w
	int r_count = 0;
	int w_count = 0;
	T* object = nullptr;
public:
	Ref(T* target) :object(target)//引用，r++，由于一个计数器仅负责一个堆区对象，故而一个计数器仅调用一次
	{
		++r_count;
	}
	inline void increase()//多个指针指向同一个对象，指针数的增减变化引起r和w变化
	{
		r_count++;
	}
	inline void increase_w()
	{
		w_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)//当r清零无视w清空所指向的类对象
		{
			delete object;
			object = nullptr;
			if(w_count==0)
				delete this;
		}
	}
	inline void reduce_w()
	{
		w_count--;
		if (w_count == 0 && r_count == 0)//如果r不为零计数器还有使用的意义
			delete this;
	}
	T* get()
	{
		return object;
	}
	int getCount()
	{
		return r_count;
	}
};
template<class T> class zsp
{
	friend class zwp<T>;
	Ref<T>* ref = nullptr;
public:
	zsp() = default;
	~zsp()
	{
		if (ref)
		{
			ref->reduce();
		}
	}
	zsp(T* newP)
	{
		ref = new Ref<T>(newP);
	}
	zsp(const zsp& other)
	{
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
	}
	zsp(zsp&& other)
	{
		swap(ref, other.ref);
	}
	zsp& operator=(const zsp& other)
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		if (ref)
		{
			ref->increase();
		}
		return *this;
	}
	zsp& operator=(zsp&& other)
	{
		if (ref)
		{
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(zsp& other)
	{
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr)
	{
		if (ref)
		{
			ref->reduce();
		}
		if (target != nullptr)
		{
			ref = new Ref<T>(target);
		}
		else
		{
			ref = nullptr;
		}
	}
	T& operator*()
	{
		if (ref)
		{
			return *ref->get();
		}
		else
		{
			return *(T*)nullptr;
		}
	}
	T* operator->()
	{
		if (ref)
		{
			return ref->get();
		}
		else
		{
			return (T*)nullptr;
		}
	}
	T* get()
	{
		if (ref)
		{
			return ref->get();
		}
		else
		{
			return (T*)nullptr;
		}
	}
	int use_count()
	{
		cout << "调用了shared计数" << endl;
		if (ref)
		{
			return ref->getCount();
		}
		else
		{
			return 0;
		}
	}
	bool unique()
	{
		if (ref)
		{
			return ref->getCount() == 1;
		}
		else
		{
			return false;
		}
	}
	operator bool()
	{
		return ref != nullptr;
	}
};
template<class T>
class zwp
{
	
	Ref<T> *ref = nullptr;
public:
	zwp() = default;
	zwp(zsp<T>& other) :ref(other.ref)
	{
		cout << "使用shared_构造一个weak的拷贝赋值运算符" << endl;
		if (ref)
		{
			ref->increase_w();
		}
	}
	zwp(zwp<T>&& other)
	{
		swap(ref, other.ref);
	}
	zwp<T>& operator = (const zwp<T>& other) 
	{
		cout << "调用了weak的拷贝赋值运算符" << endl;
		if (ref) 
		{
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref) 
		{
			ref->increase_w();
		}
		return *this;
	}
	zwp<T>&  operator=(zwp<T>&& other)
	{
		cout << "调用了weak的移动赋值运算符" << endl;
		if (ref)
		{
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count() {
		cout << "调用了weak计数" << endl;
		if (ref) {
			return ref->getCount();
		}
		else {
			return 0;
		}
	}
	bool expired() {
		if (ref) {
			return ref->getCount() > 0;
		}
		else {
			return false;
		}
	}
	zwp<T> lock() {
		zwp<T> tem(ref);
		return tem;
	}
	void swap(zwp<T>& other)
	{
		swap(ref, other.ref);
	}
	void reset()
	{
		ref->reduce_w();//计数器w-1
		ref = nullptr;//把这个对象赋空值，即可视为新建的对象
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
	T & operator=(T&&a)
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
