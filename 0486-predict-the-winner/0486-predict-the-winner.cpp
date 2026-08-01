class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] = max score difference (current player - other player) for subarray [i,j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single element subarray, current player le hi lega
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        // Chhote subarrays se bade subarrays tak build karo
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                // Left choose karo: nums[i] - baaki subarray[i+1][j] ka result (opponent ka advantage)
                int chooseLeft = nums[i] - dp[i+1][j];
                
                // Right choose karo: nums[j] - baaki subarray[i][j-1] ka result
                int chooseRight = nums[j] - dp[i][j-1];
                
                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }
        
        // Agar final difference >= 0, player 1 jeeta (ya tie, jo bhi player1 ke favor mein hai)
        return dp[0][n-1] >= 0;
    }
};