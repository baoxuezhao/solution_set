#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> smallestK(vector<int> &A, int k)
{
	vector<int> res;
	const int n = A.size();
	if(n < k)
		return res;

	priority_queue<int> q;
	for(int i=0; i<k; i++)
		q.push(A[i]);

	for(int i=k; i<n; i++)
	{
		int v = q.top();
		if(A[i] < v)
		{
			q.pop();
			q.push(A[i]);
		}
	}

	while(!q.empty())
	{
		res.push_back(q.top());
		q.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	vector<int> num;
	for(int i=0; i<100; i++)
	{
		num.push_back(100-i);
	}
	vector<int> res = smallestK(num, 10);

	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;

	return 0;
}
