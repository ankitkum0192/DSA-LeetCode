class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (balance > 0) {
                    result = result + s[i];
                }
                balance = balance + 1;
            }
            else {
                balance = balance - 1;
                if (balance > 0) {
                    result = result + s[i];
                }
            }
        }
        
        return result;
    }
};