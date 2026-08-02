class Solution {
public:
    int maxDepth(string s) {
        int maxsum=0;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            if(maxsum<cnt) {
                maxsum=max(maxsum,cnt);
            }
            if(s[i] == ')') cnt--;
        }
        return maxsum;
        
    }
};