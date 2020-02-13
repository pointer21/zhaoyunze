#include"deep_copy.h"
#include<iostream>
#include<string>
using namespace std;

void main()
{
	student s1("东北石油大学");
	people *p1=&s1;
	p1->yourjob();
	cout<<"执行下一句"<<endl;
}