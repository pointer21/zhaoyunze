#include<iostream>
#include<vector>
using namespace std;
template<class T> class zstack
{
	vector<int> ar;
public:
	void push(T && img)//&&这个接收常量
	{
		ar.push_back(img);
	}
	void pop()
	{
		ar.pop_back();
	}
	T& top()
	{
		return ar.back();
	}
	size_t size()
	{
		return ar.size();
	}
	bool empty()
	{
		return ar.size();
	}
};
void main()
{
	zstack<int> a;
	a.push(5);
	a.push(7);
	a.push(9);
	cout << a.top()<<endl;
	a.pop();
	a.pop();
	cout << a.top() << endl;
}