#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int DN = 512;
const int FN = 10000, FK = 4;

class BigInt
{
private:
	int digits[DN], len, sign;
	void format()
	{
		while(len > 1 && digits[len-1] == 0) len--;
		if(len == 1 && digits[0] == 0) sign = 1;
	}

public:
	BigInt(int e = 0): len(1), sign(1)
	{
		memset(digits, 0, sizeof(digits));
		digits[0] = e;
	}

	BigInt(const string &s)
	{
		string str(s);
		if(str.size() == 0)
			*this = BigInt(0);
		memset(digits, 0, sizeof(digits));
		
		if(str[0] == '-')
		{
			sign = -1;
			str = str.substr(1);
		}
		else
		{
			sign = 1;
			if(str[0] == '+') str = str.substr(1);
		}
		len = (str.size()-1)/FK + 1;

		for(int i=str.size(), k = 0; i>0; i-=FK, k++)
		{
			int sum = 0;
			for(int j=max(0, i-FK); j<i; j++)
			{
				sum = sum*10 + (str[j]-'0');
			}
			digits[k] = sum;
		}
		format();
	}

	BigInt(const BigInt &b)
	{
		sign = b.sign;
		len = b.len;
		memcpy(digits, b.digits, sizeof(digits));
	}

	BigInt& operator=(const int b)
	{
		*this = BigInt(b);
	}

	BigInt& operator=(const BigInt &b)
	{
		sign = b.sign;
		len = b.len;
		memcpy(digits, b.digits, sizeof(digits));
	}

	bool lessThanWithoutSign(const BigInt &b) const
	{
		if(b.len != len)
			return len < b.len;
		else
		{
			for(int i=len-1; i>=0; i--)
			{
				if(digits[i] != b.digits[i])
					return digits[i] < b.digits[i];
			}
		}
	}

	bool lessThanWithSign(const BigInt &b) const
	{
		if(sign == 1 && b.sign == -1)
			return false;
		if(sign == -1 && b.sign == 1)
			return true;

		if(sign == 1 && b.sign == 1)
			return lessThanWithoutSign(b);
		else if(sign == -1 && b.sign == -1)
		{
			const BigInt tmp(*this);
			return b.lessThanWithoutSign(tmp);
		}
	}

	bool equal(const BigInt &b)
	{
		return !lessThanWithSign(b) && !(b.lessThanWithSign(*this));
	}

	void addWithoutSign(const BigInt &b)
	{
		len = max(len, b.len);
		int carry = 0;
		for(int i=0; i<len; i++)
		{
			digits[i] += (carry + b.digits[i]);
			carry = digits[i]/FN;
			digits[i] %= FN;
		}
		if(carry != 0)
			digits[len++] = carry;
		format();
	}

	void subWithoutSign(const BigInt &b)
	{
		int carry = 0;
		for(int i=0; i<len; i++)
		{
			digits[i] -= (carry + b.digits[i]);
			if(digits[i] < 0)
			{
				carry = 1;
				digits[i] += FN;
			}
			else
				carry = 0;
		}
		format();
	}

	BigInt add(const int b)
	{
		return add(BigInt(b));
	}

	BigInt add(const BigInt &b)
	{
		BigInt res(*this);
		//same sign
		if(res.sign == b.sign)
		{
			res.addWithoutSign(b);
		}
		else
		{
			if(b.lessThanWithoutSign(res))
				res.subWithoutSign(b);
			else
			{
				BigInt tmp(b);
				tmp.subWithoutSign(res);
				res = tmp;
			}
		}
		res.format();
		return res;
	}

	BigInt sub(const int b)
	{
		return sub(BigInt(b));
	}

	BigInt sub(const BigInt &b)
	{
		BigInt res(*this);

		if(sign * b.sign < 0)
		{
			res.addWithoutSign(b);
		}
		else
		{
			if(b.lessThanWithoutSign(res))
			{
				res.subWithoutSign(b);
			}
			else
			{	
				BigInt tmp(b);
				tmp.subWithoutSign(res);
				res.len = tmp.len;
				res.sign = 0-res.sign;
				memcpy(res.digits, tmp.digits, sizeof(digits));
			}
		}
		res.format();
		return res;
	}

	BigInt multiply(const int bb)
	{
		int b = abs(bb);
		BigInt res(*this);

		int carry = 0;
		for(int i=0; i<len; i++)
		{
			res.digits[i] *= b;
			res.digits[i] += carry;
			carry = (res.digits[i]/FN);
			res.digits[i] %= FN;
		}
		if(carry)
			res.digits[res.len++] = carry;
		res.format();
		res.sign = (bb>0)?res.sign:(0-res.sign);

		return res;
	}

	BigInt multiply(const BigInt &b)
	{
		BigInt res;
		res.len = len + b.len + 1;

		int carry = 0;
		for(int i=0; i<len; i++)
		{
			carry = 0;
			int val = digits[i];
			for(int j=0; j<b.len; j++)
			{
				res.digits[i+j] += (val * b.digits[j] + carry);
				carry = res.digits[i+j]/FN;
				res.digits[i+j] %= FN;
			}
			if(carry)
			{
				res.digits[i+b.len] = carry;
			}
		}
		res.sign = (sign*b.sign);
		res.format();
		return res;
	}

	BigInt divide(const int b)
	{
		int num = 0;
		BigInt shang;
		for(int i=len-1; i>=0; i--)
		{
			num = num * FN + digits[i];
			shang = shang.multiply(FN);
			shang = shang.add(num/b);
			num %= b;
		}
		shang.format();
		shang.sign = (b>0)?sign:(0-sign);

		return shang;
	}

	BigInt divide(const BigInt &b)
	{
		BigInt a(*this);
		BigInt shang;

		BigInt aa=a, bb=b;
		bb.sign = 1;
		aa.sign = 1;

		int count = 0;
		BigInt factor(1);
		while(!aa.lessThanWithoutSign(bb))
		{
			while(aa.len > bb.len)
			{
				bb = bb.multiply(FN);
				factor = factor.multiply(FN);
			}	

			while(aa.lessThanWithoutSign(bb))
			{
				bb = bb.divide(10);
				factor = factor.divide(10);
			}
			
			shang = shang.add(factor);
			
			aa = aa.sub(bb);
			bb = b;
			bb.sign = 1;
			factor = BigInt(1);
			
		}
		shang.format();
		shang.sign = a.sign*b.sign;

		return shang;
	}

	void print() const
	{
		if(sign == -1)
			putchar('-');
		printf("%d", digits[len-1]);
		for(int i = len-2; i>=0; i--)
		{
			printf("%0*d", FK, digits[i]);
		}
		printf("\n");
	}
};


int main()
{
	BigInt int0(0);
	BigInt int1(123);
	BigInt int2(string("1235678"));
	BigInt int3(string("-1235678"));	
	BigInt int4(string("123453845"));
	BigInt int5(string("-123453845"));
	BigInt int6(string("-99999999"));

	BigInt int55 = int1.add(int2);
	BigInt int66 = int2.add(int1);

	int55.print();
	int66.print();

	BigInt int7 = int2.add(int4);
	int7.print();
	cout << 12345678 + 12345384567 << endl;

	BigInt int8 = int3.add(int5);
	int8.print();
	cout << (-12345678) + (-12345384567) << endl;

	BigInt int9 = int2.add(int5);
	int9.print();
	cout << 12345678 + (-12345384567) << endl;

	BigInt int10 = int3.add(int4);
	int10.print();
	cout << (-12345678) + 12345384567 << endl;

	BigInt int11 = int2.multiply(-18);
	int11.print();
	cout << (1235678*(-18)) << endl;

	BigInt int12 = int3.multiply(101);
	int12.print();
	cout << (-1235678*101) << endl;


	BigInt int13 = int2.multiply(int4);
	int13.print();

	BigInt inttt(string("1234567881818181818181"));
	BigInt int14 = inttt.multiply(BigInt("1235678"));
	int14.print();

	BigInt inttt2(string("1525528371069327272726261718"));
	BigInt int15 = inttt2.divide(BigInt("1235678"));
	int15.print();

	return 0;
}
