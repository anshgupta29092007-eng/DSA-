class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        // Calculate total sum
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;

        // Find pivot index
        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }

        
    
};
