class Solution {
public:
    bool isNumber(const char *s) {
        
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXP,        // 5
            NUM_INPUTS   // 6
        };
        
        int trans_table[][NUM_INPUTS] = {
            -1, 0, 1, 3, 2,-1,  // 0 invalid state
            -1,-1,-1, 3, 2,-1,  // 1 state after sign
            -1,-1,-1, 4,-1,-1,  // 2 state after sign and dot
            -1, 8,-1, 3, 4, 5,  // 3 state after digit
            -1, 8,-1, 4,-1, 5,  // 4 state after input dot with digit
            -1,-1, 6, 7,-1,-1,  // 5 state after input exp
            -1,-1,-1, 7,-1,-1,  // 6 state after input exp and sign
            -1, 8,-1, 7,-1,-1,  // 7 state after input exp and digit
            -1, 8,-1,-1,-1,-1,  // 8 state with tail space
        };
        
        int state = 0;
        
        for(; *s!='\0'; s++)
        {
            InputType input = INVALID;
            if(*s == ' ')
                input = SPACE;
            else if(*s == '+' || *s == '-')
                input = SIGN;
            else if(isdigit(*s))
                input = DIGIT;
            else if(*s == '.')
                input = DOT;
            else if(*s == 'E' || *s == 'e')
                input = EXP;
            
            state = trans_table[state][input];
            if(state == -1)
                return false;
        }
        return state == 3 || state == 4 || state == 7 || state == 8;
        
    }
};


//no state machine solution
//reference: http://www.yanyulin.info/pages/2014/10/38958011441714.html
class Solution {
public:
    bool isNumber(const char *s) {
        bool res = true;
        
        bool num = false;
        bool dot = false;
        bool exp1 = false;
        
        while(*s == ' ') s++;
        if(*s == 0) return false;
        
        int n = strlen(s);
        while(n >= 0 && s[n-1] == ' ') n--;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') 
            {
                num = true;
            }
            else if(s[i] == '.')
            {
                if(exp1 || dot) 
                    return false;
                dot = true;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!num || exp1) 
                    return false;
                exp1 = true;
                num = false;
            }
            else if(s[i] == '-' || s[i] == '+')
            {
                if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
            }
            else
                return false;
        }
        
        return num;
    }
};
