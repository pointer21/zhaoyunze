#include"deep_copy.h"
#include<iostream>
#include<string>
using namespace std;

void main()
{
	student s1("����ʯ�ʹ�ѧ");
	people *p1=&s1;
	p1->yourjob();
	cout<<"ִ����һ��"<<endl;
}