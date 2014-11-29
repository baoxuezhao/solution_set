#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unordered_map>
#include <thread>         // std::thread
#include <vector>         // std::vector

using namespace std;

class ReadWriteLock
{
public:
	ReadWriteLock(int num_readers)
	{
		maxReaderCount = num_readers;
		sem_init(&readerCount, 0, maxReaderCount);
		pthread_mutex_init(&mutex, NULL);
	}

	~ReadWriteLock()
	{
		sem_destroy(&readerCount);
	}

	void lockRead()
	{
		sem_wait(&readerCount); //minus 1
		cout << "lockRead()" << endl;
	}

	void unlockRead()
	{
		sem_post(&readerCount); //plus 1
		cout << "unlockRead()" << endl;
	}

	void lockWrite()
	{
		pthread_mutex_lock(&mutex);
		for(int i=0; i<maxReaderCount; i++)
			sem_wait(&readerCount); //minus 1
		pthread_mutex_unlock(&mutex);

		cout << "lockWrite()" << endl;
	}

	void unlockWrite()
	{
		for(int i=0; i<maxReaderCount; i++)
			sem_post(&readerCount); //plus 1

		cout << "unlockWrite()" << endl;
	}

private:
	pthread_mutex_t mutex;
	sem_t readerCount;
	int maxReaderCount;
};

template<typename K, typename V>
class CurrentHashMap
{
public:
	CurrentHashMap()
	{
		rwlock = new ReadWriteLock(10);
	}

	~CurrentHashMap()
	{
		//delete rwlock;// = new ReadWriteLock(10);
	}

	void insert(K key, V value)
	{
		rwlock->lockWrite();
		hash[key] = value;
		rwlock->unlockWrite();
	}


	V get(K key)
	{
		rwlock->lockRead();
		V value;
		auto iter = hash.find(key);
		if(iter != hash.end())
		{
			value = iter->second;
		}
		rwlock->unlockRead();
		return value;
	}

	bool exist(K key)
	{
		rwlock->lockRead();
		bool res;
		if(hash.find(key) == hash.end())
			res = false;
		else
			res = true;
		rwlock->unlockRead();

		return res;
	}

	void remove(K key)
	{
		rwlock->lockWrite();
		hash.erase(key);
		rwlock->unlockWrite();
	}

private:
	ReadWriteLock *rwlock;
	unordered_map<K, V> hash;
};

void insert_global (CurrentHashMap<int, int> &hashmap, int n) 
{ 
	hashmap.insert(n, n);
}

void read_global (CurrentHashMap<int, int> &hashmap, int n) 
{ 
	hashmap.get(n);
}

void remove_global (CurrentHashMap<int, int> &hashmap, int n) 
{ 
	hashmap.remove(n);
}

int main()
{
	CurrentHashMap<int, int> hashmap;
	vector<std::thread> threads;

	for(int i=0; i<100; i++)
	{
		if(i%3 == 0)
			threads.push_back(thread(insert_global, hashmap, i));
		else if(i%3 == 1)
			threads.push_back(thread(read_global, hashmap, i));
		else
			threads.push_back(thread(remove_global, hashmap, i));
	}

	for (auto& th : threads) th.join();

	return 0;
}
