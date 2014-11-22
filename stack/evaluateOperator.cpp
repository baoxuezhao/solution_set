//reference: http://www.aichengxu.com/view/13114

#include <iostream>
#include <stack>

using namespace std;

void compute(stack<double> &data, stack<char> &op)
{
	double val2 = data.top();
	data.pop();
	double val1 = data.top();
	data.pop();

	char opera = op.top();
	op.pop();

	int res;

	if(opera == '+')
		data.push(res = val1 + val2);
	else if(opera == '-')
		data.push(res = val1 - val2);
	else if(opera == '*')
		data.push(res = val1 * val2);
	else if(opera == '/')
		data.push(res = val1 / val2);
	else
		cout << "error " << endl;
}


int getPriority(char ch)
{
	if(ch == '(')
		return 0;
	if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	else
		return -1;
}

double evaluate(string expression)
{
	stack<double> data;
	stack<char> operators;

	for(int i=0; i<expression.size(); i++)
	{
		char ch = expression[i];
		if(ch >= '0' && ch <= '9')
		{
			data.push(ch-'0');
		}
		else if(ch == '(')
		{
			operators.push(ch);
		}
		else if(ch == ')')
		{
			while(operators.top() != '(')
			{
				compute(data, operators);
			}
			operators.pop();
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			while(!operators.empty() && 
				getPriority(ch) <= getPriority(operators.top()))
				compute(data, operators);

			operators.push(ch);
		}
		else
			cout << "error" << endl;
	}

	while(!operators.empty())
		compute(data, operators);
	return data.top();
}

int main()
{

	string ex1 = "(1+2)*3+(4*(5+6))";
	cout << evaluate(ex1) << endl;

	string ex2 = "3+4*5";
	cout << evaluate(ex2) << endl;

	cout << evaluate("7-8/4/2*3-1") << endl;

	return 0;
}
