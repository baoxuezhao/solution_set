#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> &A, int idx, int k, int target, vector<int> &path, vector<vector<int> > &res)
{
	if(path.size() == k-2)
	{
		int left = idx, right = A.size()-1;

		while(left < right)
		{
			if(left>idx && A[left] == A[left-1]) 
				left++;
			else if(right<A.size()-1 && A[right] == A[right+1]) 
				right--;
			else
			{
				if(A[left] + A[right] == target)
				{
					res.push_back(path);
					res.back().push_back(A[left++]);
					res.back().push_back(A[right--]);
				}
				else if(A[left] + A[right] < target)
					left++;
				else
					right--;
			}
		}
	}
	else
	{
		for(int i=idx; i<A.size(); i++)
		{
			if(i>idx && A[i] == A[i-1]) continue;
			path.push_back(A[i]);
			dfs(A, i+1, k, target-A[i], path, res);
			path.pop_back();
		}
	}
}

vector<vector<int> > ksum(vector<int> &A, int k, int target)
{
	sort(A.begin(), A.end());
	vector<vector<int> > res;
	vector<int> path;
	dfs(A, 0, k, target, path, res);
	return res;
}

int main()
{
	vector<int> A{1,-2,-5,-4,-3,3,3,5};

	vector<vector<int> > res = ksum(A, 4, -11);

	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
