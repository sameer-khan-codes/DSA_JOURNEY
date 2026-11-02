
class Solution {
public:

    int romanToValue(char ch) {

        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }

        return 0;
    }

    int romanToInt(string s) {

        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int current = romanToValue(s[i]);

            if (i + 1 < n &&
                current < romanToValue(s[i + 1])) {

                ans -= current;
            }
            else {
                ans += current;
            }
        }

        return ans;
    }
};
