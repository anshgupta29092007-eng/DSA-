
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long sum = 0;
        int mx = 0;

        int k = k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            for (int x : diff) {
                operations += max(x - mid, 0);
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            k -= max(diff[i] - left, 0);
            diff[i] = min(diff[i], left);
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == left) {
                diff[i]--;
                k--;
            }
        }

        long long ans = 0;

        for (int x : diff) {
            ans += 1LL * x * x;
        }

        return ans;
    }
};
