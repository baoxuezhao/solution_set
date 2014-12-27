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

int main()
{
	cout << isOneEditDistance("", "") << endl;
	cout << isOneEditDistance("", "a") << endl;
	cout << isOneEditDistance("a", "") << endl;

	cout << isOneEditDistance("abc", "abc") << endl;
	cout << isOneEditDistance("ebc", "abc") << endl;
	cout << isOneEditDistance("aec", "abc") << endl;
	cout << isOneEditDistance("abe", "abc") << endl;

	cout << isOneEditDistance("abc", "dabc") << endl;
	cout << isOneEditDistance("abc", "adbc") << endl;
	cout << isOneEditDistance("abc", "abdc") << endl;
	cout << isOneEditDistance("abc", "abcd") << endl;

	cout << isOneEditDistance("dabc", "abc") << endl;
	cout << isOneEditDistance("adbc", "abc") << endl;
	cout << isOneEditDistance("abdc", "abc") << endl;
	cout << isOneEditDistance("abcd", "abc") << endl;

	cout << isOneEditDistance("abpdt", "abcde") << endl;
	cout << isOneEditDistance("abp", "abcde") << endl;
	return 0;
}
