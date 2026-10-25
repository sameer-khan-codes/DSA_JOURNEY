
class Solution {
public:
    int sumbyD(vector<int> &nums, int div) {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ceil((double)nums[i] / (double)div);
        }

        return (int)sum;
    }

    int smallestDivisor(vector<int> &nums, int limit) {
        int n = nums.size();

        if (n > limit) {
            return -1;
        }

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumbyD(nums, mid) <= limit) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
