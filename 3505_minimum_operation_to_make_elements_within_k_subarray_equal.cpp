
class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void add(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
            sumLow += num;
        } else {
            high.insert(num);
            sumHigh += num;
        }

        balance();
    }

    void remove(int num) {
        auto it = low.find(num);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= num;
        } else {
            it = high.find(num);
            high.erase(it);
            sumHigh -= num;
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            int val = *low.rbegin();

            low.erase(prev(low.end()));
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            int val = *high.begin();

            high.erase(high.begin());
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> maritovexi = nums;

        vector<long long> cost(n - x + 1);

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        // Calculate cost of every window
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // DP using rolling arrays
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current position
                curr[i] = curr[i - 1];

                // Select a window ending at i-1
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
