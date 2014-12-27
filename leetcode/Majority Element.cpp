class Solution {
public:

    int partition(vector<int> &num, int start, int end)
    {
        int len = end-start+1;
        int p_pos = start + rand()%len;
        swap(num[end], num[p_pos]);
    
        int pivot = num[end];
    
        int left = start, right = end-1;
        while(left <= right)
        {
            while(num[left] < pivot) left++;
            while(num[right] > pivot) right--;
            
            if(left <= right)
            {
                swap(num[left], num[right]);
                left++;
                right--;
            }
        }
        swap(num[left], num[end]);
        return left;
    }
    
    int getKth(vector<int> &num, int start, int end, int k)
    {
        int mid = partition(num, start, end);
        int mid_idx = mid - start;
    
        if(mid_idx == k)
            return num[mid];
        else if(mid_idx < k)
            return getKth(num, mid+1, end, k-mid_idx-1);
        else if(mid_idx > k)
            return getKth(num, start, mid-1, k);
    }
    
    int majorityElement(vector<int> &num) 
    {
        const int n = num.size();
        int mid = n/2;
        return getKth(num, 0, n-1, mid);
    }

};
