class Solution {
public:
    int myAtoi(string s) {

        int i = 0;

        int sign = 1;

        long long ans = 0;

        // Step 1 : Ignore spaces
        while(i < s.length() && s[i] == ' ')
        {
            i++;
        }

        // Step 2 : Check sign
        if(i < s.length() && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(i < s.length() && s[i] == '+')
        {
            i++;
        }

        // Step 3 : Read digits
        while(i < s.length() && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // Step 4 : Overflow check
            if(sign == 1 && ans > INT_MAX)
            {
                return INT_MAX;
            }

            if(sign == -1 && -ans < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }

        return ans * sign;
    }
};