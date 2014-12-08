class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        const int n1 = S.size();
        const int n2 = L.size();
        const int n3 = L[0].size();
        
        const int len = n2*n3;
        unordered_map<string, int> hash;
        for(int i=0; i<n2; i++)
        {
            hash[L[i]]++;
        }
        
        for(int i=0; i+len <= n1; i++)
        {
            unordered_map<string, int> hashcopy(hash);
            int j;
            for(j=0; j<n2; j++)
            {
                int start = i + n3*j;
                string sub = S.substr(start, n3);
                if(hashcopy[sub] > 0)
                    hashcopy[sub]--;
                else
                    break;
            }
            if(j == n2)
                result.push_back(i);
        }
        return result;
    }
};
