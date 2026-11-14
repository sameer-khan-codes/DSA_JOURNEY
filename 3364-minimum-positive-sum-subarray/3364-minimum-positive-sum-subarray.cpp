
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        // Check every allowed subarray length
        for (int len = l; len <= r; len++) {

            int sum = 0;

            // Calculate the first window sum
            for (int i = 0; i < len; i++) {
                sum += nums[i];
            }

            // Check first window
            if (sum > 0) {
                ans = min(ans, sum);
            }

            // Slide the window
            for (int i = len; i < n; i++) {

                sum += nums[i] - nums[i - len];

                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
