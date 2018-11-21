class Solution {
    struct LetterLog {
        std::string ident;
        std::string content;
        LetterLog(std::string& s1, std::string& s2) {
            ident = s1;
            content = s2;
        }
    };
    struct LetterLogCmp {
        bool operator()(const LetterLog& lhs, const LetterLog& rhs) const { 
            if (lhs.content != rhs.content) {
                return lhs.content < rhs.content;
            }
            return lhs.ident < rhs.ident;
        }
    };
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::map<LetterLog, string*, LetterLogCmp> letter_logs;
        vector<string*> digit_logs;
        for (auto& str : logs) {
            int space_pos = str.find(' ');           
            std::string ident = str.substr(0, space_pos);
            std::string ignore_ident = str.substr(space_pos + 1);
            if (ignore_ident[0] >= '0' && ignore_ident[0] <= '9') {
                digit_logs.push_back(&str);
            } else {
                letter_logs.insert(std::make_pair(LetterLog(ident, ignore_ident), &str));
            }
        }
        vector<string> res;
        for (auto& pair : letter_logs) {
            res.push_back(*pair.second);
        }
        for (auto& str : digit_logs) {
            res.push_back(*str);
        }
        return res;
    }
};
