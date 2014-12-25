#include <iostream>

using namespace std;

class AnySizeReader
{
public:
	AnySizeReader(int size)
	{
		start = 0;
		end = 0;
		buf_size = size;
		interBuf = (char*)malloc(buf_size*sizeof(char));
	}

	~AnySizeReader()
	{
		free(interBuf);
	}

	int read(char *buf, int len)
	{
		if(len <= 0) return 0;
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

				while(len - readCount >= buf_size)
				{
					int size = read4k(buf + readCount);
					readCount += size;
					if(size < buf_size)
						return readCount;
				}

				start = 0;
				end = read4k(interBuf);
				if(end == 0) break;
			}
		}
		return readCount;
	}

private:
	char *interBuf;
	int start, end;
	int buf_size;
};
