

class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int i = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: Set limit
        long long limit;

        if (sign == 1) {
            limit = INT_MAX;
        }
        else {
            limit = -(long long)INT_MIN;
        }

        long long num = 0;

        // Step 4: Read digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            // Step 5: Check overflow
            if (num > limit / 10 ||
                (num == limit / 10 && digit > limit % 10)) {

                if (sign == 1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }

            // Step 6: Build number
            num = num * 10 + digit;

            i++;
        }

        // Step 7: Return answer
        return (int)(num * sign);
    }
};
