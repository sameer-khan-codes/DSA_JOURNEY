
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Calculate cost of every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                int ans = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = len / d;

                    for (int offset = 0; offset < d; offset++) {
                        int left = l + offset;
                        int right = l + offset + (groups - 1) * d;

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    ans = min(ans, changes);
                }

                cost[l][r] = ans;
            }
        }

        // DP
        const int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p <= i - 2; p++) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
