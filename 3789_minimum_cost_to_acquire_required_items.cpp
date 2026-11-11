
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        // Option 1: Buy everything separately
        long long a = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // Option 2: Buy only type 3 items
        long long b = 1LL * max(need1, need2) * costBoth;

        // Option 3: Buy common requirements using type 3
        int common = min(need1, need2);

        long long c = 1LL * common * costBoth
                    + 1LL * (need1 - common) * cost1
                    + 1LL * (need2 - common) * cost2;

        return min({a, b, c});
    }
};
