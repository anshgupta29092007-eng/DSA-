
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Step 1: Calculate cost of every substring
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int ans = n;

                // Try every valid divisor
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int cnt = 0;

                    // Compare mirror characters
                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;

                        while (l < r) {
                            if (s[l] != s[r]) {
                                cnt++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    ans = min(ans, cnt);
                }

                cost[i][j] = ans;
            }
        }

        // Step 2: DP
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        // i = number of characters considered
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= k; j++) {

                // Previous partition ends at h-1
                for (int h = 0; h < i; h++) {

                    if (i - h < 2) continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[h][j - 1] + cost[h][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
