
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;

        int right = n - 1;
        long long cost = 0;
        long long ans = 0;

        for (int left = n - 1; left >= 0; left--) {

            
            while (!dq.empty() && nums[dq.back()] < nums[left]) {

                int idx = dq.back();
                dq.pop_back();

                int r = dq.empty() ? right + 1 : dq.back();

                cost += 1LL * (nums[left] - nums[idx]) * (r - idx);
            }

            dq.push_back(left);

            
            while (cost > k) {

                int idx = dq.front();

                cost -= nums[idx] - nums[right];

                if (idx == right) {
                    dq.pop_front();
                }

                right--;
            }

            
            ans += right - left + 1;
        }

        return ans;
    }
};
