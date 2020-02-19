#pragma once
#include<iostream>
using namespace std;
template<class T> class zwp;
template<class T>
class Ref {//���������������ô���r�����ô���w
	int r_count = 0;
	int w_count = 0;
	T* object = nullptr;
public:
	Ref(T* target) :object(target)//���ã�r++������һ��������������һ���������󣬹ʶ�һ��������������һ��
	{
		++r_count;
	}
	inline void increase()//���ָ��ָ��ͬһ������ָ�����������仯����r��w�仯
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
		if (r_count == 0)//��r��������w�����ָ��������
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
		if (w_count == 0 && r_count == 0)//���r��Ϊ�����������ʹ�õ�����
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
		cout << "������shared����" << endl;
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
		cout << "ʹ��shared_����һ��weak�Ŀ�����ֵ�����" << endl;
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
		cout << "������weak�Ŀ�����ֵ�����" << endl;
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
		cout << "������weak���ƶ���ֵ�����" << endl;
		if (ref)
		{
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count() {
		cout << "������weak����" << endl;
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
		ref->reduce_w();//������w-1
		ref = nullptr;//��������󸳿�ֵ��������Ϊ�½��Ķ���
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
		cout << "����" << endl;
	}
	T()
	{
		cout << "�޲ι���" << endl;
	}
	T(const T& a)
	{
		vas = a.vas;
		val = a.val;
		cout << "����" << endl;
	}
	T(T&& a)
	{
		vas = a.vas;
		val = a.val;
		cout << "�ƶ�" << endl;
	}
	T & operator=(T&&a)
	{
		val = a.val;
		vas = a.vas;
		cout << "����" << endl;
		return *this;
	}
	~T()
	{
		cout << "����" << endl;
	}
};
