
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        vector<int> cnt(31, 0);

        // Count set bits at every position
        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (num & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (cnt[bit] > 0) {
                    num |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
