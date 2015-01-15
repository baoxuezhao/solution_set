//source http://www.careercup.com/question?id=4901629824335872

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double atof(char *s)
{
	bool num = false;
    bool dot = false;
    bool exp1 = false;

	while(*s == ' ') s++;
	int n = strlen(s);
	while(n > 0 && s[n-1] == ' ') n--;

	int sign1 = 1, sign3 = 1;

	int part1 = 0;
	double part2 = 0.0;
	int part3 = 0;
	double power2 = 0.1;

	for(int i=0; i<n; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num = true;
			if(exp1)
				part3 = part3*10+(s[i]-'0');
			else if(!dot)
				part1 = part1*10+(s[i]-'0');
			else
			{
				part2 = part2 + (s[i]-'0')*power2;
				power2 *= 0.1;
			}
		}
		else if(s[i] == '.')
		{
			if(dot || exp1) return -1;
			dot = true;
		}
		else if(s[i] == 'E' || s[i] == 'e')
		{
			if(!num || exp1) return -1;
			exp1 = true;
			num = false;
		}
		else if(s[i] == '-' || s[i] == '+')
		{
			if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E') return -1;
			if(i == 0)
				sign1 = (s[i] == '+')?1:-1;
			else
				sign3 = (s[i] == '+')?1:-1;
		}
		else
			return -1;
	}

	if(num)
		return sign1*(part1 + part2)*pow(10, part3*sign3);
	else
		return -1;
}

int main()
{
	cout << atof("342.18E-10") << endl;
	cout << atof("E5") << endl;
	cout << atof(" 12.45 ") << endl;
	cout << atof(" .45 ") << endl;
	cout << atof(" 12. ") << endl;
	cout << atof(" 12.e2 ") << endl;
	cout << atof(" 12.e-3 ") << endl;
	cout << atof(" 12.e-3.1 ") << endl;
	cout << atof(" -.0012e-3 ") << endl;
	cout << atof(" 1.2.3 ") << endl;
	cout << atof(" E123E ") << endl;
	cout << atof(" 12.34-3E12 ") << endl;
	return 0;
}
