#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;


int minsubstr(string &str, int n)
{
	const int nn = str.size();
	int map[256];
	memset(map, 0, sizeof(map));

	int unique = 0;
	int start = 0;
	int minlength = INT_MAX;
	int minstart = -1;

	for(int i=0; i<nn; i++)
	{
		map[str[i]]++;
		if(map[str[i]] == 1)
		{
			unique++;
			if(unique == n)
			{
				while(map[str[start]] > 1 && start < i)
				{
					map[str[start]]--;
					start++;
				}
				if(i-start+1 < minlength)
				{
					minlength = i-start+1;
					minstart = start;
				}
				if(start < i)
				{
					map[str[start]]--;
					if(map[str[start]] == 0)
						unique--;
					start++;
				}
			}
		}
	}

	if(minlength != INT_MAX)
	{
		cout << minstart << "\t" << minlength << endl;
		cout << str.substr(minstart, minlength) << endl;
	}
	else
		cout << "no valid substring found" << endl;

	return 0;
}

int main()
{
	string str = "aaaaaaaaaabbbbbbcccd";
	minsubstr(str, 3);
	return 0;
}
