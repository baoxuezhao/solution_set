class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int t1 = 0, t2 = 0;
        int start = 0;
        int t11 = 0, t22 = 0;
        for(int i=0; i<gas.size(); i++)
        {
            t1 += gas[i];
            t2 += cost[i];
            
            t11 += gas[i];
            t22 += cost[i];
            
            if(t1 < t2)
            {
                t1 = 0;
                t2 = 0;
                start = i+1;
            }
        }
        return (t11 >= t22)?start:-1;
    }
};
