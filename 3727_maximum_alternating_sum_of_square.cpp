
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Square every element
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Sort in ascending order
        sort(nums.begin(), nums.end());

        // Step 3: Calculate the maximum score
        long long ans = 0;
        int mid = n / 2;

        // Subtract the smaller half
        for (int i = 0; i < mid; i++) {
            ans -= nums[i];
        }

        // Add the larger half
        for (int i = mid; i < n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};
