class Solution {
public:
    // Helper: check kitne subarrays chahiye honge agar max sum allowed = 'maxSum' ho
    bool isPossible(vector<int>& nums, int maxSum, int k) {
        int subarrayCount = 1; // pehla subarray shuru
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                // naya subarray shuru karna padega
                subarrayCount++;
                currentSum = num;

                // agar num khud maxSum se bada hai, ye maxSum kabhi possible nahi
                if (currentSum > maxSum) return false;
            } else {
                currentSum += num;
            }
        }

        return subarrayCount <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, k)) {
                ans = mid;       // ye valid hai, chhota try karo
                high = mid - 1;
            } else {
                low = mid + 1;   // ye kaafi nahi, bada try karo
            }
        }

        return ans;
    }
};
