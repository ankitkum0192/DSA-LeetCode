class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>map;
        map[0]=1;
        int count=0;
        int n=nums.size();
        int presum=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            count+=map[remove];
            map[presum]+=1;
        }
        return count;
        
    }
};