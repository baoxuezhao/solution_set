/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        const int n = intervals.size();
        
        bool inserted = false;
        
        for(int i=0; i<n; i++)
        {
            if(intervals[i].end < newInterval.start)
                result.push_back(intervals[i]);
            else
            {
                if(!inserted)
                {
                    result.push_back(newInterval);
                    inserted = true;
                }
                
                if(overlap(intervals[i], result.back()))
                {
                    result.back().start = min(intervals[i].start, result.back().start);
                    result.back().end   = max(intervals[i].end,   result.back().end);
                }
                else
                {
                    result.push_back(intervals[i]);
                }
            }
        }

        if(!inserted)
        {
            result.push_back(newInterval);
        }
        return result;
    }
    
    bool overlap(Interval &in1, Interval &in2)
    {
        if(in2.start > in1.end || in1.start > in2.end)
            return false;
        return true;
    }
};
