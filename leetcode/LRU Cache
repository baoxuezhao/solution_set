//comments: do not call list::size frequently, since it is a time-consuming operation.
//when eliminate a node from the end, remember to delete the record from the hashmap

typedef list<pair<int,int> >::iterator listIter;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) 
    {
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        
        listIter iter = cacheMap[key];
        int val = iter->second;
        cacheList.erase(iter);
        cacheList.insert(cacheList.begin(), make_pair(key, val));
        cacheMap[key] = cacheList.begin();
        return val;
        
    }
    
    void set(int key, int value) 
    {
        if(cacheMap.find(key) != cacheMap.end())
        {
            listIter iter = cacheMap[key];
            cacheList.erase(iter);
            size--;
        }
        
        if(size == capacity)
        {
            //be careful of this line
            cacheMap.erase(cacheList.back().first);
            cacheList.pop_back();
            size--;
        }
        cacheList.insert(cacheList.begin(), make_pair(key, value));
        cacheMap[key] = cacheList.begin();
        size++;
    }

private:
    list<pair<int,int> > cacheList;
    unordered_map<int, listIter> cacheMap;
    int capacity;
    int size;
};
