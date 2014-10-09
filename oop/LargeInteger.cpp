class LargeInteger
{
	//the LSB stores in integer[0]
	vector<int> integer;
	bool negative;
	
	LargeInteger()
	{
		integer.push_back(0);
		negative = false;
	}
		
	LargeInteger(int val)
	{
		if(val < 0)
		{
			negative = true;
			LargeInteger(0-val);
			return;
		}
		else if(val == 0)
		{
			LargeInteger();
			return;
		}
		while(val)
		{
			integer.push_back(val % 10 + '0');
			val /= 10;
		}
	}
	
	LargeInteger plus(LargeInteger &other)
	{
		
	}
	
	LargeInteger minus(LargeInteger &other)
	{
	}
	
	
	
}
