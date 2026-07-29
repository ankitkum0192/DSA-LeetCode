class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Step 1: extract words (stringstream >> automatically skips extra spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: reverse the order of words
        reverse(words.begin(), words.end());

        // Step 3: join with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};