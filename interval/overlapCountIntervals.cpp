#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define SIZE 100

struct Node
{
	int L, R, count;
	bool colored;
}segTree[SIZE << 2];


void pushDown(int rt)
{
	if(!segTree[rt].colored)
	{
		segTree[2*rt].count += segTree[rt].count;
		segTree[2*rt+1].count += segTree[rt].count;
        segTree[2*rt].colored = segTree[2*rt+1].colored = false;
        segTree[rt].colored = true;
        segTree[rt].count = 0;
	}
}

void buildTree(int L,int R, int root)
{
    segTree[root].L = L;
    segTree[root].R = R;
    segTree[root].count = 0;
    segTree[root].colored = false;
    if(L == R) return;
            
    int mid = (L + R) / 2;
    buildTree(L, mid, root * 2);
    buildTree(mid+1, R, root * 2 + 1);
}

void update(int start, int end, int root)
{
	if(start > end)
		return;

	int L = segTree[root].L;
	int R = segTree[root].R;
	
	if(!segTree[root].colored)
	{
		if(start == L && end == R)
		{
			segTree[root].count++;
			segTree[root].colored = false;
			return;
		}
		pushDown(root);
	}

	int mid = (L+R)/2;
	if(start <= mid)
		update(start, min(mid, end), 2*root);
	if(end > mid)
		update(max(mid+1, start), end, 2*root+1);

	segTree[root].colored = true;
}

int query(int P, int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;

	if(!segTree[root].colored)
		return segTree[root].count;

	//pushDown(root);

	int mid = (L+R)/2;
	if(P <= mid)
		return query(P, 2*root);
	else
		return query(P, 2*root+1);
}

int main()
{
    int N,M;
    
    scanf("%d%d",&N, &M);

    int root = 1;
    buildTree(1,N,root);

    int l,r,c;
    while(M--)
    {
        scanf("%d%d",&l,&r);
        update(l,r,root);

		for(int i = 1; i <= 2 * N - 1; ++i)
            printf("%3d %3d %3d %3d colored %3d\n",i,segTree[i].L,segTree[i].R,segTree[i].count,segTree[i].colored);
	    cout << endl;
    }

    for(int i=1; i<=N; i++)
    	printf("%d\t%d\n", i, query(i, root));
    return 0;
}
