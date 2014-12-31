class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        const int n = num.size();
        vector<vector<int> > res;
        
        if(n < 4)
            return res;
            
        unordered_map<int, vector<pair<int, int> > > pairs;
        std::sort(num.begin(), num.end());
        
        for(int i=0; i<num.size(); i++)
        {
            for(int j=i+1; j<num.size(); j++)
            {
                pairs[num[i]+num[j]].push_back(make_pair(i, j));
            }
        }
        
        for(auto p: pairs)
        {
            int val = p.first;
            vector<pair<int,int> > &vec = p.second;
            
            if(pairs.find(target-val) != pairs.end())
            {
                vector<pair<int,int> > &vec2 = pairs[target-val];
                
                for(int i=0; i<vec.size(); i++)
                {
                    for(int j=0; j<vec2.size(); j++)
                    {
                        if(vec[i].second < vec2[j].first)
                        {
                            vector<int> pp{num[vec[i].first], num[vec[i].second], num[vec2[j].first], num[vec2[j].second]};
                            sort(pp.begin(), pp.end());
                            res.push_back(pp);   
                        }
                    }
                }
            }
        }
        
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
