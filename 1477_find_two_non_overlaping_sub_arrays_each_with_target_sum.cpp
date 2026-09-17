class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;
        int shortest = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a subarray with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // Combine with best subarray before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, best[left - 1] + len);
                }

                // Keep shortest subarray seen so far
                shortest = min(shortest, len);
            }

            best[right] = shortest;
        }

        return ans == INF ? -1 : ans;
    }
};
