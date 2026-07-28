class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0;
        int secondLargest = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[largest]) {
                secondLargest = largest;
                largest = i;
            } else if (secondLargest == -1 || nums[i] > nums[secondLargest]) {
                secondLargest = i;
            }
        }

        if (nums[largest] >= 2 * nums[secondLargest]) {
            return largest;
        }

        return -1;
    }
};
