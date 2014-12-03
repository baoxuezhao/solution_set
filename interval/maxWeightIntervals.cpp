#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 1024
struct NODE
{
	int L,R,val,color;
}segTree[4 * SIZE];

void pushDown(int rt)
{
	if(!segTree[rt].color)
	{	
		segTree[2*rt].val = max(segTree[2*rt].val, segTree[rt].val);
		segTree[2*rt+1].val = max(segTree[2*rt+1].val, segTree[rt].val);
        segTree[2*rt].color = segTree[2*rt+1].color = false;
        segTree[rt].color = true;
	}
}

void build(int L,int R,int root)
{
	segTree[root].L = L;
	segTree[root].R = R;
	segTree[root].val = 0;
	segTree[root].color = false;
	if(L == R) return;

	int mid = (L + R) >> 1;
	build(L,mid,root * 2);
	build(mid+1,R,root * 2 + 1);
}

void update(int start,int end,int root,int val)
{
	int L = segTree[root].L;
	int R = segTree[root].R;

	if(L == R)
	{
		segTree[root].val = max(segTree[root].val,val);
		return;
	}
	
	if(!segTree[root].color) // pure color
	{
		if(segTree[root].val >= val)
			return;
		else if(L == start && R == end)
		{
			segTree[root].val = val;
			return;
		}

	}
	pushDown(root);

	int mid = (L + R) >> 1;
	if(start <= mid) 
		update(start,min(mid,end),root * 2,val);
	if(end > mid)
		update(max(mid + 1,start),end,root * 2 + 1,val);
	segTree[root].color = true;
}

int query(int P,int root)
{
	//int now = max(val,segTree[root].val);
	if(!segTree[root].color)
		return segTree[root].val;

	int mid = (segTree[root].L + segTree[root].R) >> 1;
	if(P <= mid)
		return query(P, root*2);
	else
		return query(P, root*2+1);
}

int main()
{
	
	int start,end,root = 1,val;
	int N,Q;
	scanf("%d%d%d",&start,&end,&N);
	build(start,end,root);
//	for(int i = 1; i <= 15; ++i)
//		printf("%d %d %d\n",segTree[i].L,segTree[i].R,segTree[i].val);
	while(N--)
	{
		scanf("%d%d%d", &start, &end, &val);
		update(start,end,root,val);

		for(int i = 1; i <= 7; ++i)
			printf("%d %d %d %d\n",segTree[i].L,segTree[i].R,segTree[i].val,segTree[i].color);
		cout << endl;
	}
	cout << "after update " << endl;

	int point;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&point);
		printf("%d\n",query(point,root));
	}
	return 0;

}
