/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(const Interval &in1, const Interval &in2)
{
    if(in1.start != in2.start)
        return in1.start < in2.start;
    return in1.end < in2.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
            return intervals;
        
        std::sort(intervals.begin(), intervals.end(), comp);
        result.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(overlap(result.back(), intervals[i]))
            {
                result.back().start = min(result.back().start, intervals[i].start);
                result.back().end   = max(result.back().end  , intervals[i].end);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    
    bool overlap(const Interval &in1, const Interval &in2)
    {
        if(in1.start > in2.end || in2.start > in1.end)
            return false;
        return true;
    }
};


//////in-place solution
bool comp(const Interval &in1, const Interval &in2)
{
    if(in1.start != in2.start)
        return in1.start < in2.start;
    return in1.end < in2.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size() == 0)
            return intervals;
        
        std::sort(intervals.begin(), intervals.end(), comp);
        
        int j = 0;
        for(int i=1; i<intervals.size(); i++)
        {
            if(overlap(intervals[j], intervals[i]))
            {
                intervals[j].start = min(intervals[j].start, intervals[i].start);
                intervals[j].end   = max(intervals[j].end  , intervals[i].end);
            }
            else
            {
                intervals[++j] = intervals[i];
            }
        }
        intervals.resize(j+1);
        return intervals;
    }
    
    bool overlap(const Interval &in1, const Interval &in2)
    {
        if(in1.start > in2.end || in2.start > in1.end)
            return false;
        return true;
    }
};
