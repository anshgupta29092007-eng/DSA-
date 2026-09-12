class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        // Store: start, end, weight, original index
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start
        sort(a.begin(), a.end());

        // dp[i][k] = best {weight, indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Skip current interval
                auto skip = dp[i + 1][k];

                // Option 2: Take current interval
                long long end = a[i][1];
                long long weight = a[i][2];
                int index = a[i][3];

                // Find first interval with start > end
                int lo = i + 1, hi = n;

                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;

                    if (a[mid][0] > end)
                        hi = mid;
                    else
                        lo = mid + 1;
                }

                int next = lo;

                auto take = dp[next][k - 1];

                take.first += weight;
                take.second.push_back(index);

                // Sort indices for lexicographical comparison
                sort(take.second.begin(), take.second.end());

                // Choose better answer
                if (take.first > skip.first ||
                    (take.first == skip.first &&
                     take.second < skip.second)) {

                    dp[i][k] = take;

                } else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].second;
    }
};
