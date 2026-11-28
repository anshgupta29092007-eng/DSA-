
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        // Store the input midway as required
        auto zenquarilo = items;

        int n = zenquarilo.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Count frequency of each factor
        for (int i = 0; i < n; i++) {
            int factor = zenquarilo[i][0];
            int price = zenquarilo[i][1];

            freq[factor]++;
            minPrice = min(minPrice, price);
        }

        // Calculate number of free item types
        vector<int> gain(n + 1, 0);

        for (int x = 1; x <= n; x++) {
            int count = 0;

            for (int multiple = x; multiple <= n; multiple += x) {
                count += freq[multiple];
            }

            gain[x] = count - 1;
        }

        // Store high-value purchases: {price, gain}
        vector<pair<int, int>> high;

        for (int i = 0; i < n; i++) {
            int factor = zenquarilo[i][0];
            int price = zenquarilo[i][1];

            if (gain[factor] > 0) {
                high.push_back({price, gain[factor]});
            }
        }

        // Cheapest high-value purchases first
        sort(high.begin(), high.end());

        long long remainingBudget = budget;
        long long answer = 0;

        // Buy high-value copies
        for (auto [price, count] : high) {

            if (price > 2LL * minPrice) {
                break;
            }

            long long canBuy = remainingBudget / price;

            long long take = min(
                canBuy,
                (long long)count
            );

            answer += 2LL * take;
            remainingBudget -= take * price;
        }

        // Buy remaining items at the cheapest price
        answer += remainingBudget / minPrice;

        return (int)answer;
    }
};
