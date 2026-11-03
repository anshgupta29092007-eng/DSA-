
class Solution {
public:
    int minMoves(vector<int>& nums) {

        int maxi = nums[0];

        // Find maximum element
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        int ans = 0;

        // Calculate total operations
        for(int i = 0; i < nums.size(); i++) {
            ans += maxi - nums[i];
        }

        return ans;
    }
};
