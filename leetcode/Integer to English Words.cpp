class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string order[] = {"", "Thousand", "Million", "Billion"};
        int idx = 0;
        string res;
        while(num > 0) {
            int tail = num % 1000;
            num = num / 1000;
            if (tail != 0) {
                string tail_str = unitToWords(tail);
                res = tail_str + order[idx] + " " + res;
            }
            idx++;
        }
        while (res.size() > 0 && res[res.size()-1] == ' ') {
            res = res.substr(0, res.size()-1);
        }
        return res;
    }
    
    string unitToWords(int num) {
        string res;
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
        string arr1[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string arr2[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
        if(num/100 > 0) {
            res += arr[num/100] + " " + "Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += arr1[num/10] + " ";
            if (num%10) {
                res += arr[num%10] + " ";
            }
        } else if (num >= 10) {
            res += arr2[num-10] + " ";
        } else if (num > 0) {
            res += arr[num%10] + " ";
        }
        return res;
    }
};
