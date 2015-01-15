#include <iostream>
using namespace std;

double sqrt(double x)
{
	double EPS = 0.000000001;
	double left = 0.0, right = max(1.0, x), mid;
	while(left + EPS < right)
	{
		mid = (left+right)/2.0;
		if(mid*mid > x)
			right = mid;
		else
			left = mid;
	}
	return left;
}

int main()
{
	for(double i=0.1; i<10; i+=0.05)
	{
		double res = sqrt(i);
		cout << i << "\t" << res << "\t" << res*res << endl;
	}
	return 0;
}
