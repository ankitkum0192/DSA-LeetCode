class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        long long org = x;
        if(x<0) return false;
        while(x!= 0){
            int digit = x%10;
            x=x/10;
            rev=rev*10+digit;
        }
       if(org==rev){
        return true;
       }
       else
       return false;
        
    }
};