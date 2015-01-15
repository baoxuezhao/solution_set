#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int findMissing(int A[], int n)
{
	if(n < 3) return -1;
	int diff = (A[n-1]-A[0])/n;

	int l = 0, r = n-1;
	while(l <= r)
	{
		int m = l + (r-l)/2;
		if(m < n-1 && abs(A[m+1]-A[m]) > abs(diff))
			return (A[m+1]+A[m])/2;			

		int ldiff = A[m] - A[l];
		int rdiff = A[r] - A[m];
		if(ldiff == diff*(m-l))
			l = m+1;
		else if(rdiff == diff*(r-m))
			r = m-1;
		else
			break;
	}
	return A[n-1]+diff;
}

int test(int A[], int n)
{
	if(n < 3) return -1;
	int diff = (A[n-1]-A[0])/n;
	for(int i=0; i<n-1; i++)
		if(abs(A[i+1]-A[i]) > abs(diff))
			return (A[i+1]+A[i])/2;
	return A[n-1]+diff;
}

int main()
{
	int B[] = {10, 8, 6, 4, 0};
	cout << findMissing(B, 5) << endl;

	int diff = -3;
	int N = 102;
	int A[N];
	for(int i=-3; i>-3*N; i+=diff)
	{
		int cur = 0;
		for(int k=0; k<N; k++)
		{
			A[k] = cur;
			cur+=diff;
			if(cur == i)
				cur+=diff;
		}
		int res = findMissing(A, N);
		int res2 = test(A, N);
		if(res != res2)
		{
			cout << i << "\t" << res << "\t" << res2 << endl;
		}
		
	}
	return 0;
}
