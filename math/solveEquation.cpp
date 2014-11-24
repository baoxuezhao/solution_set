#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

//x + 2^x = target
//compute x

int compute1(int target)
{
	int left = 0, right = log(target)/log(2)+1;
	long gap = INT_MAX;
	int prev;
	while(left <= right)
	{
		int mid = left + (right-left)/2;
		long res = mid + pow(2, mid);

		if(res == 0)
			return mid;
		else if(res < target)
			left = mid+1;
		else
			right = mid-1;

		long curgap = abs(res - target);		
		if(curgap < gap)
		{
			prev = mid;
			gap = curgap;
		}
	}
	return prev;
}


double newton(int target)
{
	double x0 = 1;
	double x1 = INT_MAX;
	while(true)
	{
		double y0 = x0+pow(2, x0)-target;

		x1 = x0-y0/(1+pow(2,x0)*log(2));
		if(abs(x0-x1) <= 1e-6)
		{
			break;
		}
		x0 = x1;
	}
	return x0;
}

int main()
{
	int target;
	cin >> target;
	cout << compute1(target) << endl;
	cout << newton(target) << endl;
	return 0;
}
