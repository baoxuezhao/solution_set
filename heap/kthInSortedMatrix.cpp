#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Element
{
	int row, col, val;
	Element(int r, int c, int v)
	{
		row = r;
		col = c;
		val = v;
	}
};

class comp
{
public:
	bool operator()(const Element &e1, const Element &e2)
	{
		return e1.val > e2.val;
	}
};

int findKth(int A[][4], int n, int k)
{
	// k must be greater than 0 and smaller than n*n
	if (k <= 0 || k > n*n)
		return INT_MAX;
	bool visit[4][4] = {false};
	priority_queue<Element, vector<Element>, comp> PQ;

	//for(int i=0; i<n; i++)
	//	PQ.push(Element(0, i, A[0][i]));
	PQ.push(Element(0, 0, A[0][0]));
	visit[0][0] = true;

	Element e(0,0,0);
	for(int i=0; i<k; i++)
	{
		e = PQ.top();
		PQ.pop();

		if(e.row < n-1 && !visit[e.row+1][e.col])
		{
			visit[e.row+1][e.col] = true;
			PQ.push(Element(e.row+1, e.col, A[e.row+1][e.col]));
		}
		if(e.col < n-1 && !visit[e.row][e.col+1])
		{
			visit[e.row][e.col+1] = true;
			PQ.push(Element(e.row, e.col+1, A[e.row][e.col+1]));
		}
	}
	return e.val;
}

int main()
{
	int A[] = 
	{
		10, 20, 30, 40,
        15, 25, 35, 45,
        24, 29, 37, 48,
        32, 33, 39, 50,
	};

	int B[][4] = 
	{
		10, 20, 30, 40,
        15, 25, 35, 45,
        24, 29, 37, 48,
        32, 33, 39, 50,
	};

	sort(A, A+16);

	for(int i=0; i<16; i++)
	{
		int res = findKth(B, 4, i+1);
		cout << res << "\t" << A[i] << endl;
	}
	
	return 0;
}
