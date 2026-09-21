class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;

            vector<long long> newDp(k, 0);

            // Start a new subarray containing only num
            newDp[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                newDp[newR] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};
