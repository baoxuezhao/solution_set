#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isOneEditDistance(string s1, string s2)
{
	const int len1 = s1.size();
	const int len2 = s2.size();
	if(len1 > len2) return isOneEditDistance(s2, s1);
	if(abs(len1-len2) > 1) return false;

	int i=0, shift = len2-len1;
	while(i<len1 && s1[i] == s2[i]) i++;
	if(i == len1) return shift == 1;
	if(shift == 0) i++;
	while(i<len1 && s1[i] == s2[i+shift]) i++;
	return i == len1;
}

//wrong
bool isOneEditDistance2(string s1, string s2)
{
	const int len1 = s1.size();
	const int len2 = s2.size();
	if(len1 > len2) return isOneEditDistance(s2, s1);
	if(abs(len1-len2) > 1) return false;

	bool find = false;
	for(int i=0, j=0; i<len1 && j<len2; i++, j++)
	{
		if(s1[i] != s2[j])
		{
			if(find) return false;
			if(len1 == len2)
				find = true;
			else
			{
				i--;
				find = true;
			}
		}
	}
	return find;
}

//for sequences, with only next method
bool isOneEditDistance3(char* s1, char* s2)
{
	int idx1=0, idx2=0;
	bool equal=true, lshift=true, rshift=true;
	int pl = -1, pr = -1;
	int cl = -1, cr = -1;

	while(s1[idx1] == s2[idx2] && s2[idx2]) idx1++, idx2++;

	pl = s1[idx1++];
	pr = s2[idx2++];

	while(true)
	{
		cl = (pl == 0)?-1:s1[idx1];
		cr = (pr == 0)?-1:s2[idx2];
		if(cl == cr && cl == -1) break;
		equal = (equal && cl == cr);
		lshift = (lshift && cl == pr);
		rshift = (rshift && cr == pl);
		if(!equal && !lshift && !rshift) return false;
		pl = pl==0?0:s1[idx1++];
		pr = pr==0?0:s2[idx2++];
	}
	return (equal || lshift || rshift);
}

int main()
{
	/*
	cout << isOneEditDistance3("abc", "abcd") << endl;
	cout << isOneEditDistance3("abc", "abcde") << endl;
	cout << isOneEditDistance3("abecd", "abcd") << endl;
	cout << isOneEditDistance3("", "") << endl;
	cout << isOneEditDistance3("abcd", "abce") << endl;
	cout << isOneEditDistance3("abcd", "abed") << endl;
	cout << isOneEditDistance3("ebcd", "abcd") << endl;
	cout << isOneEditDistance3("ababa", "bababa") << endl;
	cout << isOneEditDistance3("ababa", "baba") << endl;
	cout << isOneEditDistance3("ababa", "abab") << endl;
	cout << isOneEditDistance3("ababa", "babab") << endl;
	return 0;
	*/

	cout << isOneEditDistance("", "")  << isOneEditDistance3("", "") << endl;
	cout << isOneEditDistance("", "a") << isOneEditDistance3("", "a") << endl;
	cout << isOneEditDistance("a", "") << isOneEditDistance3("a", "") << endl;

	cout << isOneEditDistance("abc", "abc") << isOneEditDistance3("abc", "abc") << endl;
	cout << isOneEditDistance("ebc", "abc") << isOneEditDistance3("ebc", "abc") << endl;
	cout << isOneEditDistance("aec", "abc") << isOneEditDistance3("aec", "abc") << endl;
	cout << isOneEditDistance("abe", "abc") << isOneEditDistance3("abe", "abc") << endl;

	cout << isOneEditDistance("abc", "dabc") << isOneEditDistance3("abc", "dabc") << endl;
	cout << isOneEditDistance("abc", "adbc") << isOneEditDistance3("abc", "adbc") << endl;
	cout << isOneEditDistance("abc", "abdc") << isOneEditDistance3("abc", "abdc") << endl;
	cout << isOneEditDistance("abc", "abcd") << isOneEditDistance3("abc", "abcd") << endl;

	cout << isOneEditDistance("dabc", "abc") << isOneEditDistance3("dabc", "abc") << endl;
	cout << isOneEditDistance("adbc", "abc") << isOneEditDistance3("adbc", "abc") << endl;
	cout << isOneEditDistance("abdc", "abc") << isOneEditDistance3("abdc", "abc") << endl;
	cout << isOneEditDistance("abcd", "abc") << isOneEditDistance3("abcd", "abc") << endl;

	cout << isOneEditDistance("abpdt", "abcde") << isOneEditDistance3("abpdt", "abcde") << endl;
	cout << isOneEditDistance("abp", "abcde") << isOneEditDistance3("abp", "abcde") << endl;
	return 0;
}
