#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

    int divide1(int va, int vb)
    {
    	long long a = va;
    	long long b = vb;
    	bool sign = (a > 0) ^ (b > 0);
    	a = abs(a);
    	b = abs(b);
    
    	if(b == 0) return INT_MAX;
    	long long res = 0;
    
    	long long total = 0;
    	while(a >= total+b)
    	{
    		long long sh = 1;
    		long long bb = b;
    		while(a >= bb+bb+total)
    		{
    			bb += bb;
    			sh += sh;
    		}
    		total += bb;
    		res += sh;
    	}
    	if(sign)
    	    res = ~res + 1;
    	
    	if(res > INT_MAX || res < INT_MIN)
    	    return INT_MAX;
    	else
    	    return res;
    }

int main()
{
	cout << divide(125, 5) << endl;
	cout << divide(180, 1) << endl;
	cout << divide(200, 7) << endl;
	cout << divide(INT_MAX, 1) << endl;
	cout << divide(-200, 7) << endl;
	cout << divide(-200, -18) << endl;
	cout << divide(-10, 20) << endl;
	cout << divide(INT_MAX, INT_MAX) << endl;
	cout << divide(INT_MAX, -INT_MAX) << endl;
	cout << divide(-INT_MAX, -INT_MAX) << endl;
	return 0;
}
