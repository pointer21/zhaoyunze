#include<iostream>
#include<math.h>
#include<time.h>
#include<Windows.h>
using namespace std;



//��ô����a~b�����С��

	int possiblity(int a)//��ôͨ��rand����[0,a)����
	{
		int p = rand() % a;
		return p;
	}
	int possiblity1(int a, int b)//��ôͨ��rand����[a,b)����
	{
		int p = (rand() % (b - a)) + a;
		return p;
	}
	bool possiblity2(double n)///����0��1��double���������жϳɹ����ɹ�����ture��
	{
		double p = ((double)rand()) / RAND_MAX;
		if (p < n)
			return true;
		else
			return false;
	}
	double possiblity3(double n)//��ô����һ��0~1�����С��double
	{
		double p = ((double)rand()) / RAND_MAX;
			return p;
	}
	//����0��100���������������жϳɹ�,�ɹ�����true
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
	srand(time(0));//��ʼ�����������
	cout << possibility5(2.5, 3.3) << endl;

}