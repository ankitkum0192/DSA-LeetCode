class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            freq[c] = freq[c] + 1;
        }

        int n = s.size();
        vector<vector<char>> buckets(n + 1);

        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                char ch = (char)i;
                int count = freq[i];
                buckets[count].push_back(ch);
            }
        }

        string result = "";
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                char ch = buckets[i][j];
                for (int k = 0; k < i; k++) {
                    result += ch;   // fix: += use kiya, + nahi
                }
            }
        }

        return result;
    }
};