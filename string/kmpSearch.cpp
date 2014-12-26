#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void compute_next(char *str, int *next)
{
	int len = strlen(str);
	next[0] = -1;
	int j = 0, k = -1;
	while(j < len)
	{
		if(k == -1 || str[j] == str[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int kmp_search(char *str, char *pat)
{
	int slen = strlen(str);
	int plen = strlen(pat);
	int *next = new int[slen];
	compute_next(str, next);

	int i = 0, j = 0;
	while(i < slen && j < plen)
	{
		if(j == -1 || str[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	delete[] next;

	if(j == plen)
		return i-j;
	else
		return -1;
}

int main()
{
	char *txt = "ABABDABACDABABCABAB";
   	char *pat = "ABABCABAB";
   	int ret = kmp_search(txt, pat);
   	cout << ret << endl;
   	cout << txt + ret << endl;
   	return 0;
}
