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
	student(string school):people("������")
	{
		this->school=school;
		cout<<name<<"��"<<school<<"��ѧ��"<<endl;
	}
	~student()
	{
		cout<<name<<"��ҵ��"<<endl;
		
	}
	void yourjob()
	{
		cout<<"ְҵ��student"<<endl;
	}
};
