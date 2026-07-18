class Solution {
public:
    int retsum(vector<int>& nums, int div){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+ceil(double(nums[i])/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int maxi=*max_element(nums.begin(),nums.end());
        int high=maxi;
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if (retsum(nums,mid)<=threshold){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};