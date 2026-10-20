
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k != 0) continue;

            if (check(nums, k, prefMax, suffMin, prefDrop))
                ans += k;

            int other = n / k;
            if (other != k &&
                check(nums, other, prefMax, suffMin, prefDrop)) {
                ans += other;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, int k,
               vector<int>& prefMax,
               vector<int>& suffMin,
               vector<int>& prefDrop) {
        int n = nums.size();

        for (int start = 0; start < n; start += k) {
            int end = start + k - 1;

            int drops = prefDrop[end] - prefDrop[start];

            if (nums[end] > nums[start])
                drops++;

            if (drops > 1)
                return false;

            if (prefMax[start] > suffMin[start])
                return false;
        }

        return true;
    }
};
