//给一个有序序列 {x1, x2, ...., xn} 然后二次函数 f(x) = ax^2 + bx + c
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<float> sort(vector<float> &array, int a, int b, int c)
{
	float zhou = 0-(b*1.0)/(2*a);
	vector<float> result;
	vector<pair<float, float> > left;
	vector<pair<float, float> > right;
	

	for(int i=0; i<array.size(); i++)
	{
		if(array[i] <= zhou)
		{
			left.push_back(make_pair(array[i], zhou-array[i]));
		}
		else
		{
			right.push_back(make_pair(array[i], array[i]-zhou));
		}
	}

	if(a > 0)
	{
		std::reverse(left.begin(), left.end());
	}
	else if(a < 0)
	{
		std::reverse(right.begin(), right.end());
	}

	int idx1 = 0, idx2 = 0;
	while(idx1 < left.size() && idx2 < right.size())
	{
		if((a > 0 && left[idx1].second < right[idx2].second) 
			|| (a < 0 && left[idx1].second > right[idx2].second))
		{
			result.push_back(left[idx1].first);
			idx1++;
		}
		else
		{
			result.push_back(right[idx2].first);
			idx2++;
		}
	}
	if(idx1 < left.size())
	{
		for(; idx1 < left.size(); idx1++)
			result.push_back(left[idx1].first);
	}
	else if(idx2 < right.size())
	{
		for(; idx2 < right.size(); idx2++)
			result.push_back(right[idx2].first);
	}
	return result;
}

int main()
{
	int a = 4, b = -7, c = 9;

	float arr[] = {-17.2, -13, -10.2, -8, -4.5, -2.0, 1.0, 1.8, 2.6, 4.5, 9.3};
	vector<float> array(arr, arr+sizeof(arr)/sizeof(float));

	vector<float> res = sort(array, a, b, c);
	for(int i=0; i<res.size(); i++)
	{
		float val = a*(res[i]*res[i]) + b*(res[i]) + c;
		cout << res[i] << "\t" << val << endl;
	}
	return 0;
}
