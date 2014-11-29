//reference: http://homecox.com/bbs/view.php?f=25&t=6

#include <iostream>
#include <cmath>
using namespace std;

bool contains7(int x)
{
	int digit;
	while(x)
	{
		digit = x%10;
		x /= 10;
		if(digit == 7)
			return true;
	}
	return false;
}


int getx(int &x)
{
	while(contains7(x))
		x++;
}

int base9to10(int x)
{
	int res = 0;
	int base = 1;
	while(x)
	{
		int val = x%10;
		x /= 10;
		val = (val < 7)? val: (val-1);
		res = res + base*val;
		base *= 9;
	}
	return res;
}

int main()
{
	int x = 0;
	for(int i=1; i<1000; i++)
	{
		x++;
		getx(x);
		if(i != base9to10(x))
			cout << i << "\t" << x << " error " << base9to10(x) << endl;
	}
	return 0;
}
