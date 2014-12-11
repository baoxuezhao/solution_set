#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

//we garantee that the max_heap size is 
//no less than the min_heap size
void getMedian(int in[], int out[], int n)
{
	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;

	for(int i=0; i<n; i++)
	{
		if(max_heap.size() == min_heap.size())
		{
			if(max_heap.size() == 0)
				max_heap.push(in[i]);
			else
			{
				if(in[i] <= min_heap.top())
					max_heap.push(in[i]);
				else
				{
					max_heap.push(min_heap.top());
					min_heap.pop();
					min_heap.push(in[i]);
				}
			}
			out[i] = max_heap.top();
		}
		else
		{
			if(in[i] >= max_heap.top())
			{
				min_heap.push(in[i]);
			}
			else
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(in[i]);
			}
			out[i] = (max_heap.top() + min_heap.top())/2;
		}
		
	}
}

int verify(int in[], int k)
{
	const int n = k+1;
	int arr[n];

	for(int i=0; i<=k; i++)
	{
		arr[i] = in[i];
	}
	std::sort(arr, arr+n);
	if(n%2 == 0)
		return (arr[n/2-1] + arr[n/2])/2;
	else
		return arr[n/2];
}

int main()
{
	#define N 10000

	int in[N];
	int out[N];

	for(int i=0; i<N; i++)
	{
		in[i] = rand()%100000;
	}

	getMedian(in, out, N);

	for(int i=0; i<N; i++)
	{
		int r = verify(in, i);
		if(out[i] != r)
		{
			cout << "error " << out[i] << "\t" << r << endl;
		}
	}

	return 0;
}
