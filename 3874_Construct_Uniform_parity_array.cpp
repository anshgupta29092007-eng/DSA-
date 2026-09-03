class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find the smallest odd number
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                minOdd = min(minOdd, nums1[i]);
            }
        }

        // Check if an even number is smaller than minOdd
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0) {
                if (minOdd != INT_MAX && nums1[i] < minOdd) {
                    return false;
                }
            }
        }

        return true;
    }
};
