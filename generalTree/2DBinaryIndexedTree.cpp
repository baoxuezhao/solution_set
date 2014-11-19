#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <cstring>
using namespace std;

#define NUM 200
#define LOWBIT(x)	(x & (-x))

int array[NUM+1][NUM+1];
int bitArray[NUM+1][NUM+1];


int query(int x, int y)
{
	int sum = 0;
	for(int i = x; i>0; i -= LOWBIT(i))
	{
		for(int j = y; j>0; j -= LOWBIT(j))
		{
			sum += bitArray[i][j];
		}
	}
	return sum;
}

void update(int x, int y, int value)
{
	assert(x >= 1 && x <= NUM);
	assert(y >= 1 && y <= NUM);

	int delta = value - array[x][y];
	array[x][y] += delta;

	for(int i = x; i<=NUM; i += LOWBIT(i))
	{
		for(int j=y; j<=NUM; j += LOWBIT(j))
		{
			bitArray[i][j] += delta;
		}
	}
}


int verify(int x, int y)
{
	int sum = 0;
	for(int i=1; i<=x; i++)
	{
		for(int j=1; j<=y; j++)
		{
			sum += array[i][j];
		}
	}
	return sum;
}

void build()
{
	memset(array, 0, sizeof(array));
	memset(bitArray, 0, sizeof(bitArray));
	srand(time(NULL));

	for(int i=1; i<=NUM; i++)
	{
		for(int j=1; j<=NUM; j++)
		{
			int value = rand()%100;
			update(i, j, value);
		}
	}
}

int main()
{
	build();

	float time1 = 0, time2 = 0;
	clock_t start, end;
	int res1, res2;
	for(int i=1; i<=NUM; i++)
	{
		for(int j=1; j<=NUM; j++)
		{
			start = clock();
			res1 = query(i, j);
			end = clock();

			time1 += (end-start);

			start = clock();
			res2 = verify(i, j);
			end = clock();

			time2 += (end-start+0.0);
			if(res1 != res2)
				cout << "error " << i << " " << j << endl; 
		}
	}
	cout << time1/CLOCKS_PER_SEC << "\t" << time2/CLOCKS_PER_SEC << endl;

	return 0;
}
