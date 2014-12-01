#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 100


int table[26];
char ch[MAXN];

int l_pos, r_pos;

int solve()
{
	int minstep = 0;

	memset(table, 0, sizeof(table));
	const int n = strlen(ch);

	for(int i=0; i<n; i++)
		table[ch[i]-'a']++;

	int numodd = 0;
	for(int i=0; i<26; i++)
		if(table[i] % 2)
		{
			numodd++;
			if(numodd > 1)
				return -1;
		}

	int left = 0, right = n-1;
	while(left < right)
	{

		if(ch[left] == ch[right])
		{
			left++;
			right--;
			continue;
		}
		char lch = ch[left];
		char rch = ch[right];

		l_pos = r_pos = INT_MAX;

		for(int lk = left+1; lk < right; lk++)
		{
			if(ch[lk] == ch[right])
			{
				l_pos = lk - left;
				break;
			}
		}

		for(int rk = right-1; rk > left; rk--)
		{
			if(ch[rk] == ch[left])
			{
				r_pos = right - rk;
				break;
			}
		}

		if(l_pos < r_pos)
		{
			minstep += l_pos;
			for(int i = left + l_pos; i > left; i--)
			{
				swap(ch[i], ch[i-1]);
				if(ch[i] == ch[i-1])
					minstep--;
			}
		}
		else
		{
			minstep += r_pos;
			for(int i = right - r_pos; i < right; i++)
			{
				swap(ch[i], ch[i+1]);
				if(ch[i] == ch[i+1])
					minstep--;
			}
		}
		left++;
		right--;
	}
	return minstep;
}

int main()
{
	int t, res;
	scanf("%d%*c" , &t);

    while(t--){  
        scanf("%s" , ch);  
        res = solve();  
    	if(res != -1)
    		cout << res << endl;
    	else
    		cout << "Impossible" << endl;
    }  
    return 0; 
}
