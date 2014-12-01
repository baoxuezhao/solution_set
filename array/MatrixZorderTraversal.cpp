#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<int> ZTraversal(int A[][8], int m, int n)
{
	int levelMax = m-1 + n-1;
	vector<int> result;
	bool order = false;

	for(int level = 0; level<=levelMax; level++)
	{
		if(order)
		{
			for(int i=level; i>=0; i--)
			{
				int j = level-i;
				if(i >= m || j >= n) continue;
				result.push_back(A[i][j]);
			}
		}
		else
		{
			for(int i=0; i<=level; i++)
			{
				int j = level-i;
				if(i >= m || j >= n) continue;
				result.push_back(A[i][j]);
			}
		}
		order = !order;
	}
	return result;
}

int main()
{
	int A[][10] = 
	{
		{0, 2, 3, 9, 10, 19, 20, 29, 30, 39},
		{1, 4, 8, 11, 18, 21, 28, 31, 38, 40},
		{5, 7, 12, 17, 22, 27, 32, 37, 41, 46},
		{6, 13, 16, 23, 26, 33, 36, 42, 45, 47},
		{14, 15, 24, 25, 34, 35, 43, 44, 48, 49}
	};

	int B[][8] = 
	{
		{0,  2,  3,  9,  10, 20, 21, 35},
		{1,  4,  8,  11, 19, 22, 34, 36},
		{5,  7,  12, 18, 23, 33, 37, 51},
		{6,  13, 17, 24, 32, 38, 50, 52},
		{14, 16, 25, 31, 39, 49, 53, 64},
		{15, 26, 30, 40, 48, 54, 63, 65},
		{27, 29, 41, 47, 55, 62, 66, 73},
		{28, 42, 46, 56, 61, 67, 72, 74},
		{43, 45, 57, 60, 68, 71, 75, 78},
		{44, 58, 59, 69, 70, 76, 77, 79}
	};


	vector<int> res1 = ZTraversal(B, 10, 8);

	for(int i=0; i<res1.size(); i++)
	{
		cout << res1[i] << endl;
	}
	return 0;
}
