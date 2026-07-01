class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int longest=1;
        int ls=INT_MIN;
        int count=0;
        for(int i =0;i<n;i++){
            if(nums[i]-1==ls){
                count+=1;
                ls=nums[i];
            }else if(nums[i] !=ls){
                count=1;
                ls=nums[i];
            }
            longest=max(longest,count);

        }
        return longest;



        
    }
};