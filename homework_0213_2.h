#pragma once
#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	friend class house;
	string name;

	people(string name)
	{
		this->name=name;
		cout<<name<<endl;
	}
	virtual~people()
	{
		cout<<"people delete"<<endl;
	}
	virtual void yourjob()=0;
};

class student:public people
{
	string school;
public:
	student(string school):people("赵运泽")
	{
		this->school=school;
		cout<<name<<"是"<<school<<"的学生"<<endl;
	}
	~student()
	{
		cout<<name<<"毕业了"<<endl;
		
	}
	void yourjob()
	{
		cout<<"职业是student"<<endl;
	}
};
