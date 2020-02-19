#include"zhaoyunze0217.h"
class node
{
public:
	zwp<node> pre;
	zwp<node> next;
	~node()
	{
		cout << "nodeÎö¹¹" << endl;
	}
};
void run()
{
	zsp<node> node1{ new node };
	zsp<node> node2{ new node };
	node1->next = node2;
	node2->pre = node1;
	cout << node1->next.use_count() << endl;
	cout << node1.use_count() << " " << endl;
}
void main()
{
	run();
	/*T t1(3, "zhaoyunze"), t2(5, "zyz");
	T &t3 = t2;
	T t4(t1);
	zsp<T> pt1{ new T(t1) };
	zsp<T> pt2 = pt1;
	cout<<pt1.use_count()<<endl;*/
}