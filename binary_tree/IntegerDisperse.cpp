//problem: http://www.careercup.com/question?id=6026101998485504
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int A[] = {2,1,1,1,3,4,4,4,5};
	map<int, int> hash;
	int n = sizeof(A)/sizeof(int);
	int m = 2;

	for(int i=0; i<n; i++)
		hash[A[i]]++;

	map<int, int>::iterator it = hash.begin();
	for(int i=0; i<m; i++)
	{
		int idx = i;
		for(;idx<n; idx+=m)
		{
			A[idx] = it->first;
			it->second--;
			if(it->second == 0)
				it++;
		}
	}
	for(int i=0; i<n; i++)
	{
		cout << A[i] << endl;
	}
	return 0;
}
