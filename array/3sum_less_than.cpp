#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>

using namespace std;


int lessThan(vector<int> &A, int target)
{
	const int n = A.size();
	std::sort(A.begin(), A.end());
	int count = 0;
	int sum = -1;

	for(int i=0; i<A.size(); i++)
	{
		int left = i+1, right = A.size()-1;
		while(left < right)
		{
			sum = A[i] + A[left] + A[right];
			if(sum < target)
			{
				count += (right-left);
				left++;
			}
			else if(sum >= target)
			{
				right--;
			}
		}
	}
	return count;
}


int verify(vector<int> &A, int target)
{
	const int n = A.size();
	int count = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				if(A[i]+A[j]+A[k] < target)
				{
					//cout << A[i] << " " << A[j] << " " << A[k] << endl;
					count++;
				}
			}
		}
	}
	return count;
}

int main()
{
  	srand ( time(NULL) );
  	vector<int> AA;

  	for(int i=0; i<1000; i++)
  	{
  		AA.push_back(rand()%1000);
  	}

  	int target = rand()%1000;

  	clock_t start = clock();
	int res1 = lessThan(AA, target);
	clock_t end = clock();

	cout << "Time 1: " << (end-start+0.0)/CLOCKS_PER_SEC << endl;

	start = clock();
	int res2 = verify(AA, target);
	end = clock();

	cout << "Time 2: " << (end-start+0.0)/CLOCKS_PER_SEC << endl;

	cout << res1 << " " << res2 << " " << (res1 == res2) << endl;
	return 0;
}
