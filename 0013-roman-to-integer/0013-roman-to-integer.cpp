class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n - 1; i++) {

            if(roman[s[i]] < roman[s[i+1]]) {
                ans = ans - roman[s[i]];
            }
            else {
                ans = ans + roman[s[i]];
            }
        }

        ans = ans + roman[s[n-1]];

        return ans;
    }
};