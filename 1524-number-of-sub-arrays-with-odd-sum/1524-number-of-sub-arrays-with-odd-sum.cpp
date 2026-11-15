
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;

        int even = 1;
        int odd = 0;
        int parity = 0;
        int ans = 0;

        for (int x : arr) {
            parity ^= (x % 2 != 0);

            if (parity == 1) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
