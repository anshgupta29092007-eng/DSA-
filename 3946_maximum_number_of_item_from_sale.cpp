
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int cheapest = INT_MAX;
        vector<int> freeCnt(n, 0);

        // Find cheapest price and calculate free items
        for (int i = 0; i < n; i++) {
            cheapest = min(cheapest, items[i][1]);

            int factor = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeCnt[i]++;
                }
            }
        }

        // 0/1 Knapsack
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int value = freeCnt[i] + 1;

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + value);
            }
        }

        int ans = 0;

        // Buy cheapest items with remaining budget
        for (int j = 0; j <= budget; j++) {
            int remaining = budget - j;

            int total = dp[j] + remaining / cheapest;

            ans = max(ans, total);
        }

        return ans;
    }
};
