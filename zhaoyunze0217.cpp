#include"zhaoyunze0217.h"
void main()
{
	T t1(3, "zhaoyunze"), t2(5, "zyz");
	T &t3 = t2;
	T t4(t1);
	zsp<T> pt1{ new T(t1) };
	zsp<T> pt2 = pt1;
	cout<<pt1.use_count()<<endl;
}