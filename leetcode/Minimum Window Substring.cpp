class Solution {
public:
    string minWindow(string S, string T) {
        const int n1 = S.size();
        const int n2 = T.size();
        
        int expected[256];
        int founded[256];
        
        memset(expected, 0, sizeof(expected));
        memset(founded,  0, sizeof(founded));
        
        for(int i=0; i<n2; i++)
        {
            expected[T[i]]++;
        }
        
        int count = 0;
        int start = 0;
        int shortest = INT_MAX;
        int shortest_start = -1;
        
        for(int i=0; i<n1; i++)
        {
            if(expected[S[i]] == 0) continue;
            
            founded[S[i]]++;
            if(founded[S[i]] <= expected[S[i]])
            {
                count++;
            }
            
            if(count == n2)
            {
                while(expected[S[start]] == 0 || founded[S[start]] > expected[S[start]])
                {
                    if(founded[S[start]] > expected[S[start]])
                        founded[S[start]]--;
                    start++;
                }
                if(i-start+1 < shortest)
                {
                    shortest = i-start+1;
                    shortest_start = start;
                }
                founded[S[start]]--;
                start++;
                count--;
            }
            
        }
        if(shortest_start == -1)
        {
            return "";
        }
        else
        {
            return S.substr(shortest_start, shortest);
        }
    }
};
