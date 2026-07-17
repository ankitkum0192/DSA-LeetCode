class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int bq=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt==k){
                    bq++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return bq>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * k * m;
        if(total > bloomDay.size()) return -1;

        int mn=*min_element(bloomDay.begin(),bloomDay.end());
        int mx=*max_element(bloomDay.begin(),bloomDay.end());
        int low=mn, high=mx;
        int result = -1;

        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};