class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        vector<vector<int>> prefix(n+1, vector<int>(26,0));
        for (int i=0;i<n;i++){
            for(int c=0;c<26;c++){
                prefix[i+1][c]=prefix[i][c];
            }
            prefix[i+1][s[i]-'a']++;
            
        }
        int beauty=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int maxf=0;
                int minf=INT_MAX;
                for(int c=0;c<26;c++){
                    int freq=prefix[j+1][c]-prefix[i][c];
                    if(freq>0){
                        maxf=max(freq,maxf);
                        minf=min(freq,minf);
                    }
                }
            beauty+=maxf-minf;
            }
        }
       return beauty;

        
    }
};