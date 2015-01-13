long long concat(long long s1, long long s2)
{
    int n = 1;
    int b = 1;
    while(s2 / b >= 10) n++, b*=10;
    while(n--) s1 *= 10;
    return s1+s2;
}

struct comp
{
    bool operator()(const int &s1, const int &s2)
    {
        long long t1 = concat(s1, s2);
        long long t2 = concat(s2, s1);
        return t1 < t2;
    }
};

class Solution {
public:
    string largestNumber(vector<int> &num) {
        priority_queue<int, vector<int>, comp> pq;
        for(int i=0; i<num.size(); i++)
            pq.push(num[i]);
        
        string res;
        while(!pq.empty())
        {
            res += itoa(pq.top());
            pq.pop();
        }
        
        int i=0;
        while(i<res.size() && res[i] == '0') i++;
        if(i == res.size())
            return "0";
        return res.substr(i, res.size()-i);
    }
    
    string itoa(int n)
    {
        if(n == 0) return "0";
        string res;
        while(n)
        {
            res += n%10 + '0';
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
