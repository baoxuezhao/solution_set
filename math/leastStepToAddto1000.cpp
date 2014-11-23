//两个寄存器a,b, 一开始存的值是1 1. 允许两种操作a=a+b和b=a+b. 问经过最少几步操作可以将a或b中的其中一个变成100.
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int getStep(int a, int b)
{
	if(a < b)
		swap(a, b);

	if(b == 0)
		return -1;
	else if(b == 1)
		return a-1;

	int res = getStep(a%b, b);
	if(res == -1)
		return -1;
	else
		return res+(a/b);
}

int leastStep(int target)
{
	int min_step = INT_MAX;
	for(int i=1; i<target/2+1; i++)
	{
		int j = target-i;
		int res = getStep(i, j);
		if(res != -1)
		{
			if(res < min_step)
			{
				min_step = res;
			}
		}
	}
	return min_step+1;
}

int main()
{
	
	for(int i=1000; i<100000; i *= 2)
	{
		int res = leastStep(i);
		cout << i << "\t" << res << endl;
	}

	return 0;
}
