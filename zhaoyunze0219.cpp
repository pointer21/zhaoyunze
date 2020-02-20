#include<iostream>
#include<math.h>
#include<time.h>
#include<Windows.h>
using namespace std;



//怎么生成a~b的随机小数

	int possiblity(int a)//怎么通过rand生成[0,a)的数
	{
		int p = rand() % a;
		return p;
	}
	int possiblity1(int a, int b)//怎么通过rand生成[a,b)的数
	{
		int p = (rand() % (b - a)) + a;
		return p;
	}
	bool possiblity2(double n)///传入0到1的double，概率性判断成功，成功返回ture。
	{
		double p = ((double)rand()) / RAND_MAX;
		if (p < n)
			return true;
		else
			return false;
	}
	double possiblity3(double n)//怎么生成一个0~1的随机小数double
	{
		double p = ((double)rand()) / RAND_MAX;
			return p;
	}
	//传入0到100的整数，概率性判断成功,成功返回true
	bool possiblity4(int n)
	{
		int p = rand() % 100;
		if (p < n)
			return true;
		else
			return false;
	}
	double possibility5(double a, double b)
	{
		double lon = b - a;
		double p;
		while (1)
		{
			p = ((double)rand()) / RAND_MAX;
			if (p < lon)
				break;
		}p = p + a;
		return p;

	}


void main()
{
	srand(time(0));//初始化随机数种子
	cout << possibility5(2.5, 3.3) << endl;

}