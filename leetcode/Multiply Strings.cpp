class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size();
        int n = num2.size();
        string res(m+n, '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int carry = 0;
        for(int i=0; i<m; i++)
        {
            int n1 = num1[i]-'0';
            carry = 0;
            for(int j=0; j<n; j++)
            {
                int n2 = num2[j]-'0';
                int tmp = (n1*n2 + (res[i+j]-'0') + carry);
                res[i+j] = tmp%10 + '0';
                carry = tmp/10;
            }
            if(carry)
                res[i+n] += carry;
        }
        
        int i;
        for(i=res.size()-1; i>=0; i--)
            if(res[i] != '0')
                break;
        
        if(i == -1)
            return "0";
        else
        {
            res.resize(i+1);
            reverse(res.begin(), res.end());
            return res;
        }
    }
};
