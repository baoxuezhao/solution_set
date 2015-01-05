class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res;
        int carry = 0;
        for(int i=0; i<max(a.size(), b.size()); i++)
        {
            int v1 = (i<a.size())?a[i]-'0':0;
            int v2 = (i<b.size())?b[i]-'0':0;
            res.push_back((v1+v2+carry)%2 + '0');
            carry = (v1+v2+carry)/2;
        }
        if(carry)
            res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
