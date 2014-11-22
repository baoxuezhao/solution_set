class RWLock
{
public:
	RWLock(int num): maxReads(num)
	{
		curReads = 0;
	}

	void lockRead()
	{
		mutex.lock();
		curReads++;
		mutex.unlock();
	}
	
	
	void unlockRead()
	{
	}
	
	void lockWrite()
	{
	}
	
	
	void unlockWrite()
	{
	}

private:
	int maxReads;
	int curReads;
	mutex_t mutex;
};
