class Solution {
public:
    bool check(vector<int >& weights,int cap,int days){
        int load=0;
        int n=weights.size();
        int needays=1;
        for(int i=0;i<n;i++){
            if(load + weights[i]>cap){
                needays++;
                load=0;
            }
            load+=weights[i];

        }
        return needays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int low=maxi;
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(weights,mid,days)){
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