//source: http://www.careercup.com/question?id=19587667

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isMatch(char *str, char *pat)
{
	int m = strlen(pat);
	int n = strlen(str);

	bool dp[m+1][n+1];
	memset(dp, false, sizeof(dp));

	dp[0][0] = true;
	for(int j=1; j<=n; j++)
		dp[0][j] = false;
	for(int i=1; i<=m; i++)
		dp[i][0] = (i>1 && pat[i-1] == '*' && dp[i-2][0]);

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j] = dp[i][j] || (dp[i-1][j-1] && str[j-1] == pat[i-1]);
			dp[i][j] = dp[i][j] || (i>=2 && dp[i][j-1] && str[j-1] == pat[i-2] && (pat[i-1] == '*' || pat[i-1] == '+' ));
			dp[i][j] = dp[i][j] || (i>=2 && dp[i-2][j] && pat[i-1] == '*');
			dp[i][j] = dp[i][j] || (i>=2 && dp[i-2][j-1] && pat[i-1] == '+' && (pat[i-2] == str[j-1]));
		}
	}
	return dp[m][n];
}

int main()
{
	cout << isMatch("aaab", "a*b") << endl;
	cout << isMatch("b", "a*b") << endl;
	cout << isMatch("ab", "a*b") << endl;
	cout << isMatch("aab", "a*b") << endl;
	cout << isMatch("aaab", "a*b") << endl;
	cout << isMatch("aaab", "a*b") << endl;

	cout << isMatch("ab", "a+aabc") << endl;
	cout << isMatch("aabc", "a+aabc") << endl;
	cout << isMatch("aaabc", "a+aabc") << endl;
	cout << isMatch("aaaabc", "a+aabc") << endl;

	cout << isMatch("aab aab", "aa*b*ab+") << endl;
	cout << isMatch("aab", "aa*b*ab+") << endl;
	cout << isMatch("aabab", "aa*b*ab+") << endl;
	cout << isMatch("aaaabbab", "aa*b*ab+") << endl;

	cout << isMatch("a", "a+a*b*") << endl;
	cout << isMatch("ab", "a+a*b*") << endl;
	cout << isMatch("aab", "a+a*b*") << endl;
	cout << isMatch("aaabb", "a+a*b*") << endl;

	cout << isMatch("aaaabba", "aa*b*ab+") << endl;
	cout << isMatch("bbb", "a+a*b*") << endl;

	return 0;
}
