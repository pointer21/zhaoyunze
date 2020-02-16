#include<iostream>
using namespace std;
template<class T> void zswap(T &a, T &b)
{
	T tem = a;
	a = b;
	b = tem;
	cout << a << " 交换" << b << endl;
}
class A
{
public:
	int val;
	char* p;
	A(int v)
	{
		val = v;
		p = new char[10];
		cout << "构造" << endl;
	}
	A(const A&other) :A(other.val)
	{
		p = new char[10];
		cout << "拷贝构造" << endl;
	}
	~A()
	{
		delete p;
		cout << "析构" << endl;
	}
	A& operator=(const A& other)
	{
		delete p;
		p = new char[10];
		val = other.val;
		cout << "重载拷贝构造" << endl;
		return *this;
	}
	
	
};
ostream& operator<<(ostream& o,A& a)
{
	cout << "val " << a.val<<" ";
	return o;
}
void main()
{
	int a = 2, b = 3;
	double b1 = 2.33, b2 = 3.32;
	zswap(a, b);
	zswap<int>(a, b);
	zswap<>(b1, b2);
	A a1(31),a2(2);
	zswap(a1, a2);
	cout << "结束" << endl;
}

