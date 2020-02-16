#include <iostream>
#include <initializer_list>
using namespace std;

class vec
{
	int *val;
public:
	vec(initializer_list<double> ve)
	{
		val = new int[ve.size()];
		for (int i = 0; i < ve.size(); i++)
		{
			val[i] = *(ve.begin() + i);
		}
	}
	int& operator [](unsigned int index)
	{
		return val[index];
	}
};

void main()
{
	vec ve({1,2,3,4,5,6,7});
	cout<<ve[2]<<endl;
}