//binary bit map
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        
        int n = (1 << S.size());
        vector<int> sub;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<S.size(); j++)
            {
                if(i & (1 << j)) sub.push_back(S[j]);
            }
            res.push_back(sub);
            sub.clear();
        }
        return res;
    }
};

//Solution incremental construct
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res(1);
        
        for(int i=0; i<S.size(); i++)
        {
            for(int j=res.size()-1; j>=0; j--)
            {
                vector<int> t(res[j].begin(), res[j].end());
                t.push_back(S[i]);
                res.push_back(t);
            }
        }
        return res;
    }
};
