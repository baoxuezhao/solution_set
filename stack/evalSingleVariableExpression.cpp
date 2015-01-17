#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

void compute(stack<pair<double, double> > &nums, stack<char> &ops)
{
	char op = ops.top();
	ops.pop();

	pair<double, double> n2 = nums.top();
	nums.pop();

	pair<double, double> n1 = nums.top();
	nums.pop();

	if(op == '+')
		nums.push(make_pair(n1.first+n2.first, n1.second+n2.second));
	else if(op == '-')
		nums.push(make_pair(n1.first-n2.first, n1.second-n2.second));
	else if(op == '*')
	{
		if(abs(n1.first-0) > 1e-7 && abs(n2.first-0) > 1e-7)
			cout << "error 1" << endl;
		double p2 = n1.first*n2.second + n1.second*n2.first;
		double p3 = n1.second*n2.second;
		nums.push(make_pair(p2, p3));
	}
	else if(op == '/')
	{
		if(abs(n2.first)<1e-5)
		{
			nums.push(make_pair(n1.first/n2.second, n1.second/n2.second));
		}
		else if(abs(n1.second-0)<1e-7 && abs(n2.second-0)<1e-7 && abs(n2.first-0)>1e-7)
		{
			nums.push(make_pair(n1.first/n2.first, 0));
		}
		else
		{
			cout << "error 2" << endl;
		}
	}
}

int getPriority(char ch)
{
	if(ch == '(')
		return 0;
	else if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	else
		return -1;
}

int atoi1(string str)
{
	int res = 0;
	if(str.size() == 0)
		return res;
		for(int i=0; i<str.size(); i++)
		res = res*10+(str[i]-'0');
	return res;
}

pair<double, double> evaluate(string &exp1)
{
	stack<pair<double,double> > data;
	stack<char> operators;
	
	const int n = exp1.size();
	for(int i=0; i<n; i++)
	{
		if(exp1[i] >= '0' && exp1[i] <= '9')
		{
			int start = i;
			while(i<n && exp1[i] >= '0' && exp1[i] <= '9') i++;
			i--;
			int num = atoi1(exp1.substr(start, i-start+1));
			data.push(make_pair(0, num));
		}
		else if(exp1[i] == 'x')
		{
			if(i>0 && exp1[i-1] >= '0' && exp1[i-1] <= '9')
			{
				pair<double, double> p = data.top();
				data.pop();
				data.push(make_pair(p.second, 0));
			}
			else
				data.push(make_pair(1, 0));
		}
		else if(exp1[i] == '(')
		{
			if(exp1[i-1] >= '0' && exp1[i-1] <= '9')
			{
				operators.push('*');
			}
			operators.push(exp1[i]);
		}
		else if(exp1[i] == ')')
		{
			while(!operators.empty() && operators.top() != '(')
				compute(data, operators);
			operators.pop();
		}
		else if(exp1[i] == '+' || exp1[i] == '-' || exp1[i] == '*' || exp1[i] == '/')
		{
			while(!operators.empty() && 
				getPriority(exp1[i]) <= getPriority(operators.top()))
				compute(data, operators);

			operators.push(exp1[i]);
		}
		else
			cout << "error 4" << endl;
	}

	while(!operators.empty())
		compute(data, operators);
	return data.top();
}

int main()
{
	string ex1 = "4x+13(x-(4x+x/3+2)+5)+11";
	string ex2 = "13(x-(4x+x/3))";
	pair<double, double> res = evaluate(ex1);
	cout << res.first << "\t" << res.second << endl;
	return 0;
}
