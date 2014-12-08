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
