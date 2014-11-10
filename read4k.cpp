#include <iostream>

using namespace std;

int read(char *buf, int len)
{
	if(n <= 0) return 0;
	static char *interBuf = (char*)malloc(4096*sizeof(char));
	static int start = 0, end = 0;

	int readCount = 0;

	while(readCount < len)
	{
		if(end-start >= (len - readCount))
		{
			memcpy(buf + readCount, interBuf + start, (len - readCount));
			start += (len - readCount);
			readCount = len;
		}
		else
		{
			if(end-start > 0)
			{
				memcpy(buf + readCount, interBuf + start, end-start);
				readCount += (end-start);
			}
			start = 0;
			end = read4k(interBuf);
			if(end == 0)
			{
				break;
			}
		}
	}
	return readCount;
}
