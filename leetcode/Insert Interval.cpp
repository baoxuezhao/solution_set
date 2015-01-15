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


//in-place insertion
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
        const int n = intervals.size();
        int i;
        for(i=0; i<n; i++)
        {
            if(intervals[i].end >= newInterval.start)
                break;
        }
        
        if(i == n)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(!overlap(intervals[i], newInterval))
        {
            intervals.insert(intervals.begin()+i, newInterval);
        }
        else
        {
            intervals[i].start = min(intervals[i].start, newInterval.start);
            intervals[i].end   = max(intervals[i].end, newInterval.end);
            
            int j = i;
            i++;
            while(i < n && overlap(intervals[i], intervals[j]))
            {
                intervals[j].end = max(intervals[i].end, intervals[j].end);
                i++;
            }
            j++;
            while(i < n)
            {
                intervals[j++] = intervals[i++];
            }
            intervals.resize(j);
        }
        return intervals;
        
    }
    
    bool overlap(Interval &in1, Interval &in2)
    {
        if(in2.start > in1.end || in1.start > in2.end)
            return false;
        return true;
    }
};
