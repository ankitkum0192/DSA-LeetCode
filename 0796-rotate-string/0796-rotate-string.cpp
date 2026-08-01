class Solution {
public:
    bool rotateString(string s, string goal) {
        // Step 1: Length match nahi to shift se kabhi goal nahi ban sakta
        if (s.length() != goal.length()) return false;
        
        int n = s.length();
        
        // Step 2: n baar shift karo aur har baar check karo
        for (int i = 0; i < n; i++) {
            // Step 3: Ek shift perform karo
            // Leftmost character nikal ke rightmost pe daal do
            char firstChar = s[0];          // leftmost character save kar liya
            s = s.substr(1) + firstChar;    // baaki string + saved character end mein
            
            // Step 4: Check karo shift ke baad goal se match hua ya nahi
            if (s == goal) return true;
        }
        
        // Step 5: Poora cycle complete ho gaya, kabhi match nahi mila
        return false;
    }
};