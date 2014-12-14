#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define NUM 1024

using namespace std;

struct Node
{
	int L, R;
	int val;
}segTree[2*NUM];

void build(int left, int right, int root)
{
	segTree[root].L = left;
	segTree[root].R = right;
	segTree[root].val = 0;

	if(left == right)
		return;

	int mid = (left+right)/2;
	build(left, mid, 2*root);
	build(mid+1, right, 2*root+1);
}

void update(int pos, int root, int delta)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	if(L == R)
	{
		segTree[root].val += delta;
		return;
	}

	int mid = (L + R)/2;
	if(pos <= mid)
		update(pos, 2*root, delta);
	else
		update(pos, 2*root+1, delta);

	segTree[root].val = segTree[2*root].val + segTree[2*root+1].val;
}

int query(int start, int end, int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;

	if(start == L && end == R)
	{
		return segTree[root].val;
	}
	int mid = (L+R)/2;
	int left = 0, right = 0;
	if(start <= mid)
		left = query(start, min(end, mid), 2*root);
	if(end >= mid+1)
		right = query(max(start, mid+1), end, 2*root+1);

	return left+right;
}

int verify(int array[], int N, int start, int end)
{
	int sum = 0;
	for(int i=start; i<=end; i++)
		sum += array[i];
	return sum;
}

int main()
{
	int array[NUM+1];
	build(1, NUM, 1);

	for(int i=1; i<=NUM; i++)
	{
		array[i] = rand()%10000;
		update(i, 1, array[i]);
	}

	for(int i=1; i<=NUM; i++)
	{
		for(int j=i; j<=NUM; j++)
		{
			if(verify(array, NUM, i, j) != query(i, j, 1))
				printf("error %d %d\n", i, j);
		}
	}
	return 0;
}
