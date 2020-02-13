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
		cout<<"���people"<<endl;
	}
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
		cout<<school<<"��У��"<<endl;
		
	}
	void out()
	{
		cout<<"���student"<<endl;
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
		cout<<"ʹ�������"<<endl;
		address=p.address;
		area=p.area;
		owner=new people(*p.owner);
	}
	house(house&& p):area(p.area),address(p.address),owner(p.owner)
	{
		cout<<"ʹ�����ƶ�����"<<endl;
		p.owner=NULL;
	}
	~house()
	{
		delete owner;
	}
};