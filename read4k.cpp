#include <iostream>
#define 4K 4096

int read(char *buf, int len)
{
	if(n <= 0) return 0;
	static char *interBuf = (char*)malloc(4K*sizeof(char));
	static int start = 0, end = 0;

	int readCount = 0;

	while(readCount < len)
	{
		//the remaining content in the buffer is enough
		if(end-start >= (len - readCount))
		{
			memcpy(buf + readCount, interBuf + start, (len - readCount));
			start += (len - readCount);
			readCount = len;
		}
		//no enough content in the buffer
		else
		{
			if(end-start > 0)
			{
				memcpy(buf + readCount, interBuf + start, end-start);
				readCount += (end-start);
			}
			
			//read directly to the target buffer to save memcpy
			while(len - readCount >= 4K)
			{
				int size = read4k(buf + readCount);
				readCount += size;
				if(size < 4K)
					return readCount;
			}

			start = 0;
			end = read4k(interBuf);
			if(end == 0) break;
		}
	}
	return readCount;
}
