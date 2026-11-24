class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int mx = 0, ml = 1;

        // Find maximum element and LCM of entire array
        for (int x : nums) {
            mx = max(mx, x);
            ml = lcm(ml, x);
        }

        long long limit = 1LL * mx * ml;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                prod *= nums[j];

                // Prevent unnecessary calculations
                if (prod > limit)
                    break;

                g = gcd(g, (long long)nums[j]);

                l = l / gcd(l, (long long)nums[j])
                      * nums[j];

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
