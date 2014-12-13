#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>

using namespace std;

struct Triple
{
	int sum;
	int i, j;
	Triple(int s, int ii, int jj)
	{
		sum = s;
		i = ii;
		j = jj;
	}
};

class comp  
{  
public:  
    bool operator()(const Triple &t1, const Triple &t2)
    {  
        return t1.sum > t2.sum;  
    }  
}; 

vector<int> smallestKth(int A[], int m, int B[], int n, int k)
{
	bool hash[m][n];
	memset(hash, false, sizeof(hash));

	priority_queue<Triple, vector<Triple>, comp> pqueue;

	vector<int> result;
	pqueue.push(Triple(A[0]+B[0], 0, 0));
	hash[0][0] = true;
	
	for(int i=0; i<k; i++)
	{
		Triple t = pqueue.top();
		pqueue.pop();
		result.push_back(t.sum);

		if(t.i+1 < m)
		{
			Triple cur(A[t.i+1]+B[t.j], t.i+1, t.j);
			if(hash[cur.i][cur.j] == false)
			{
				pqueue.push(cur);
				hash[cur.i][cur.j] = true;
			}
		}
		if(t.j+1 < n)
		{
			Triple cur(A[t.i]+B[t.j+1], t.i, t.j+1);
			if(hash[cur.i][cur.j] == false)
			{
				pqueue.push(cur);
				hash[cur.i][cur.j] = true;
			}
		}
	}
	return result;
}

int main()
{
	int m = 500;
	int n = 800;
	int k = 800;

	int A[m];
	int B[n];

	for(int i=0; i<m; i++)
		A[i] = rand()%10000;

	for(int j=0; j<n; j++)
		B[j] = rand()%10000;

	sort(A, A+m);
	sort(B, B+n);

	vector<int> res = smallestKth(A, m, B, n, k);

	//verify
	int C[m*n];
	int idx = 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			C[idx++] = A[i]+B[j];

	sort(C, C+m*n);

	for(int i=0; i<k; i++)
		if(C[i] != res[i])
			cout << "error " << C[i] << "\t" << res[i] << endl;

	return 0;
}
