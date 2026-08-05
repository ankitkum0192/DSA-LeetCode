class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;  // result track karne ke liye
        
        for (int i = 0; i < s.size(); i++) {
            // Case 1: Odd length palindrome (center = single char i)
            int len1 = expandFromCenter(s, i, i);
            
            // Case 2: Even length palindrome (center = i aur i+1 ke beech)
            int len2 = expandFromCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                // palindrome ka start index nikalo current length se
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    // left aur right se expand karo jab tak match kare
    int expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // loop tootne ke baad left, right dono ek-ek step aage/peeche ja chuke honge
        // isliye actual palindrome length = right - left - 1
        return right - left - 1;
    }
};