
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(),
            [&](pair<int, int> a, pair<int, int> b) {
                int s1 = digitSum(a.first);
                int s2 = digitSum(b.first);

                if (s1 != s2)
                    return s1 < s2;

                return a.first < b.first;
            });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
