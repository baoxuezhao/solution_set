string longest(string str, int n)
{
    int longest = 0;
	int longest_start = -1;

	int occurance[256];
	int count = 0;
	memset(occurance, 0, sizeof(occurance));
	
	int len = str.size();
	int start = 0;
	for(size_t i = 0; i<len; i++)
	{
		if(occurance[str[i]] == 0)
        	count++;
		occurance[str[i]]++;
        
        while(count > n)
        {
        	occurance[str[start]]--;
        	if(occurance[str[start]] == 0)
        		count--;
            start++;
        }
		if(i-start+1 > longest)
		{
			longest = i-start+1;
			longest_start = start;
		}
    }
    if(longest > 0)
    	return str.substr(longest_start, longest);
    else
    	return "";
}
