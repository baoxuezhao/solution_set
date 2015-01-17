#define MAX_READERS 10
 
class Semaphore {
	private:
		Mutex* lockers[MAX_READERS];
		Mutex semaphoreLock;
		int i;
	public:
		Semaphore() {
			i = 0;
		}
		
		int increase() {
			semaphoreLock.lock();
			
			if(i == MAX_READERS) {
				semaphoreLock.unlock();
				return -1;
			}
			
			lockers[i++].lock();
			semaphoreLock.unlock();
			
			return 0;
		}
		
		int decrease() {
			semaphoreLock.lock();
			
			if(i == 0) {
				semaphoreLock.unlock();
				return -2;
			}
			
			lockers[i--].unlock();
			semaphoreLock.unlock();
			
			return 0;
		}
};
 
class ReadWriteMutex {
	private:
		Semaphore readerSem;
		Semaphore mutex;
	public:
		ReadWriteMutex() {
			isWriting = false;
		}
		
		int tryRead(char* buf, size_t sz) {		
			if(readerSem.increase() != 0) return -2;
			
			// Read ...
			
			readerSem.decrease();
			
			return 0;
		}
		
		void write() {
		  mutex.lock();
			for(int i = 0; i < MAX_READERS; i++)
				semaphoreLock.increase();
			mutex.unlock();
				
			// Write here
			
			for(int i = 0; i < MAX_READERS; i++)
				semaphoreLock.decrease();
		}
};
