#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;
static_assert(sizeof(char*)==4, "integer is not 32 ");
class vec
{
	int *val;
	int size;
public:
	vec(initializer_list<double> ve)
	{
		size = ve.size();
		val = new int[ve.size()];
		for (int i = 0; i < ve.size(); i++)
		{
			val[i] = *(ve.begin() + i);
		}
	}
	int& operator [](unsigned int index)
	{
		assert(index <= 0 || index>size);
		return val[index];
	}
};
void main()
{
	vec ve({1,2,3,5,7});
	cout<<ve[2]<<endl;
	

}