#pragma once
#include<iostream>
using namespace std;
template<class T>
class Ref {
	int r_count = 0;
	T* object = nullptr;
public:
	Ref(T* target) :object(target)
	{
		++r_count;
	}
	inline void increase()
	{
		r_count++;
	}
	inline void reduce()
	{
		r_count--;
		if (r_count == 0)
		{
			delete object;
			delete this;
		}
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
