class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,char>maps,mapt;
        for(int i=0;i<s.size();i++){
            char c1=s[i];
            char c2=t[i];
            if(maps.count(c1)){
                if(maps[c1] != c2) return false;
            }
            if(mapt.count(c2)){
                if(mapt[c2] != c1) return false;
            }
            maps[c1]=c2;
            mapt[c2]=c1;
        }
        return true;
        
    }
};