class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_map<int, bool> mp;   // hash map bana rahe hain
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = true;        // har element ko map mein mark kar do
        }

        for (int i = mini; i <= maxi; i++) {
            if (mp.find(i) == mp.end()) {   // agar map mein nahi mila
                ans.push_back(i);           // to missing hai, add kar do
            }
        }
        return ans;
    }
};