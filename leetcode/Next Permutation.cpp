class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size()-2;
        for(; i>=0; i--)
        {
            if(num[i] < num[i+1]) break;
        }
        if(i == -1)
        {
            reverse(num, 0, num.size()-1);
            return;
        }
        
        int j = num.size()-1;
        for(; j>i; j--)
            if(num[j] > num[i])
                break;
        
        swap(num[i], num[j]);
        reverse(num, i+1, num.size()-1);
        return;
    }
    
    void reverse(vector<int> &num, int l, int r)
    {
        while(l <= r)
        {
            swap(num[l], num[r]);
            l++;
            r--;
        }
    }
};
