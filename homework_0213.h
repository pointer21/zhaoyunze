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
	virtual void out()
	{
		cout<<"输出people"<<endl;
	}
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
		cout<<school<<"封校了"<<endl;
		
	}
	void out()
	{
		cout<<"输出student"<<endl;
	}
};
class house
{
	string address;
	string area;
	people* owner;
public:
	house(string address,string area,string sname)
	{
		this->address=address;
		this->area=area;
		owner=new people(sname);	
	}
	house(const house& p)
	{
		cout<<"使用了深拷贝"<<endl;
		address=p.address;
		area=p.area;
		owner=new people(*p.owner);
	}
	house(house&& p):area(p.area),address(p.address),owner(p.owner)
	{
		cout<<"使用了移动构造"<<endl;
		p.owner=NULL;
	}
	~house()
	{
		delete owner;
	}
};