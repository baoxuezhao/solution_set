#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <sstream>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define NO_OF_CHAR 26

string itoa(int n){
    std::stringstream ss;
	ss<<n;
	return ss.str();
}

string divide(int a,int b)
{
    string result=itoa(a/b);
	a=a%b;
	unordered_map<int,int> remain;
	int size=result.size();
	if(a==0)
		return result;
	result+='.';
	int loop_s=-1;
	while(a!=0)
    {
		if(remain.find(a)!=remain.end()){
			loop_s=remain.find(a)->second;
			break;
		}
     
		remain.insert(pair<int,int>(a,result.size()));
        a=a*10;
		if(a<b){
			result+='0';
		}else{
			result+=(a/b+'0');
			a=a%b;
		}
	}
	if(a!=0){
		result.insert(loop_s,"(");
		result+=")";
	}
	return result;
}


int countBeforeRepeat(int a, int b)
{
    int count2 = 0, count5 = 0;
    while(b%2 == 0)
    {
        b = b/2;
        count2++;
    }
    while(b%5 == 0)
    {
        b = b/5;
        count5++;
    }
    
    while(a%2 == 0)
    {
        a = a/2;
        count2--;
    }
    while(a%5 == 0)
    {
        a = a/5;
        count5--;
    }
    if(count2 > count5)
    {
        if(count2 > 0)
            return count2;
        else
            return 0;
    }else if(count5 > count2)
    {
        if(count5 > 0)
            return count5;
        else
            return 0;
    }
}

string divide2(int a, int b)
{
    string result=itoa(a/b);
    a=a%b;
    if(a == 0)
        return result;
    
    result += ".";
    int count = countBeforeRepeat(a, b);
    
    for(int i=0; i<count; i++)
    {
        a *= 10;
        result += (a/b + '0');
        a = a%b;
    }
    if(a == 0)
        return result;
    
    result += "(";
    int r = a;
    while(true)
    {
        r *= 10;
        result += (r/b + '0');
        r = r%b;
        if(r == a)
            break;
    }
    result += ")";
    return result;
}


int main()
{
    int n=20;
    while(n)
    {
        int a=rand()%1000;
        int b=rand()%300+1;

        string s1 = divide(a,b);
        string s2 = divide2(a,b);

        if(s1 != s2)
        {
            cout << "error: " << a << "\t" << b  << endl;
            cout << s1 << endl;
            cout << s2 << endl;
        }
        n--;
    }
    return 0;
}
